#include <bits/stdc++.h>
const int INF = 1e+9;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string n;
  cin >> n;
  int l = n.size();
  if (l < 2) {
    cout << -1 << '\n';
    return 0;
  }
  vector<vector<int>> col(4);
  int lan;
  for (int i = l - 1; i >= 0; --i) {
    if (n[i] != '0' && i > 1) {
      lan = i;
    }
    if (n[i] == '0') {
      col[0].push_back(i);
    } else if (n[i] == '2') {
      col[1].push_back(i);
    } else if (n[i] == '5') {
      col[2].push_back(i);
    } else if (n[i] == '7') {
      col[3].push_back(i);
    }
  }
  int cnt = INF, r;
  if (col[0].size() > 1) {
    if (l - 1 - col[0][0] + l - 2 - col[0][1] < cnt) {
      cnt = l - 1 - col[0][0] + l - 2 - col[0][1];
    }
  }
  if (col[1].size() > 0 && col[2].size() > 0) {
    if (col[2][0] < col[1][0] || col[1][0] == l - 1) {
      r = l - 1 - col[1][0] + l - 1 - col[2][0];
    } else {
      r = l - 1 - col[1][0] + l - 2 - col[2][0];
    }
    if (col[0].size() > 0 && n[1] == '0' &&
        (col[2][0] == 0 || col[1][0] == 0)) {
      r += lan - 1;
    }
    if (r < cnt) {
      cnt = r;
    }
  }
  if (col[0].size() > 0 && col[2].size() > 0) {
    if (col[0][0] < col[2][0] || col[2][0] == l - 1) {
      r = l - 1 - col[0][0] + l - 1 - col[2][0];
    } else {
      r = l - 1 - col[0][0] + l - 2 - col[2][0];
    }
    if (col[0].size() > 0 && n[1] == '0' && col[2][0] == 0 && col[0][0] != 1) {
      r += lan - 1;
    }
    if (r < cnt) {
      cnt = r;
    }
  }
  if (col[2].size() > 0 && col[3].size() > 0) {
    if (col[2][0] < col[3][0] || col[3][0] == l - 1) {
      r = l - 1 - col[2][0] + l - 1 - col[3][0];
    } else {
      r = l - 1 - col[2][0] + l - 2 - col[3][0];
    }
    if (col[0].size() > 0 && n[1] == '0' &&
        (col[2][0] == 0 || col[3][0] == 0)) {
      r += lan - 1;
    }
    if (r < cnt) {
      cnt = r;
    }
  }
  if (cnt == INF) {
    cnt = -1;
  }
  cout << cnt << '\n';
  return 0;
}
