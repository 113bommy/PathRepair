#include <bits/stdc++.h>
using namespace std;
const int len = 55, inf = 1e9;
const double key = 100000000000.0;
int m, n, can[len];
double x, dp[len][len];
pair<int, int> arr[len];
vector<pair<int, int> > vec[len];
bool comp(pair<int, int> a, pair<int, int> b) { return (a > b); }
bool comp2(pair<int, int> a, pair<int, int> b) {
  return (a.first - x * a.second < b.first - x * b.second);
}
double solve(int i, int j) {
  if (i == m) return 0;
  if (j < 0) return key;
  if (dp[i][j] != key) return dp[i][j];
  double ans = key, sum = 0.0;
  if ((int)vec[i].size() <= j) ans = solve(i + 1, j - (int)vec[i].size());
  for (int k = 0; k < (int)vec[i].size(); k++) {
    sum += vec[i][k].first - x * vec[i][k].second;
    if (j - (int)vec[i].size() + k + 1 >= 0)
      ans = min(ans, sum + solve(i + 1, j - (int)vec[i].size() + 2 * (k + 1)));
  }
  return dp[i][j] = ans;
}
bool check() {
  for (int i = 0; i < m; i++)
    for (int j = 0; j <= n; j++) dp[i][j] = key;
  return (solve(0, 0) <= 0);
}
double bs() {
  double l = 0, r = 100000000.0;
  for (int i = 0; i < 100; i++) {
    x = (l + r) / 2.0;
    if (check())
      r = x;
    else
      l = x;
  }
  return l;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i].first);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i].second);
  sort(arr, arr + n, comp);
  int pos = 0;
  while (pos < n) {
    int j = pos;
    while (j < n && arr[j].first == arr[pos].first) vec[m].push_back(arr[j++]);
    m++;
    pos = j;
  }
  printf("%.0f\n", 1000.0 * bs());
  return 0;
}
