#include <bits/stdc++.h>
using namespace std;
long long read() {
  char ch = getchar();
  long long x = 0, fl = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') fl = -1;
  for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch - '0');
  return x * fl;
}
const int NN = 1000000 + 17;
void open() {
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
}
int n;
long long q, ans;
int a[NN], b[NN], siz[NN], ch[NN][2];
long long d[NN];
int kind(long long x, long long k) { return (x & (1LL << k)) > 0; }
int main() {
  n = read();
  q = read();
  for (int i = 2; i <= n; i++) {
    int p = read();
    long long w = read();
    d[i] = d[p] ^ w;
  }
  for (int i = 1; i <= n; i++) a[i] = b[i] = 1;
  for (long long k = 2; k >= 0; k--) {
    int tot = 0;
    long long ct_same = 0LL;
    for (int i = 1; i <= n; i++) siz[i] = ch[i][0] = ch[i][1] = 0;
    for (int i = 1; i <= n; i++) {
      int t = kind(d[i], k);
      if (!ch[a[i]][t]) ch[a[i]][t] = ++tot;
      a[i] = ch[a[i]][t];
      siz[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
      int t = kind(d[i], k);
      ct_same += 1LL * siz[ch[b[i]][t]];
    }
    long long typ = 0LL;
    if (ct_same < q) {
      q -= ct_same;
      typ = 1LL;
      ans += (1LL << k);
    }
    for (int i = 1; i <= n; i++) b[i] = ch[b[i]][kind(d[i], k) ^ typ];
  }
  printf("%lld\n", ans);
  return 0;
}
