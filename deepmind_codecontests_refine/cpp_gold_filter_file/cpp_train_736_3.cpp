#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > dp[20];
bool solve(int val, int idx, int a[], int b[], int t[], int d[][4], int n) {
  if (idx == n) {
    return true;
  }
  if (d[idx][val] != -1) return false;
  int size = dp[4 * a[idx] + b[idx]].size();
  for (int i = 0; i < size; i++) {
    pair<int, int> p = dp[4 * a[idx] + b[idx]][i];
    if (val == p.first) {
      t[idx + 1] = p.second;
      bool flag = solve(p.second, idx + 1, a, b, t, d, n);
      if (flag) return true;
    }
  }
  d[idx][val] = 0;
  return false;
}
int main() {
  int n;
  cin >> n;
  dp[0].push_back(make_pair(0, 0));
  dp[1].push_back(make_pair(0, 1));
  dp[1].push_back(make_pair(1, 0));
  dp[2].push_back(make_pair(0, 2));
  dp[2].push_back(make_pair(2, 0));
  dp[3].push_back(make_pair(1, 2));
  dp[3].push_back(make_pair(2, 1));
  dp[3].push_back(make_pair(0, 3));
  dp[3].push_back(make_pair(3, 0));
  dp[5].push_back(make_pair(1, 1));
  dp[7].push_back(make_pair(1, 3));
  dp[7].push_back(make_pair(3, 1));
  dp[10].push_back(make_pair(2, 2));
  dp[11].push_back(make_pair(2, 3));
  dp[11].push_back(make_pair(3, 2));
  dp[15].push_back(make_pair(3, 3));
  int a[200002], b[200005];
  int d[200004][4];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= 3; j++) {
      d[i][j] = -1;
    }
  }
  for (int i = 1; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i < n; i++) {
    cin >> a[i];
  }
  int t[n + 1];
  bool flag = false;
  for (int j = 0; j < dp[4 * a[1] + b[1]].size(); j++) {
    pair<int, int> p = dp[4 * a[1] + b[1]][j];
    t[1] = p.first;
    t[2] = p.second;
    flag = false;
    if (solve(p.second, 2, a, b, t, d, n)) {
      cout << "YES" << endl;
      for (int k = 1; k <= n; k++) {
        cout << t[k] << " ";
      }
      cout << endl;
      flag = true;
      break;
    }
  }
  if (flag == 0) cout << "NO" << endl;
  return 0;
}
