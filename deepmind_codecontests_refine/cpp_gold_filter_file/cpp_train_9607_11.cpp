#include <bits/stdc++.h>
using namespace std;
char arr[1000][1000];
int main() {
  int t;
  cin >> t;
  for (int o = 0; o < t; o++) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) cin >> arr[i][j];
    vector<pair<int, int> > vp1, vp2, vp3;
    for (int i = 1; i <= n; i += 2) {
      if (i == n) i--;
      for (int j = 1; j <= m; j += 2) {
        if (j == m) j--;
        if (arr[i][j] == '1' && arr[i][j + 1] == '0' && arr[i + 1][j] == '0' &&
            arr[i + 1][j + 1] == '0') {
          vp1.push_back({i, j}), vp2.push_back({i, j + 1}),
              vp3.push_back({i + 1, j + 1});
          vp1.push_back({i, j}), vp2.push_back({i, j + 1}),
              vp3.push_back({i + 1, j});
          vp1.push_back({i, j}), vp2.push_back({i + 1, j}),
              vp3.push_back({i + 1, j + 1});
        } else if (arr[i][j] == '0' && arr[i][j + 1] == '1' &&
                   arr[i + 1][j] == '0' && arr[i + 1][j + 1] == '0') {
          vp1.push_back({i, j}), vp2.push_back({i, j + 1}),
              vp3.push_back({i + 1, j});
          vp1.push_back({i, j}), vp2.push_back({i, j + 1}),
              vp3.push_back({i + 1, j + 1});
          vp1.push_back({i + 1, j}), vp2.push_back({i, j + 1}),
              vp3.push_back({i + 1, j + 1});
        } else if (arr[i][j] == '0' && arr[i + 1][j] == '0' &&
                   arr[i][j + 1] == '0' && arr[i + 1][j + 1] == '1') {
          vp1.push_back({i, j}), vp2.push_back({i, j + 1}),
              vp3.push_back({i + 1, j + 1});
          vp1.push_back({i, j}), vp2.push_back({i + 1, j}),
              vp3.push_back({i + 1, j + 1});
          vp1.push_back({i + 1, j}), vp2.push_back({i + 1, j + 1}),
              vp3.push_back({i, j + 1});
        } else if (arr[i][j] == '0' && arr[i + 1][j] == '1' &&
                   arr[i][j + 1] == '0' && arr[i + 1][j + 1] == '0') {
          vp1.push_back({i, j}), vp2.push_back({i, j + 1}),
              vp3.push_back({i + 1, j});
          vp1.push_back({i, j}), vp2.push_back({i + 1, j}),
              vp3.push_back({i + 1, j + 1});
          vp1.push_back({i + 1, j}), vp2.push_back({i + 1, j + 1}),
              vp3.push_back({i, j + 1});
        } else if (arr[i][j] == '1' && arr[i + 1][j] == '1' &&
                   arr[i][j + 1] == '0' && arr[i + 1][j + 1] == '0') {
          vp1.push_back({i, j + 1}), vp2.push_back({i, j}),
              vp3.push_back({i + 1, j + 1});
          vp1.push_back({i, j + 1}), vp2.push_back({i + 1, j}),
              vp3.push_back({i + 1, j + 1});
        } else if (arr[i][j] == '1' && arr[i][j + 1] == '0' &&
                   arr[i + 1][j] == '0' && arr[i + 1][j + 1] == '1') {
          vp1.push_back({i, j}), vp2.push_back({i, j + 1}),
              vp3.push_back({i + 1, j});
          vp1.push_back({i + 1, j + 1}), vp2.push_back({i + 1, j}),
              vp3.push_back({i, j + 1});
        } else if (arr[i][j] == '0' && arr[i][j + 1] == '1' &&
                   arr[i + 1][j] == '1' && arr[i + 1][j + 1] == '0') {
          vp1.push_back({i, j}), vp2.push_back({i, j + 1}),
              vp3.push_back({i + 1, j + 1});
          vp1.push_back({i, j}), vp2.push_back({i + 1, j}),
              vp3.push_back({i + 1, j + 1});
        } else if (arr[i][j] == '0' && arr[i][j + 1] == '1' &&
                   arr[i + 1][j] == '0' && arr[i + 1][j + 1] == '1') {
          vp1.push_back({i, j}), vp2.push_back({i, j + 1}),
              vp3.push_back({i + 1, j});
          vp1.push_back({i, j}), vp2.push_back({i + 1, j}),
              vp3.push_back({i + 1, j + 1});
        } else if (arr[i][j] == '1' && arr[i][j + 1] == '1' &&
                   arr[i + 1][j] == '1' && arr[i + 1][j + 1] == '1') {
          vp1.push_back({i + 1, j}), vp2.push_back({i + 1, j + 1}),
              vp3.push_back({i, j + 1});
          vp1.push_back({i, j}), vp2.push_back({i, j + 1}),
              vp3.push_back({i + 1, j + 1});
          vp1.push_back({i, j}), vp2.push_back({i, j + 1}),
              vp3.push_back({i + 1, j});
          vp1.push_back({i, j}), vp2.push_back({i + 1, j}),
              vp3.push_back({i + 1, j + 1});
        } else if (arr[i][j] == '0' && arr[i][j + 1] == '0' &&
                   arr[i + 1][j] == '1' && arr[i + 1][j + 1] == '1') {
          vp1.push_back({i, j}), vp2.push_back({i + 1, j + 1}),
              vp3.push_back({i, j + 1});
          vp1.push_back({i, j}), vp2.push_back({i, j + 1}),
              vp3.push_back({i + 1, j});
        } else if (arr[i][j] == '1' && arr[i][j + 1] == '1' &&
                   arr[i + 1][j] == '0' && arr[i + 1][j + 1] == '0') {
          vp1.push_back({i, j}), vp2.push_back({i + 1, j}),
              vp3.push_back({i + 1, j + 1});
          vp1.push_back({i + 1, j}), vp2.push_back({i + 1, j + 1}),
              vp3.push_back({i, j + 1});
        } else if (arr[i][j] == '1' || arr[i][j + 1] == '1') {
          vector<pair<int, int> > vp;
          for (int k = 0; k < 2; k++) {
            for (int l = 0; l < 2; l++) {
              if (arr[i + k][l + j] == '1') vp.push_back({i + k, l + j});
            }
          }
          vp1.push_back(vp[0]);
          vp2.push_back(vp[1]);
          vp3.push_back(vp[2]);
        }
        arr[i][j] = '0';
        arr[i + 1][j] = '0';
        arr[i][j + 1] = '0';
        arr[i + 1][j + 1] = '0';
      }
    }
    cout << vp1.size() << '\n';
    for (int i = 0; i < vp1.size(); i++)
      cout << vp1[i].first << " " << vp1[i].second << " " << vp2[i].first << " "
           << vp2[i].second << " " << vp3[i].first << " " << vp3[i].second
           << '\n';
  }
  return 0;
}
