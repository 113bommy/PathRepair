#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int n, m, t;
string s[maxn], ans[maxn];
int tonum(char ch) {
  if (ch == 'A') return 1;
  if (ch == 'G') return 2;
  if (ch == 'C') return 3;
  if (ch == 'T') return 4;
}
char tochar(int x) {
  if (x == 1) return 'A';
  if (x == 2) return 'G';
  if (x == 3) return 'C';
  if (x == 4) return 'T';
}
vector<int> a[maxn], temp[maxn];
int md[30][10];
int mmin = maxn;
int main() {
  std::ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < m; j++) {
      a[i].push_back(tonum(s[i][j]));
    }
  }
  int index = 0;
  for (int c1 = 1; c1 <= 4; c1++) {
    for (int c2 = 1; c2 <= 4; c2++) {
      for (int c3 = 1; c3 <= 4; c3++) {
        if (c1 == c2 || c1 == c3 || c2 == c3) continue;
        int c4 = 10 - c1 - c2 - c3;
        md[++index][1] = c1;
        md[index][2] = c2;
        md[index][3] = c3;
        md[index][4] = c4;
      }
    }
  }
  for (int k = 1; k <= index; k++) {
    int c1 = md[k][1], c2 = md[k][2], c3 = md[k][3], c4 = md[k][4];
    for (int dire = 0; dire <= 1; dire++) {
      int change = 0;
      if (dire == 0) {
        for (int i = 0; i < n; i++) temp[i].clear();
        for (int i = 0; i < n; i++) {
          if (i % 2 == 0) {
            if (i == 0) {
              for (int j = 0; j < m; j++) {
                if (j % 2 == 0) {
                  if (c1 != a[i][j]) change++;
                  temp[i].push_back(c1);
                } else {
                  if (c2 != a[i][j]) change++;
                  temp[i].push_back(c2);
                }
              }
            } else {
              int change1 = 0, change2 = 0;
              for (int j = 0; j < m; j++) {
                if (j % 2 == 0) {
                  if (c1 != a[i][j]) change1++;
                  if (c2 != a[i][j]) change2++;
                } else {
                  if (c1 != a[i][j]) change2++;
                  if (c2 != a[i][j]) change1++;
                }
              }
              if (change1 <= change2) {
                change += change1;
                for (int j = 0; j < m; j++) {
                  if (j % 2 == 0)
                    temp[i].push_back(c1);
                  else
                    temp[i].push_back(c2);
                }
              } else {
                change += change2;
                for (int j = 0; j < m; j++) {
                  if (j % 2 == 0)
                    temp[i].push_back(c2);
                  else
                    temp[i].push_back(c1);
                }
              }
            }
          } else {
            if (i == 1) {
              for (int j = 0; j < m; j++) {
                if (j % 2 == 0) {
                  if (c3 != a[i][j]) change++;
                  temp[i].push_back(c3);
                } else {
                  if (c4 != a[i][j]) change++;
                  temp[i].push_back(c4);
                }
              }
            } else {
              int change1 = 0, change2 = 0;
              for (int j = 0; j < m; j++) {
                if (j % 2 == 0) {
                  if (c3 != a[i][j]) change1++;
                  if (c4 != a[i][j]) change2++;
                } else {
                  if (c3 != a[i][j]) change2++;
                  if (c4 != a[i][j]) change1++;
                }
              }
              if (change1 <= change2) {
                change += change1;
                for (int j = 0; j < m; j++) {
                  if (j % 2 == 0)
                    temp[i].push_back(c3);
                  else
                    temp[i].push_back(c4);
                }
              } else {
                change += change2;
                for (int j = 0; j < m; j++) {
                  if (j % 2 == 0)
                    temp[i].push_back(c4);
                  else
                    temp[i].push_back(c3);
                }
              }
            }
          }
        }
        if (change < mmin) {
          mmin = change;
          for (int i = 0; i < n; i++) ans[i].clear();
          for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
              ans[i].push_back(tochar(temp[i][j]));
            }
          }
        }
      } else {
        for (int j = 0; j < m; j++) temp[j].clear();
        for (int j = 0; j < m; j++) {
          if (j % 2 == 0) {
            if (j == 0) {
              for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                  if (c1 != a[i][j]) change++;
                  temp[j].push_back(c1);
                } else {
                  if (c2 != a[i][j]) change++;
                  temp[j].push_back(c3);
                }
              }
            } else {
              int change1 = 0, change2 = 0;
              for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                  if (c1 != a[i][j]) change1++;
                  if (c2 != a[i][j]) change2++;
                } else {
                  if (c1 != a[i][j]) change2++;
                  if (c2 != a[i][j]) change1++;
                }
              }
              if (change1 <= change2) {
                change += change1;
                for (int i = 0; i < n; i++) {
                  if (i % 2 == 0)
                    temp[j].push_back(c1);
                  else
                    temp[j].push_back(c3);
                }
              } else {
                change += change2;
                for (int i = 0; i < n; i++) {
                  if (i % 2 == 0)
                    temp[j].push_back(c3);
                  else
                    temp[j].push_back(c1);
                }
              }
            }
          } else {
            if (j == 1) {
              for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                  if (c2 != a[i][j]) change++;
                  temp[j].push_back(c2);
                } else {
                  if (c4 != a[i][j]) change++;
                  temp[j].push_back(c4);
                }
              }
            } else {
              int change1 = 0, change2 = 0;
              for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                  if (c2 != a[i][j]) change1++;
                  if (c4 != a[i][j]) change2++;
                } else {
                  if (c2 != a[i][j]) change2++;
                  if (c4 != a[i][j]) change1++;
                }
              }
              if (change1 <= change2) {
                change += change1;
                for (int i = 0; i < n; i++) {
                  if (i % 2 == 0)
                    temp[j].push_back(c2);
                  else
                    temp[j].push_back(c4);
                }
              } else {
                change += change2;
                for (int i = 0; i < n; i++) {
                  if (i % 2 == 0)
                    temp[j].push_back(c4);
                  else
                    temp[j].push_back(c2);
                }
              }
            }
          }
        }
        if (change < mmin) {
          mmin = change;
          for (int i = 0; i < n; i++) ans[i].clear();
          for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
              ans[i].push_back(tochar(temp[j][i]));
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << ans[i][j];
    }
    cout << '\n';
  }
  return 0;
}
