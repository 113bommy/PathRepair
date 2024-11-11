#include <bits/stdc++.h>
using namespace std;
int x[100010], y[100010];
int n, m;
vector<int> row[100010], col[100010];
vector<int> d1[200010], d2[200010];
const int c = 100000;
bool cmpx(const int &lhs, const int &rhs) { return x[lhs] < x[rhs]; }
bool cmpy(const int &lhs, const int &rhs) { return y[lhs] < y[rhs]; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", x + i, y + i);
    row[x[i]].push_back(i);
    col[y[i]].push_back(i);
    d1[x[i] + y[i]].push_back(i);
    d2[x[i] - y[i] + c].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    sort(row[i].begin(), row[i].end(), cmpx);
    sort(col[i].begin(), col[i].end(), cmpy);
  }
  for (int i = 0; i <= 2 * n; i++) {
    sort(d1[i].begin(), d1[i].end(), cmpx);
    sort(d2[i].begin(), d2[i].end(), cmpx);
  }
  int t[9] = {};
  for (int i = 0; i < m; i++) {
    int cur = 8;
    if (row[x[i]].front() == i) --cur;
    if (row[x[i]].back() == i) --cur;
    if (col[y[i]].front() == i) --cur;
    if (col[y[i]].back() == i) --cur;
    if (d1[x[i] + y[i]].front() == i) --cur;
    if (d1[x[i] + y[i]].back() == i) --cur;
    if (d2[x[i] - y[i] + c].front() == i) --cur;
    if (d2[x[i] - y[i] + c].back() == i) --cur;
    t[cur]++;
  }
  for (int i = 0; i <= 8; i++) printf("%d ", t[i]);
  return 0;
}
