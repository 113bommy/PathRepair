#include <bits/stdc++.h>
using namespace std;
long long arr[123][12345];
long long ans[123][12345];
bool b[12345];
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m;
  string s;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s;
    queue<pair<int, int> > qu;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1') qu.push({i, 0});
    }
    if (qu.empty()) {
      cout << "-1" << endl;
      return 0;
    }
    memset(b, 0, sizeof b);
    while (!qu.empty()) {
      pair<int, int> p;
      p = qu.front();
      qu.pop();
      int x, depth;
      x = p.first;
      depth = p.second;
      if (b[x]) continue;
      b[x] = 1;
      ans[i][x] = depth;
      if (x == 0) {
        qu.push({1, depth + 1});
        qu.push({m - 1, depth + 1});
      } else if (x == m - 1) {
        qu.push({0, depth + 1});
        qu.push({m - 2, depth + 1});
      } else {
        qu.push({x + 1, depth + 1});
        qu.push({x - 1, depth + 1});
      }
    }
  }
  if (n == 1 && m == 1) {
    cout << "0" << endl;
    return 0;
  }
  long long z = 1e15, sum = 0;
  for (int j = 0; j < m; j++) {
    sum = 0;
    for (int i = 0; i < n; i++) {
      sum += ans[i][j];
    }
    z = min(sum, z);
  }
  cout << z << endl;
  return 0;
}
