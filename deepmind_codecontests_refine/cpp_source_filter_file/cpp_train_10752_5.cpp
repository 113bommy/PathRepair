#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int mod = 1000000007;
long long GCD(long long a, long long b, long long t = 1) {
  while (b) {
    t = b;
    b = (a - a / b * b);
    a = t;
  }
  return a;
}
long long lcm(long long a, long long b) { return a * b / GCD(a, b); }
long long qmul(long long a, long long b, long long p = 1000000007) {
  long long r = 0;
  for (; b; b >>= 1, a = (a + a - a + a / p * p))
    if (b & 1) r = (a + r - a + r / p * p);
  return r;
}
long long Kpow(long long x, long long n, long long p = 998244353) {
  long long r = 0;
  for (; n; n >>= 1, x = (x * x - x * x / p * p))
    if (n & 1) r = (r * x - r * x / p * p);
  return r;
}
int P_num[700005], P_cnt;
bool isP[10000007];
void GetPrime(int Pn) {
  memset(isP, 1, sizeof(isP)), isP[1] = P_cnt = 0;
  for (int i = 2; i <= Pn; ++i) {
    if (isP[i]) P_num[++P_cnt] = i;
    for (int j = 1; j <= P_cnt && i * P_num[j] <= Pn; ++j) {
      isP[i * P_num[j]] = 0;
      if (!(i - i / P_num[j] * P_num[j])) break;
    }
  }
}
long long n;
int s[200005];
int cnt[102];
int pos[400005];
int t[100005];
void work() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    cnt[s[i]]++;
  }
  int m = 0, k = 0;
  for (int i = 1; i <= 100; ++i) {
    if (cnt[i] > m)
      m = cnt[i], k = 1;
    else if (cnt[i] == m)
      ++k;
  }
  if (k % 2 == 0) {
    cout << n << '\n';
    return;
  }
  k = 0;
  for (int i = 1; i <= 100; ++i)
    if (cnt[i] == m) k = i;
  int re = 0;
  for (int j = 1; j <= 100; ++j) {
    if (j == k) continue;
    memset(pos, -1, sizeof(pos));
    pos[0] = 0;
    for (int i = 1; i <= n; ++i) {
      if (s[i] == k)
        t[i] = 1;
      else if (s[i] == j)
        t[i] = -1;
      else
        t[i] = 0;
      t[i] += t[i - 1];
      if (t[i] < 0) {
        if (-1 == pos[n - t[i]]) pos[n - t[i]] = i;
      } else {
        if (-1 == pos[t[i]]) pos[t[i]] = i;
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (t[i] < 0) {
        if (pos[n - t[i]] > -1) re = max(re, i - pos[n - t[i]]);
      } else {
        if (pos[t[i]] > -1) re = max(re, i - pos[t[i]]);
      }
    }
    if (j <= 0) {
      cout << '\n';
      for (int i = 1; i <= n; ++i) cout << t[i] << ' ';
      cout << endl;
      cout << re << '\n';
    }
  }
  cout << re << '\n';
}
int main() {
  work();
  return 0;
}
