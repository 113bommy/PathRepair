#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int a[maxn][maxn];
vector<int> row[maxn];
vector<int> col[maxn];
int n, m;
int ans[maxn][maxn];
void solve(vector<int>& v) {
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i < n + 1; i++)
    for (int j = 1; j < m + 1; j++) cin >> a[i][j];
  for (int i = 1; i < n + 1; i++)
    for (int j = 1; j < m + 1; j++)
      row[i].push_back(a[i][j]), col[j].push_back(a[i][j]);
  for (int i = 1; i < n + 1; i++) solve(row[i]);
  for (int i = 1; i < m + 1; i++) solve(col[i]);
  for (int i = 1; i < n + 1; i++)
    for (int j = 1; j < m + 1; j++) {
      int rows =
          lower_bound(row[i].begin(), row[i].end(), a[i][j]) - row[i].begin();
      int rowb = row[i].size() - rows - 1;
      int cols =
          lower_bound(col[j].begin(), col[j].end(), a[i][j]) - col[j].begin();
      int colb = col[i].size() - cols - 1;
      ans[i][j] = max(rows, cols) + max(rowb, colb) + 1;
    }
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      cout << ans[i][j] << ' ';
    }
    cout << endl;
  }
}
