#include <bits/stdc++.h>
using namespace std;
const int B = 256;
int f[B << 1 | 1][B | 3][B | 3], cnt, n, m, ans[70005], b, a[5005], pos[5005],
    stp[2200005][2];
int insert(int x, int y) {
  if (!x || !y) return x + y;
  return stp[++cnt][0] = x, stp[cnt][1] = y, cnt;
}
struct Block {
  int anss[B | 2][B | 2], s[5005];
  void build(int k, int l, int r, vector<int> vec) {
    if (l == r) return void(f[k][1][1] = pos[l]);
    vector<int> vecl(1), vecr(1);
    int mid = l + r >> 1;
    for (int i = 1; i < vec.size(); i++)
      (vec[i] <= mid) ? (vecl.push_back(vec[i])) : (vecr.push_back(vec[i]));
    build(k << 1, l, mid, vecl), build(k << 1 | 1, mid + 1, r, vecr);
    for (int i = 1, xl = 1, xr = 1; i < vec.size();
         (vec[i] <= mid) ? (xl++) : (xr++), i++)
      for (int j = i, yl = xl - (vec[j] > mid), yr = xr - (vec[j] <= mid);
           j < vec.size(); j++, (vec[j] <= mid) ? (yl++) : (yr++))
        f[k][i][j] = insert(f[k << 1][xl][yl], f[k << 1 | 1][xr][yr]);
    return;
  }
  void build1(int l, int r) {
    vector<int> vec(1);
    for (int i = 1; i <= n; i++, s[i] = s[i - 1])
      if (a[i] >= l && a[i] <= r) vec.push_back(a[i]), ++s[i];
    build(1, l, r, vec);
    for (int i = 1; i < vec.size(); i++)
      for (int j = i; j < vec.size(); j++) anss[i][j] = f[1][i][j];
  }
  int query(int l, int r) { return anss[s[l - 1] + 1][s[r]]; }
} block[20];
int main() {
  scanf("%d%d", &n, &m), b = min(B, n), cnt = n;
  for (int i = 1; i <= n; i++) scanf("%d", a + i), pos[a[i]] = i;
  for (int i = 1; (i - 1) * b + 1 <= n; i++)
    block[i].build1((i - 1) * b + 1, min(i * b, n));
  for (int i = 1, l, r; i <= m; i++) {
    scanf("%d%d", &l, &r);
    for (int j = 1; (j - 1) * b + 1 <= n; j++)
      ans[i] = insert(ans[i], block[j].query(l, r));
  }
  printf("%d\n", cnt);
  for (int i = n + 1; i <= cnt; i++) printf("%d %d\n", stp[i][0], stp[i][1]);
  for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
  return 0;
}
