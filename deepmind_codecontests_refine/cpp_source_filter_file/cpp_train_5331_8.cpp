#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int a[maxn + 5][maxn + 5];
struct node {
  int val, id;
  node(int _v = 0, int _d = 0) {
    val = _v;
    id = _d;
  }
} b[maxn + 5];
bool cmp(node a, node b) { return a.val > b.val; }
vector<int> v[maxn + 5];
int n, m;
bool bo[maxn + 5];
int sum[maxn + 5];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; i++) bo[i] = true;
  int mx = 0, mxj = -1;
  for (int j = 1; j <= n - 1; j++) {
    for (int i = 1; i <= m; i++) b[i] = node(a[i][j] - a[i][n], i);
    sort(b + 1, b + m + 1, cmp);
    sum[0] = 0;
    for (int i = 1; i <= m; i++) sum[i] = sum[i - 1] + b[i].val;
    if (sum[1] < 0) continue;
    for (int i = 1; i <= m; i++)
      if (sum[i] >= 0)
        v[j].push_back(b[i].id);
      else
        break;
    if (v[j].size() > mx) {
      mx = v[j].size();
      mxj = j;
    }
  }
  if (mx == 0) {
    printf("%d\n", m);
    for (int i = 1; i <= m; i++) printf("%d ", i);
    printf("\n");
  } else {
    for (int i = 0; i < v[mxj].size(); i++) bo[v[mxj][i]] = false;
    printf("%d\n", m - mx);
    for (int i = 1; i <= m; i++)
      if (bo[i]) printf("%d ", i);
    printf("\n");
  }
  return 0;
}
