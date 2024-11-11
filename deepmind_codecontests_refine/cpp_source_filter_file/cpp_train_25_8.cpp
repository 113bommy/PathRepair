#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    char arr[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> arr[i][j];
      }
    }
    vector<pair<int, int>> vec;
    if (arr[0][1] == arr[1][0]) {
      if (arr[0][1] == '1') {
        if (arr[n - 2][n - 1] != '0') {
          vec.push_back({n - 1, n});
        }
        if (arr[n - 1][n - 2] != '0') {
          vec.push_back({n, n - 1});
        }
      } else {
        if (arr[0][1] == '0') {
          if (arr[n - 2][n - 1] != '1') {
            vec.push_back({n - 1, n});
          }
          if (arr[n - 1][n - 2] != '1') {
            vec.push_back({n, n - 1});
          }
        }
      }
    } else if (arr[n - 1][n - 2] == arr[n - 2][n - 1]) {
      if (arr[n - 1][n - 2] == '1') {
        if (arr[0][1] != '0') {
          vec.push_back({1, 2});
        }
        if (arr[1][0] != '0') {
          vec.push_back({2, 1});
        }
      } else {
        if (arr[n - 1][n - 2] == '0') {
          if (arr[1][0] != '1') {
            vec.push_back({2, 1});
          }
          if (arr[0][1] != '1') {
            vec.push_back({1, 2});
          }
        }
      }
    } else {
      if (arr[n - 1][n - 2] != '1') {
        vec.push_back({n, n - 1});
      }
      if (arr[n - 2][n - 1] != '1') {
        vec.push_back({n - 1, n});
      }
      if (arr[0][1] != '1') {
        vec.push_back({1, 2});
      }
      if (arr[1][0] != '1') {
        vec.push_back({2, 1});
      }
    }
    cout << vec.size() << endl;
    for (auto x : vec) {
      cout << x.first << " " << x.second << endl;
    }
  }
}
