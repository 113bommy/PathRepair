#include <bits/stdc++.h>
using namespace std;
const long long sz = 2e5 + 5;
const long long MD = 1e9 + 7;
pair<long long, long long> st[2 * sz];
long long arr[sz];
long long n, q;
string s;
pair<long long, long long> ADD(pair<long long, long long> &A,
                               pair<long long, long long> &B) {
  return {A.first + B.first, A.second + B.second};
}
void build() {
  for (long long i = 0; i < n; ++i) {
    arr[i] = s[i] == '1';
  }
  for (long long i = 0; i < n; ++i) {
    st[i + n] = {arr[i] == 0, arr[i] == 1};
  }
  for (long long i = n - 1; i >= 0; --i) {
    st[i] = ADD(st[i << 1], st[i << 1 | 1]);
  }
}
pair<long long, long long> query(long long L, long long R) {
  --L;
  pair<long long, long long> tot = {0, 0};
  for (L += n, R += n; L < R; L >>= 1, R >>= 1) {
    if (L & 1) tot = ADD(tot, st[L++]);
    if (R & 1) tot = ADD(tot, st[--R]);
  }
  return tot;
}
long long powMod(long long a, long long p) {
  long long res = 1;
  for (; p; p >>= 1, a = ((a) * (a)) % MD) {
    if (p & 1) res *= a, res %= MD;
  }
  return res;
}
long long MUL(long long a, long long b) {
  a %= MD;
  b %= MD;
  return (a * b);
}
int main() {
  scanf("%lld", &n), scanf("%lld", &q);
  cin >> s;
  build();
  while (q--) {
    long long L, R;
    scanf("%lld", &L), scanf("%lld", &R);
    pair<long long, long long> res = query(L, R);
    long long le = (powMod(2LL, res.second) + MD - 1) % MD;
    long long ri = (powMod(2LL, res.first) + MD - 1) % MD;
    printf("%lld\n", MUL(le, 1LL + ri));
  }
}
