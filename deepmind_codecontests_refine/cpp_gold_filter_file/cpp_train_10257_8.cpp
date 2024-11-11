#include <bits/stdc++.h>
using namespace std;
int n, m;
char cou[3010][3010];
int l[3010][3010], r[3010][3010], ld[3010][3010];
int tree[6005][3005];
vector<pair<int, int> > leftPoint[3010];
void update(int no, int idx, int val) {
  while (idx <= 3005) {
    tree[no][idx] += val;
    idx += (idx & -idx);
  }
}
int sum(int no, int idx) {
  int ret = 0;
  while (idx > 0) {
    ret += tree[no][idx];
    idx -= (idx & -idx);
  }
  return ret;
}
void preprocess() {
  memset(l, 0, sizeof(l));
  memset(r, 0, sizeof(r));
  memset(ld, 0, sizeof(ld));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (cou[i][j] == 'z') l[i][j] = l[i][j - 1] + 1;
  for (int i = 1; i <= n; i++)
    for (int j = m; j > 0; j--)
      if (cou[i][j] == 'z') r[i][j] = r[i][j + 1] + 1;
  for (int i = n; i > 0; i--)
    for (int j = 1; j <= m; j++)
      if (cou[i][j] == 'z') ld[i][j] = ld[i + 1][j - 1] + 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      leftPoint[j + r[i][j] - 1].push_back(make_pair(i, j));
}
int position(int x, int y) {
  if (x + y <= 1 + m)
    return x;
  else
    return m - y + 1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", cou[i] + 1);
  preprocess();
  long long ans = 0;
  for (int j = m; j > 0; j--) {
    for (int i = 0; i < leftPoint[j].size(); i++) {
      int x = leftPoint[j][i].first, y = leftPoint[j][i].second;
      int pos = position(x, y);
      update(x + y, pos, 1);
    }
    for (int i = 1; i <= n; i++) {
      if (cou[i][j] != 'z') continue;
      int len = min(l[i][j], ld[i][j]);
      int st = position(i, j);
      int ed = position(i + len - 1, j - len + 1);
      ans += sum(i + j, ed) - sum(i + j, st - 1);
    }
  }
  cout << ans << endl;
  return 0;
}
