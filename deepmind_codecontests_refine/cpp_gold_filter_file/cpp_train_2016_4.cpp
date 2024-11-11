#include <bits/stdc++.h>
using namespace std;
const int mx = 24;
int a[mx], wz, p;
int ans[mx], ww[mx];
bool fl;
void dfs(int d, int w, int xo, int mod) {
  if (fl) return;
  if (d == wz) {
    if (xo || mod || w == 0) return;
    cout << "Yes" << endl << w << endl;
    for (int i = 0; i < w; i++) cout << ans[i] << ' ';
    fl = 1;
    return;
  }
  dfs(d + 1, w, xo, mod);
  ans[w++] = ww[d];
  if (a[d] < 10)
    mod *= 10;
  else
    mod *= 100;
  dfs(d + 1, w, xo ^ a[d], (mod + a[d]) % p);
}
int main() {
  int n, k, i;
  scanf("%d%d", &n, &p);
  for (i = 1; i <= n; i++) {
    scanf("%d", &k);
    if (k <= mx) ww[wz] = i, a[wz++] = k;
  }
  dfs(0, 0, 0, 0);
  if (fl == 0) cout << "No";
}
