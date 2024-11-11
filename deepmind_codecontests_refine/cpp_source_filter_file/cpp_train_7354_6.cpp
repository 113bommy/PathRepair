#include <bits/stdc++.h>
using namespace std;
const int N = 3000010;
int n, m1, m2, t, a[N], b[N], mp[2][N], f[2][N];
pair<int, int> frm[2][N];
vector<int> c, tn;
vector<pair<int, int> > pt;
int main() {
  scanf("%d%d%d%d", &n, &m1, &m2, &t);
  for (int i = 1; i <= m1; i++) {
    scanf("%d", &a[i]);
    c.push_back(a[i]);
    if (a[i] > 1) c.push_back(a[i] - 1);
    if (a[i] < n) c.push_back(a[i] + 1);
  }
  for (int i = 1; i <= m2; i++) {
    scanf("%d", &b[i]);
    c.push_back(b[i]);
    if (b[i] > 1) c.push_back(b[i] - 1);
    if (b[i] < n) c.push_back(b[i] + 1);
  }
  c.push_back(n);
  c.push_back(0);
  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());
  n = lower_bound(c.begin(), c.end(), n) - c.begin();
  for (int i = 1; i <= m1; i++)
    a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin(), mp[0][a[i]] = 1;
  for (int i = 1; i <= m2; i++)
    b[i] = lower_bound(c.begin(), c.end(), b[i]) - c.begin(), mp[1][b[i]] = 1;
  for (int i = 1; i <= n; i++) {
    f[0][i] = f[1][i] = -1;
    if (f[0][i - 1] != -1)
      f[0][i] = f[0][i - 1] + c[i] - c[i - 1], frm[0][i] = {0, i - 1};
    if (f[1][i - 1] != -1)
      f[1][i] = f[1][i - 1] + c[i] - c[i - 1], frm[1][i] = {1, i - 1};
    if (mp[0][i]) f[0][i] = (f[0][i] - 1 >= t) ? f[0][i] - t : -1;
    if (mp[1][i]) f[1][i] = (f[1][i] - 1 >= t) ? f[1][i] - t : -1;
    int a = f[0][i], b = f[1][i];
    if (min(b, t) > a && !mp[0][i]) f[0][i] = min(b, t), frm[0][i] = {1, i};
    if (min(a, t) > b && !mp[1][i]) f[1][i] = min(a, t), frm[1][i] = {0, i};
  }
  if (f[0][n] == -1 && f[1][n] == -1) return puts("No"), 0;
  puts("Yes");
  int x = 0, y = n;
  if (f[0][n] == -1) x = 1;
  while (y || x) {
    if (mp[x][y]) pt.push_back({x, y - 1});
    int _x = x, _y = y;
    x = frm[_x][_y].first;
    y = frm[_x][_y].second;
    if (y == _y) tn.push_back(y);
  }
  printf("%d\n", (int)tn.size());
  for (int i = tn.size() - 1; ~i; i--) printf("%d ", c[tn[i]]);
  putchar('\n');
  printf("%d\n", pt.size());
  int lst = 1 << 29;
  for (int i = 0; i < pt.size(); i++)
    pt[i].second = lst = min(c[pt[i].second], lst - t);
  for (int i = pt.size() - 1; ~i; i--)
    printf("%d %d\n", pt[i].second, pt[i].first + 1);
  return 0;
}
