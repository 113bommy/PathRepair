#include <bits/stdc++.h>
using namespace std;
int a[55][55];
int is(int x1, int y1, int x2, int y2) {
  if (x2 - x1 == 1 && y2 - y1 == 1)
    return a[x1][y1] == a[x2][y2];
  else {
    if (x2 - x1 == 2)
      return a[x1][y1] == a[x2][y2] &&
             (a[x1 + 1][y1] == a[x2][y2 - 1] ||
              a[x1][y1 + 1] == a[x2 - 1][y2] || a[x1 + 1][y1] == a[x2 - 1][y2]);
    else
      return a[x1][y1] == a[x2][y2] &&
             (a[x1 + 1][y1] == a[x2][y2 - 1] ||
              a[x1][y1 + 1] == a[x2 - 1][y2] || a[x1][y1 + 1] == a[x2][y2 - 1]);
  }
}
int main() {
  int n;
  while (cin >> n) {
    long long ans = 0;
    memset(a, -1, sizeof a);
    a[1][1] = 1;
    a[n][n] = 0;
    int tmp1, tmp2, tmp3, tmp4, x;
    for (int i = 1; i <= n; ++i) {
      for (int j = (i % 2 == 0) + 1; j <= n; j += 2) {
        if (a[i][j] != -1) continue;
        if (j == 1) {
          tmp1 = i - 2;
          tmp2 = j;
          assert(a[i - 2][j] != -1);
        } else if (i == 1) {
          tmp1 = i;
          tmp2 = j - 2;
          assert(a[i][j - 2] != -1);
        } else {
          tmp1 = i - 1;
          tmp2 = j - 1;
          assert(a[i - 1][j - 1] != -1);
        }
        cout << "? " << tmp1 << " " << tmp2 << " " << i << " " << j << endl;
        cout.flush();
        cin >> x;
        assert(x != -1);
        if (x) {
          a[i][j] = a[tmp1][tmp2];
        } else {
          a[i][j] = !a[tmp1][tmp2];
        }
      }
    }
    for (int i = 1; i + 2 <= n; ++i) {
      for (int j = (i % 2 == 0) + 1; j + 2 <= n; j += 2) {
        if (a[i][j] != a[i + 2][j + 2]) {
          tmp1 = i;
          tmp2 = j;
          tmp3 = i + 2;
          tmp4 = j + 2;
        }
      }
    }
    vector<pair<int, int>> v, v1, v2;
    for (int i = tmp1; i <= tmp3; ++i) {
      for (int j = tmp2; j <= tmp4; ++j) {
        if (a[i][j] == -1) {
          v.push_back(make_pair(i, j));
        }
      }
    }
    v1.push_back(make_pair(0, 1));
    v2.push_back(make_pair(1, 2));
    v1.push_back(make_pair(0, 1));
    v2.push_back(make_pair(2, 1));
    v1.push_back(make_pair(0, 1));
    v2.push_back(make_pair(2, 2));
    v1.push_back(make_pair(1, 0));
    v2.push_back(make_pair(1, 2));
    v1.push_back(make_pair(1, 0));
    v2.push_back(make_pair(2, 1));
    v1.push_back(make_pair(1, 0));
    v2.push_back(make_pair(2, 2));
    vector<int> d;
    for (int i = 0; i < v1.size(); ++i) {
      cout << "? " << tmp1 + v1[i].first << " " << tmp2 + v1[i].second << " "
           << tmp1 + v2[i].first << " " << tmp2 + v2[i].second << endl;
      cout.flush();
      cin >> x;
      assert(x != -1);
      d.push_back(x);
    }
    int tmp;
    bool l = 1;
    for (int i = 0; i < (1 << 4); ++i) {
      l = 1;
      for (int j = 0; j < 4; ++j) {
        if (i & (1 << j)) {
          a[v[j].first][v[j].second] = 1;
        } else {
          a[v[j].first][v[j].second] = 0;
        }
      }
      for (int j = 0; j < 6; ++j) {
        if (d[j] != is(tmp1 + v1[j].first, tmp2 + v1[j].second,
                       tmp1 + v2[j].first, tmp2 + v2[j].second)) {
          l = 0;
        }
      }
      if (l) {
        break;
      }
    }
    if (!l)
      cout << "I can not find the answer, please tell me wrong answer" << endl;
    while (l) {
      l = 0;
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          if (a[i][j] == -1) {
            if (i + 2 <= n && a[i + 2][j] != -1) {
              cout << "? " << i << " " << j << " " << i + 2 << " " << j << endl;
              cout.flush();
              l = 1;
              cin >> x;
              assert(x != -1);
              if (x)
                a[i][j] = a[i + 2][j];
              else
                a[i][j] = !a[i + 2][j];
            } else if (j + 2 <= n && a[i][j + 2] != -1) {
              cout << "? " << i << " " << j << " " << i << " " << j + 2 << endl;
              cout.flush();
              l = 1;
              cin >> x;
              assert(x != -1);
              if (x)
                a[i][j] = a[i][j + 2];
              else
                a[i][j] = !a[i][j + 2];
            } else if (i - 2 >= 1 && a[i - 2][j] != -1) {
              cout << "? " << i - 2 << " " << j << " " << i << " " << j << endl;
              cout.flush();
              l = 1;
              cin >> x;
              assert(x != -1);
              if (x)
                a[i][j] = a[i - 2][j];
              else
                a[i][j] = !a[i - 2][j];
            } else if (j - 2 >= 1 && a[i][j - 2] != -1) {
              cout << "? " << i << " " << j - 2 << " " << i << " " << j << endl;
              cout.flush();
              l = 1;
              cin >> x;
              assert(x != -1);
              if (x)
                a[i][j] = a[i][j - 2];
              else
                a[i][j] = !a[i][j - 2];
            }
          }
        }
      }
    }
    cout << "!" << endl;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        cout << a[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
