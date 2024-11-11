#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma optimize("O3")
using namespace std;
long long N = 1000000, M = 31;
int i, j, l, r, n, m, t, k, f, ma = 0, y3, mi = 2e9, x2, y2, a[1111010],
                               de[4111000], de2[4111000], d[1011000],
                               d2[1011000], x, y, z;
long long ans;
void bild(int l, int r, int ve) {
  if (l == r) {
    de[ve] = a[l];
    return;
  }
  int t = (l + r) / 2;
  bild(l, t, ve * 2);
  bild(t + 1, r, ve * 2 + 1);
  de[ve] = max(de[ve * 2], de[ve * 2 + 1]);
}
void upd(int l, int r, int x, int y, int z, int ve, int su) {
  su += de2[ve];
  if (l > y || r < x) return;
  if (l >= x && r <= y) {
    de2[ve] += z;
    return;
  }
  int t = (r + l) / 2;
  upd(l, t, x, y, z, ve * 2, su);
  upd(t + 1, r, x, y, z, ve * 2 + 1, su);
  de[ve] = max(de[ve * 2] + de2[ve * 2], de[ve * 2 + 1] + de2[ve * 2 + 1]);
}
int sum(int l, int r, int ve, int su) {
  su += de2[ve];
  if (l == r) return l;
  if (de[ve] + su <= 0) return 0;
  int t = (l + r) / 2;
  if (de[ve * 2 + 1] + su + de2[ve * 2 + 1] > 0)
    return sum(t + 1, r, ve * 2 + 1, su);
  return sum(l, t, ve * 2, su);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    cin >> x;
    a[x]++;
    d[i] = x;
  }
  for (i = 1; i <= m; i++) {
    cin >> x;
    a[x]--;
    d2[i] = x;
  }
  for (i = N; i >= 1; i--) {
    a[i] = a[i + 1] + a[i];
  }
  bild(1, N, 1);
  cin >> k;
  for (i = 1; i <= k; i++) {
    cin >> x >> y >> z;
    if (x == 1) {
      upd(1, N, 1, d[y], -1, 1, 0);
      upd(1, N, 1, z, 1, 1, 0);
      d[y] = z;
    } else {
      upd(1, N, 1, d2[y], 1, 1, 0);
      upd(1, N, 1, z, -1, 1, 0);
      d2[y] = z;
    }
    t = sum(1, N, 1, 0);
    if (t == 0) t = -1;
    cout << t << endl;
  }
}
