#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long powM(long long a, int t = mod - 2) {
  long long ret = 1;
  while (t) {
    if (t & 1) ret = ret * a % mod;
    a = a * a % mod;
    t >>= 1;
  }
  return ret;
}
int n, t[200500];
void add(int p) {
  while (p <= n) {
    t[p]++;
    p += (p & -p);
  }
}
int qry(int p) {
  int ret = 0;
  while (p) {
    ret = ret + t[p];
    p ^= (p & -p);
  }
  return ret;
}
int a[200500], m, o[200500];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) o[i] = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == -1)
      m++;
    else
      o[a[i]] = 0;
  }
  for (int i = 1; i <= n; i++) o[i] += o[i - 1];
  long long ans1 = 0;
  for (int i = n; i; i--)
    if (a[i] != -1) {
      ans1 += qry(a[i]);
      add(a[i]);
    }
  long long ans2 = 1ll * m * (m - 1) % mod * (mod + 1) / 4 % mod, sav = 0,
            ans3 = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] != -1) sav += o[n] - o[a[i]];
  for (int i = 1; i <= n; i++) {
    if (a[i] == -1)
      ans3 += sav;
    else {
      sav += 2 * o[a[i]] - o[n];
    }
  }
  printf("%lld", (ans1 + ans2 + ans3 % mod * powM(m)) % mod);
  return 0;
}
