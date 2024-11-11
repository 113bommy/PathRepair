#include <bits/stdc++.h>
using namespace std;
bool critical[101][101][101];
vector<vector<string> > CPU;
int n, m, k;
void solve(int i, int j, int t) {
  if (CPU[i][j][t] == '0') {
    return;
  }
  if (i < n - 2 && CPU[i + 1][j][t] == '1' && CPU[i + 2][j][t] == '1') {
    critical[i + 1][j][t] = true;
  }
  if (j < m - 2 && CPU[i][j + 1][t] == '1' && CPU[i][j + 2][t] == '1') {
    critical[i][j + 1][t] = true;
  }
  if (t < k - 2 && CPU[i][j][t + 1] == '1' && CPU[i][j][t + 2] == '1') {
    critical[i][j][t + 1] = true;
  }
  if (i < n - 1 && j < m - 1 && CPU[i + 1][j + 1][t] == '1' &&
      (CPU[i + 1][j][t] == '1' || CPU[i][j + 1][t] == '1')) {
    if (CPU[i + 1][j][t] == '0') {
      critical[i][j + 1][t] = true;
    }
    if (CPU[i][j + 1][t] == '0') {
      critical[i + 1][j][t] = true;
    }
  }
  if (i < n - 1 && t < k - 1 && CPU[i + 1][j][t + 1] == '1' &&
      (CPU[i + 1][j][t] == '1' || CPU[i][j][t + 1] == '1')) {
    if (CPU[i + 1][j][t] == '0') {
      critical[i][j][t + 1] = true;
    }
    if (CPU[i][j][t + 1] == '0') {
      critical[i + 1][j][t] = true;
    }
  }
  if (t < k - 1 && j < m - 1 && CPU[i][j + 1][t + 1] == '1' &&
      (CPU[i][j][t + 1] == '1' || CPU[i][j + 1][t] == '1')) {
    if (CPU[i][j][t + 1] == '0') {
      critical[i][j + 1][t] = true;
    }
    if (CPU[i][j + 1][t] == '0') {
      critical[i][j][t + 1] = true;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    vector<string> r;
    CPU.push_back(r);
    for (int j = 0; j < m; j++) {
      string in;
      cin >> in;
      CPU.back().push_back(in);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int t = 0; t < k; t++) {
        solve(i, j, t);
      }
    }
  }
  long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int t = 0; t < k; t++) {
        if (critical[i][j][t]) {
          ans++;
        }
      }
    }
  }
  cout << ans;
  return 0;
}
