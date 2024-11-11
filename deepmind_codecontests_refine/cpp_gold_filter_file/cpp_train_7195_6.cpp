#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, kk, q, ans, cnt, nc, a[N], b[N], c[N], pre[N], bl[N], lt[N], tag[N];
char s[N];
int num[1007][17000];
void upd1(int p, int v) {
  for (int i = p; i <= n; i += kk) {
    pre[i] ^= v;
    if (v && !pre[i]) --ans;
    if (v && pre[i] == v) ++ans;
  }
  int lst = p % kk + ((n - p % kk) / kk) * kk;
  if (v && !pre[lst]) --cnt;
  if (v && pre[lst] == v) ++cnt;
}
void upd2(int p, int v) {
  for (int i = p; bl[i] == bl[p]; i += kk) {
    if (v && !(pre[i] ^ tag[bl[p]])) ++ans;
    num[bl[p]][pre[i]]--;
    pre[i] ^= v;
    num[bl[p]][pre[i]]++;
    if (v && !(pre[i] ^ tag[bl[p]])) --ans;
  }
  for (int i = bl[p] + 1; i <= nc && lt[i] % kk == p % kk; i++) {
    if (v) ans += num[i][tag[i]];
    tag[i] ^= v;
    if (v) ans -= num[i][tag[i]];
  }
  int lst = p % kk + ((n - p % kk) / kk) * kk;
  if (v && !(pre[lst] ^ tag[bl[lst]])) --cnt;
  if (v && (pre[lst] ^ tag[bl[lst]]) == v) ++cnt;
}
const int B = 400;
void modify(int p, int v) {
  if (n / kk < B)
    upd1(p, v ^ c[p]);
  else
    upd2(p, v ^ c[p]);
  c[p] = v;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> kk >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  ++n;
  if (n / kk >= B)
    for (int i = 1; i <= kk; i++)
      for (int j = i; j <= n; j += kk) {
        if (((j - 1) / kk + 1) % B == 1) {
          lt[++nc] = j;
          num[nc][0] = min(B, (n - j) / kk + 1);
        }
        bl[j] = nc;
      }
  for (int i = 1; i <= n; i++) modify(i, (a[i] ^ a[i - 1]) ^ (b[i] ^ b[i - 1]));
  cout << (cnt ? -1 : ans) << endl;
  while (q--) {
    int p, v;
    cin >> s >> p >> v;
    if (s[0] == 'a')
      a[p] = v;
    else
      b[p] = v;
    modify(p, (a[p] ^ a[p - 1]) ^ (b[p] ^ b[p - 1]));
    if (p != n) modify(p + 1, (a[p + 1] ^ a[p]) ^ (b[p + 1] ^ b[p]));
    cout << (cnt ? -1 : ans) << endl;
  }
  return 0;
}
