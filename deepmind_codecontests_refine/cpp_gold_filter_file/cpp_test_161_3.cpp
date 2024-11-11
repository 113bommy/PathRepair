#include <bits/stdc++.h>
using uiII = unsigned int long long;
using II = int long long;
using namespace std;
const II N = 0x3f3f3f3f3f3f3f;
int main() {
  vector<pair<II, II>> v;
  vector<pair<II, II>>::iterator it;
  v.reserve(1000000);
  II t, n, l, r, i(0);
  for (cin >> t; i < t; i++) {
    cin >> n;
    v.push_back(make_pair(1, n));
    bool x[2000][2000]{false};
    for (II i = 0; i < n; i++) {
      cin >> l >> r;
      x[l][r] = true;
    }
    bool f = false;
    for (II i = 0; i < v.size(); i++) {
      for (II j = v[i].first; j <= v[i].second; j++) {
        if (v[i].first == v[i].second) {
          cout << v[i].first << " " << v[i].second << " " << v[i].first << endl;
        }
        if (j - v[i].first == 0) {
          if (v[i].second - v[i].first >= 2) {
            if (x[j + 1][v[i].second] == true) {
              cout << v[i].first << " " << v[i].second << " " << j << endl;
              v.push_back(make_pair(j + 1, v[i].second));
            }
            continue;
          }
          if (v[i].second - v[i].first == 1) {
            if (x[v[i].second][v[i].second] == true) {
              cout << v[i].first << " " << v[i].second << " " << j << endl;
              v.push_back(make_pair(v[i].second, v[i].second));
            }
            continue;
          }
        }
        if (j - v[i].second == 0) {
          if (j - v[i].first >= 2) {
            if (x[v[i].first][v[i].second - 1] == true) {
              cout << v[i].first << " " << v[i].second << " " << j << endl;
              v.push_back(make_pair(v[i].first, v[i].second - 1));
            }
            continue;
          }
          if (j - v[i].first == 1) {
            if (x[v[i].first][v[i].first] == true) {
              cout << v[i].first << " " << v[i].second << " " << j << endl;
              v.push_back(make_pair(v[i].first, v[i].first));
            }
            continue;
          }
        }
        if (j != v[i].first && j != v[i].second) {
          if (j - v[i].first == 1) {
            if (x[v[i].first][v[i].first] == true) {
              if (x[j + 1][v[i].second] == true) {
                cout << v[i].first << " " << v[i].second << " " << j << endl;
                v.push_back(make_pair(v[i].first, v[i].first));
                v.push_back(make_pair(j + 1, v[i].second));
                break;
              }
            }
            continue;
          }
          if (v[i].second - j == 1) {
            if (x[v[i].first][j - 1] == true) {
              if (x[v[i].second][v[i].second] == true) {
                cout << v[i].first << " " << v[i].second << " " << j << endl;
                v.push_back(make_pair(v[i].second, v[i].second));
                v.push_back(make_pair(v[i].first, j - 1));
                break;
              }
            }
            continue;
          } else {
            if (x[v[i].first][j - 1] == true) {
              if (x[j + 1][v[i].second] == true) {
                cout << v[i].first << " " << v[i].second << " " << j << endl;
                v.push_back(make_pair(v[i].first, j - 1));
                v.push_back(make_pair(j + 1, v[i].second));
                break;
              }
            }
            continue;
          }
        }
      }
    }
    v.clear();
  }
}
