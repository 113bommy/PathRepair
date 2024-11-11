#include <bits/stdc++.h>
using namespace std;
template <typename T, typename L>
bool smax(T &x, L y) {
  return x < y ? (x = y, true) : false;
}
template <typename T, typename L>
bool smin(T &x, L y) {
  return y < x ? (x = y, true) : false;
}
int n, m;
vector<int> vec1, vec2;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> n >> m;
  int a[n << 1][m << 1];
  memset(a, false, sizeof a);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) a[i][j] = (i - 1) * m + j;
  }
  if (n >= 4 || m >= 4) {
    cout << "YES\n";
    if (min(n, m) == 1) {
      if (n == 1) {
        int p = (m & 1 ? m : m - 1);
        for (int i = 1; i <= m; i++) {
          a[1][i] = p;
          p -= 2;
        }
        p = (m - (m & 1));
        for (int i = ((m + 1) >> 1) + 1; i <= m; i++) {
          a[1][i] = p;
          p -= 2;
        }
      } else {
        int p = (n & 1 ? n : n - 1);
        for (int i = 1; i <= n; i++) {
          a[i][1] = p;
          p -= 2;
        }
        p = (n - (n & 1));
        for (int i = ((n + 1) >> 1) + 1; i <= n; i++) {
          a[i][1] = p;
          p -= 2;
        }
      }
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cout << a[i][j] << ' ';
        cout << '\n';
      }
      return false;
    }
    if (n <= m) {
      int p = 0;
      if (m & 1) {
        if (n & 1) {
          for (int i = 1; i <= (m >> 1); i++)
            for (int j = 1; j <= n; j++) {
              a[j][i] = (p << 1) + 1;
              p++;
            }
          for (int i = 1; i <= (n + 1) / 2; i++) {
            a[i][(m + 1) / 2] = (p << 1) + 1;
            p++;
          }
          p = 1;
          for (int i = (n + 1) / 2 + 1; i <= n; i++) {
            a[i][(m + 1) / 2] = (p << 1);
            p++;
          }
          for (int i = (m + 1) / 2 + 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
              a[j][i] = (p << 1);
              p++;
            }
          }
        } else {
          for (int i = 1; i <= (m >> 1); i++)
            for (int j = 1; j <= n; j++) {
              a[j][i] = (p << 1) + 1;
              p++;
            }
          for (int i = 1; i <= n / 2; i++) {
            a[i][(m + 1) / 2] = (p << 1) + 1;
            p++;
          }
          p = 1;
          for (int i = (n >> 1) + 1; i <= n; i++) {
            a[i][(m + 1) / 2] = (p << 1);
            p++;
          }
          for (int i = (m + 1) / 2 + 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
              a[j][i] = (p << 1);
              p++;
            }
          }
        }
      } else {
        int p = 0;
        if (n & 1) {
          for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
              if (i & 1) {
                if (j & 1) vec1.push_back(a[i][j]);
              } else if (!(j & 1))
                vec1.push_back(a[i][j]);
          for (int i = 1; i <= n; i++)
            for (int j = m; j; j--)
              if (i & 1) {
                if (!(j & 1)) vec2.push_back(a[i][j]);
              } else if ((j & 1))
                vec2.push_back(a[i][j]);
          for (int i = 1; i <= (m >> 1); i++)
            for (int j = 1; j <= n; j++) a[j][i] = vec1[p++];
          p = 0;
          for (int i = (m >> 1) + 1; i <= m; i++)
            for (int j = 1; j <= n; j++) a[j][i] = vec2[p++];
        } else {
          for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
              if (i & 1) {
                if (j & 1) vec1.push_back(a[i][j]);
              } else if (!(j & 1))
                vec1.push_back(a[i][j]);
          for (int i = 1; i <= n; i++)
            for (int j = m; j; j--)
              if (i & 1) {
                if (!(j & 1)) vec2.push_back(a[i][j]);
              } else if ((j & 1))
                vec2.push_back(a[i][j]);
          for (int i = 1; i <= (m >> 1); i++)
            for (int j = 1; j <= n; j++) a[j][i] = vec1[p++];
          p = 0;
          for (int i = (m >> 1) + 1; i <= m; i++)
            for (int j = 1; j <= n; j++) a[j][i] = vec2[p++];
        }
      }
    } else {
      int p = 0;
      if (m & 1) {
        if (n & 1) {
          for (int i = 1; i <= (n >> 1); i++)
            for (int j = 1; j <= m; j++) {
              a[i][j] = (p << 1) + 1;
              p++;
            }
          for (int i = 1; i <= (m + 1) / 2; i++) {
            a[(n + 1) / 2][i] = (p << 1) + 1;
            p++;
          }
          p = 1;
          for (int i = (m >> 1) + 2; i <= m; i++) {
            a[(n + 1) / 2][i] = (p << 1);
            p++;
          }
          for (int i = (n + 1) / 2 + 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
              a[i][j] = (p << 1);
              p++;
            }
          }
        } else {
          for (int i = 1; i <= (n >> 1); i++)
            for (int j = 1; j <= m; j++) {
              a[i][j] = (p << 1) + 1;
              p++;
            }
          p = 1;
          for (int i = (n >> 1) + 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
              a[i][j] = (p << 1);
              p++;
            }
          }
        }
      } else {
        int p = 0;
        if (n & 1) {
          for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
              if (i & 1) {
                if (j & 1) vec1.push_back(a[i][j]);
              } else if (!(j & 1))
                vec1.push_back(a[i][j]);
          for (int i = 1; i <= n; i++)
            for (int j = m; j; j--)
              if (i & 1) {
                if (!(j & 1)) vec2.push_back(a[i][j]);
              } else if ((j & 1))
                vec2.push_back(a[i][j]);
          for (int i = 1; i <= (n >> 1); i++)
            for (int j = 1; j <= m; j++) a[i][j] = vec1[p++];
          for (int i = 1; i <= (m >> 1); i++) a[(n + 1) / 2][i] = vec1[p++];
          p = 0;
          for (int i = (m >> 1) + 1; i <= m; i++) a[(n + 1) / 2][i] = vec2[p++];
          for (int i = (n >> 1) + 2; i <= n; i++)
            for (int j = 1; j <= m; j++) a[i][j] = vec2[p++];
        } else {
          for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
              if (i & 1) {
                if (j & 1) vec1.push_back(a[i][j]);
              } else if (!(j & 1))
                vec1.push_back(a[i][j]);
          for (int i = 1; i <= n; i++)
            for (int j = m; j; j--)
              if (i & 1) {
                if (!(j & 1)) vec2.push_back(a[i][j]);
              } else if ((j & 1))
                vec2.push_back(a[i][j]);
          for (int i = 1; i <= (n >> 1); i++)
            for (int j = 1; j <= m; j++) a[i][j] = vec1[p++];
          p = 0;
          for (int i = (n >> 1) + 1; i <= n; i++)
            for (int j = 1; j <= m; j++) a[i][j] = vec2[p++];
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cout << a[i][j] << ' ';
      }
      cout << '\n';
    }
  } else {
    if (n == 1) {
      if (m == 1) return cout << "YES\n1\n", false;
      return cout << "NO\n", false;
    }
    if (n == 2) {
      return cout << "NO\n", false;
    }
    if (n == 3) {
      if (m == 1 || m == 2) {
        return cout << "NO\n", false;
      }
      if (m == 3) {
        return cout << "YES\n5 1 9\n3 8 4\n7 2 6\n", false;
      }
    }
  }
}
