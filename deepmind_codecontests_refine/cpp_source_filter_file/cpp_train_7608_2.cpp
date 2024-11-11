#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigMod(T p, T e, T M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T modInverse(T a, T M) {
  return bigMod(a, M - 2, M);
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  a = abs(a);
  b = abs(b);
  return (a / gcd(a, b)) * b;
}
template <class T>
inline string int2String(T a) {
  ostringstream str;
  str << a;
  return str.str();
}
const int dr[] = {0, 1, 0, -1, -1, 1, 1, -1, -2, -2, 2, 2, -1, -1, 1, 1};
const int dc[] = {1, 0, -1, 0, 1, 1, -1, -1, -1, 1, -1, 1, -2, 2, -2, 2};
long long n, m, q;
int w[15], Q[111][5000];
bitset<5000> rep;
std::map<int, int> mp;
char ch[100];
int Int() {
  int x = 0, v = 1;
  for (int i = int(0); i < int(n); i++) {
    if (ch[i] == '1') x += v;
    v <<= 1;
  }
  return x;
}
int main() {
  scanf("%lld%lld%lld", &n, &m, &q);
  for (int i = int(0); i < int(n); i++) scanf("%d", &w[i]);
  for (int i = int(0); i < int(m); i++) {
    scanf("%s", ch);
    mp[Int()]++;
  }
  int k, x, curr, sum;
  while (q--) {
    scanf("%s%d", ch, &k);
    x = Int();
    if (!rep[x]) {
      for (auto &p : mp) {
        sum = 0;
        for (int i = int(0); i < int(n); i++)
          sum += ((bool)(p.first & (1 << (i)))) == ((bool)(x & (1 << (i))))
                     ? w[i]
                     : 0;
        if (sum > 100) continue;
        Q[sum][x] = p.second;
      }
      for (int i = int(1); i < int(111); i++) Q[i][x] += Q[i - 1][x];
      rep[x] = 1;
    }
    printf("%d\n", Q[k][x]);
  }
  return 0;
}
