#include <bits/stdc++.h>
using namespace std;
inline int Get() {
  int res = 0, q = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') q = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
  return res * q;
}
const double eps = 1e-12, pi = M_PI;
const int oo = (int)2e9, mod = (int)1e9 + 7;
const long long INF = (long long)1e17;
int Pow(int x, int y) {
  long long t = x, r = 1;
  for (; y; y >>= 1, t = t * t) {
    if (y & 1) r = r * t % mod;
  }
  return r;
}
char s[100010];
int cnt[1010];
int n;
int main() {
  scanf(
      "%d"
      "%s\n",
      &n, s + 1);
  for (int i = (1), end = (n); i <= end; ++i) ++cnt[(int)s[i]];
  int tot = 0, mx = 0;
  for (int i = (1), end = (150); i <= end; ++i)
    if (cnt[i] > mx)
      mx = cnt[i], tot = 1;
    else if (cnt[i] == mx)
      ++tot;
  printf(
      "%d"
      "\n",
      Pow(tot, n));
  return 0;
}
