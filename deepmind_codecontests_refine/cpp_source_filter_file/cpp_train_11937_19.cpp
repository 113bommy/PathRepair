#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<size_t> ve[100103];
void pre() {
  int arr[100103];
  fill(arr, arr + 100103, 1);
  for (ll i = 2; i < 100103; i++) {
    if (arr[i]) {
      for (ll j = i; j < 100103; j += i) {
        arr[j] = 0;
        ve[j].push_back(i);
      }
    }
  }
}
int main() {
  int n;
  cin >> n;
  string str;
  int tt, x = 0, y = 0;
  vector<pair<int, int>> v;
  int s = 0;
  int bl[n][n];
  int wh[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i % 2) {
        if (j % 2) {
          bl[i][j] = 1;
          wh[i][j] = 0;
        } else {
          bl[i][j] = 0;
          wh[i][j] = 1;
        }
      } else {
        if (j % 2) {
          bl[i][j] = 0;
          wh[i][j] = 1;
        } else {
          bl[i][j] = 1;
          wh[i][j] = 0;
        }
      }
    }
  }
  for (int i = 0; i < 4; i++) {
    x = 0;
    y = 0;
    for (int r = 0; r < n; r++) {
      cin >> str;
      for (int t = 0; t < n; t++) {
        tt = 0 * (str[t] == '0') + 1 * (str[t] == '1');
        if (tt != bl[r][t]) {
          x++;
        }
        if (tt != wh[r][t]) {
          y++;
        }
      }
    }
    v.push_back(make_pair(x, y));
  }
  int m = 100000000;
  for (int i = 0; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      s = 0;
      for (int x = 0; x < 4; x++) {
        if (x != i && x != j) {
          s += v[x].first;
        }
      }
      s += v[i].second;
      s += v[j].second;
      if (s < m) {
        m = s;
      }
    }
  }
  cout << m << endl;
}
