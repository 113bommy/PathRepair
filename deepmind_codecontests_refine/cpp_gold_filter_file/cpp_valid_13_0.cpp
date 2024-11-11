#include <bits/stdc++.h>
using namespace std;
class desc {
 public:
  bool operator()(const int &a, const int &b) { return a > b; }
};
bool pairone(pair<long long int, long long int> &a,
             pair<long long int, long long int> &b) {
  return (a.first > b.first);
}
void show(vector<int> vec) {
  for (auto x : vec) cout << x << " ";
  cout << endl;
  ;
}
void showl(vector<long long int> vec) {
  for (auto x : vec) cout << x << " ";
  cout << endl;
  ;
}
int operate(vector<int> &);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    bool domino = 0;
    vector<string> grid(n, string(m, 'z'));
    int alph = 0;
    if (n == 1) {
      if (k == m / 2) {
        domino = 1;
        for (int i = 0; i < m; i += 2) {
          grid[0][i] = 'a' + alph;
          grid[0][i + 1] = 'a' + alph;
          alph = (alph + 1) % 26;
        }
      }
    } else if (m == 1) {
      if (k == 0) {
        domino = 1;
        for (int i = 0; i < n; i += 2) {
          grid[i][0] = 'a' + alph;
          grid[i + 1][0] = 'a' + alph;
          alph = (alph + 1) % 26;
        }
      }
    } else {
      if (n % 2 == 0 && m % 2 == 0)
        if (k % 2 == 0) {
          domino = 1;
          int cnt = 0;
          int i = 0, j = 0;
          char first, second;
          while (cnt < k) {
            if (j % 4 == 0) {
              first = 'a';
              second = 'b';
            } else {
              first = 'b';
              second = 'a';
            }
            grid[i][j] = first;
            grid[i][j + 1] = first;
            alph = (alph + 1) % 26;
            grid[i + 1][j] = second;
            grid[i + 1][j + 1] = second;
            alph = (alph + 1) % 26;
            cnt += 2;
            j += 2;
            if (j == m) {
              i += 2;
              j = 0;
            }
          }
          while (i < n) {
            if (i % 4 == 0) {
              first = 'x';
              second = 'y';
            } else {
              first = 'y';
              second = 'x';
            }
            grid[i][j] = first;
            grid[i + 1][j] = first;
            alph = (alph + 1) % 26;
            grid[i][j + 1] = second;
            grid[i + 1][j + 1] = second;
            alph = (alph + 1) % 26;
            j += 2;
            if (j == m) {
              i += 2;
              j = 0;
            }
          }
        }
      if (n % 2 == 1 && m % 2 == 0)
        if ((m / 2) % 2 == 0) {
          if (k % 2 == 0 && k >= m / 2) {
            domino = 1;
            int cnt = 0;
            int i = 0, j = 0;
            char first, second;
            while (cnt < k - (m / 2)) {
              if (j % 4 == 0) {
                first = 'a';
                second = 'b';
              } else {
                first = 'b';
                second = 'a';
              }
              grid[i][j] = first;
              grid[i][j + 1] = first;
              alph = (alph + 1) % 26;
              grid[i + 1][j] = second;
              grid[i + 1][j + 1] = second;
              alph = (alph + 1) % 26;
              cnt += 2;
              j += 2;
              if (j == m) {
                i += 2;
                j = 0;
              }
            }
            while (i < n - 1) {
              if (i % 4 == 0) {
                first = 'x';
                second = 'y';
              } else {
                first = 'y';
                second = 'x';
              }
              grid[i][j] = first;
              grid[i + 1][j] = first;
              alph = (alph + 1) % 26;
              grid[i][j + 1] = second;
              grid[i + 1][j + 1] = second;
              alph = (alph + 1) % 26;
              j += 2;
              if (j == m) {
                i += 2;
                j = 0;
              }
            }
            for (j = 0; j < m; j += 2) {
              grid[n - 1][j] = (j % 4 == 0 ? 'p' : 'q');
              grid[n - 1][j + 1] = (j % 4 == 0 ? 'p' : 'q');
            }
          }
        } else if ((m / 2) % 2 == 1)
          if (k % 2 == 1 && k >= m / 2) {
            domino = 1;
            int cnt = 0;
            int i = 0, j = 0;
            char first, second;
            while (cnt < (k - m / 2)) {
              if (j % 4 == 0) {
                first = 'a';
                second = 'b';
              } else {
                first = 'b';
                second = 'a';
              }
              grid[i][j] = first;
              grid[i][j + 1] = first;
              alph = (alph + 1) % 26;
              grid[i + 1][j] = second;
              grid[i + 1][j + 1] = second;
              alph = (alph + 1) % 26;
              cnt += 2;
              j += 2;
              if (j == m) {
                i += 2;
                j = 0;
              }
            }
            while (i < n - 1) {
              if (i % 4 == 0) {
                first = 'x';
                second = 'y';
              } else {
                first = 'y';
                second = 'x';
              }
              grid[i][j] = first;
              grid[i + 1][j] = first;
              alph = (alph + 1) % 26;
              grid[i][j + 1] = second;
              grid[i + 1][j + 1] = second;
              alph = (alph + 1) % 26;
              j += 2;
              if (j == m) {
                i += 2;
                j = 0;
              }
            }
            for (j = 0; j < m; j += 2) {
              grid[n - 1][j] = (j % 4 == 0 ? 'p' : 'q');
              grid[n - 1][j + 1] = (j % 4 == 0 ? 'p' : 'q');
            }
          }
      if (n % 2 == 0 && m % 2 == 1)
        if (k % 2 == 0 && ((n * m) / 2 - k) >= n / 2) {
          domino = 1;
          int cnt = 0;
          int i = 0, j = 0;
          char first, second;
          while (cnt < k) {
            if (j % 4 == 0) {
              first = 'a';
              second = 'b';
            } else {
              first = 'b';
              second = 'a';
            }
            grid[i][j] = first;
            grid[i][j + 1] = first;
            alph = (alph + 1) % 26;
            grid[i + 1][j] = second;
            grid[i + 1][j + 1] = second;
            alph = (alph + 1) % 26;
            cnt += 2;
            i += 2;
            if (i == n) {
              j += 2;
              i = 0;
            }
          }
          while (j < m - 1) {
            if (i % 4 == 0) {
              first = 'x';
              second = 'y';
            } else {
              first = 'y';
              second = 'x';
            }
            grid[i][j] = first;
            grid[i + 1][j] = first;
            alph = (alph + 1) % 26;
            grid[i][j + 1] = second;
            grid[i + 1][j + 1] = second;
            alph = (alph + 1) % 26;
            i += 2;
            if (i == n) {
              j += 2;
              i = 0;
            }
          }
          for (i = 0; i < n; i += 2) {
            grid[i][m - 1] = (i % 4 == 0 ? 'p' : 'q');
            grid[i + 1][m - 1] = (i % 4 == 0 ? 'p' : 'q');
            alph = (alph + 1) % 26;
          }
        }
    }
    cout << (domino ? "YES" : "NO") << endl;
    if (domino) {
      for (auto x : grid) cout << x << endl;
    }
  }
  return 0;
}
