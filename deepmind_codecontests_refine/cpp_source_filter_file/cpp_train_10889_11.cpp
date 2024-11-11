#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > arr(105, vector<int>(105));
vector<pair<string, int> > v;
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  int cnt = 0;
  if (n < m) {
    for (int i = 0; i < n; i++) {
      int x = 520;
      for (int j = 0; j < m; j++) {
        x = min(x, arr[i][j]);
      }
      if (x != 0) {
        for (int j = 0; j < m; j++) {
          arr[i][j] -= x;
        }
        for (int k = 0; k < x; k++) {
          v.push_back({"row ", i + 1});
        }
      }
    }
    for (int i = 0; i < m; i++) {
      int x = 520;
      for (int j = 0; j < n; j++) {
        x = min(x, arr[j][i]);
      }
      if (x != 0) {
        for (int j = 0; j < n; j++) arr[j][i] -= x;
        for (int k = 0; k < x; k++) {
          v.push_back({"col ", i + 1});
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < m; k++) {
        if (arr[i][k] != 0) cnt++;
      }
    }
    if (cnt > 1) cout << "-1" << '\n';
  } else {
    for (int i = 0; i < m; i++) {
      int x = 520;
      for (int j = 0; j < n; j++) {
        x = min(x, arr[j][i]);
      }
      if (x != 0) {
        for (int j = 0; j < n; j++) arr[j][i] -= x;
        for (int k = 0; k < x; k++) {
          v.push_back({"col ", i + 1});
        }
      }
    }
    for (int i = 0; i < n; i++) {
      int x = 520;
      for (int j = 0; j < m; j++) {
        x = min(x, arr[i][j]);
      }
      if (x != 0) {
        for (int j = 0; j < m; j++) {
          arr[i][j] -= x;
        }
        for (int k = 0; k < x; k++) {
          v.push_back({"row ", i + 1});
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < m; k++) {
        if (arr[i][k] != 0) cnt++;
      }
    }
    if (cnt >= 1) cout << "-1" << '\n';
  }
  if (cnt == 0) {
    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++)
      cout << v[i].first << v[i].second << '\n';
  }
}
