#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[400005], best[400005];
vector<int> a[400005], tmp[400005];
int t[30][5], top = 0, ans = 4000000;
int fn(char c) {
  if (c == 'A')
    return 1;
  else if (c == 'C')
    return 2;
  else if (c == 'G')
    return 3;
  else if (c == 'T')
    return 4;
}
char fc(int c) {
  if (c == 1)
    return 'A';
  else if (c == 2)
    return 'C';
  else if (c == 3)
    return 'G';
  else if (c == 4)
    return 'T';
}
void print() { cout << "That's OK!" << endl; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    for (int j = 0; j < m; j++) a[i].push_back(fn(s[i][j]));
  }
  for (int c1 = 1; c1 <= 4; c1++)
    for (int c2 = 1; c2 <= 4; c2++)
      for (int c3 = 1; c3 <= 4; c3++) {
        int c4 = 10 - c1 - c2 - c3;
        if (c1 == c2 || c2 == c3 || c1 == c3) continue;
        t[++top][1] = c1;
        t[top][2] = c2;
        t[top][3] = c3;
        t[top][4] = c4;
      }
  for (int tt = 1; tt <= 24; tt++) {
    int c1 = t[tt][1], c2 = t[tt][2], c3 = t[tt][3], c4 = t[tt][4];
    for (int b = 0; b <= 1; b++) {
      int now = 0;
      if (!b) {
        for (int i = 0; i < n; i++) tmp[i].clear();
        for (int i = 0; i < n; i++) {
          if (i % 2 == 0) {
            if (i == 0) {
              for (int j = 0; j < m; j++) {
                if (j % 2 == 0) {
                  if (c1 != a[i][j]) now++;
                  tmp[i].push_back(c1);
                }
                if (j % 2 == 1) {
                  if (c2 != a[i][j]) now++;
                  tmp[i].push_back(c2);
                }
              }
            } else {
              int tmp1 = 0, tmp2 = 0;
              for (int j = 0; j < m; j++) {
                if (j % 2 == 0) {
                  if (c1 != a[i][j]) tmp1++;
                  if (c2 != a[i][j]) tmp2++;
                } else {
                  if (c1 != a[i][j]) tmp2++;
                  if (c2 != a[i][j]) tmp1++;
                }
              }
              if (tmp1 <= tmp2) {
                now += tmp1;
                for (int j = 0; j < m; j++)
                  if (j % 2 == 0)
                    tmp[i].push_back(c1);
                  else
                    tmp[i].push_back(c2);
              } else {
                now += tmp2;
                for (int j = 0; j < m; j++)
                  if (j % 2 == 0)
                    tmp[i].push_back(c2);
                  else
                    tmp[i].push_back(c1);
              }
            }
          } else {
            if (i == 1) {
              for (int j = 0; j < m; j++) {
                if (j % 2 == 0) {
                  if (c3 != a[i][j]) now++;
                  tmp[i].push_back(c3);
                }
                if (j % 2 == 1) {
                  if (c4 != a[i][j]) now++;
                  tmp[i].push_back(c4);
                }
              }
            } else {
              int tmp1 = 0, tmp2 = 0;
              for (int j = 0; j < m; j++) {
                if (j % 2 == 0) {
                  if (c3 != a[i][j]) tmp1++;
                  if (c4 != a[i][j]) tmp2++;
                } else {
                  if (c3 != a[i][j]) tmp2++;
                  if (c4 != a[i][j]) tmp1++;
                }
              }
              if (tmp1 <= tmp2) {
                now += tmp1;
                for (int j = 0; j < m; j++)
                  if (j % 2 == 0)
                    tmp[i].push_back(c3);
                  else
                    tmp[i].push_back(c4);
              } else {
                now += tmp2;
                for (int j = 0; j < m; j++)
                  if (j % 2 == 0)
                    tmp[i].push_back(c4);
                  else
                    tmp[i].push_back(c3);
              }
            }
          }
        }
        if (now < ans) {
          ans = now;
          for (int i = 0; i < n; i++) best[i].clear();
          for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) best[i].push_back(fc(tmp[i][j]));
        }
      } else {
        for (int j = 0; j < m; j++) tmp[j].clear();
        for (int j = 0; j < m; j++) {
          if (j % 2 == 0) {
            if (j == 0) {
              for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                  if (c1 != a[i][j]) now++;
                  tmp[j].push_back(c1);
                }
                if (i % 2 == 1) {
                  if (c3 != a[i][j]) now++;
                  tmp[j].push_back(c3);
                }
              }
            } else {
              int tmp1 = 0, tmp2 = 0;
              for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                  if (c1 != a[i][j]) tmp1++;
                  if (c3 != a[i][j]) tmp2++;
                } else {
                  if (c1 != a[i][j]) tmp2++;
                  if (c3 != a[i][j]) tmp1++;
                }
              }
              if (tmp1 <= tmp2) {
                now += tmp1;
                for (int i = 0; i < n; i++)
                  if (i % 2 == 0)
                    tmp[j].push_back(c1);
                  else
                    tmp[j].push_back(c3);
              } else {
                now += tmp2;
                for (int i = 0; i < n; i++)
                  if (i % 2 == 0)
                    tmp[j].push_back(c3);
                  else
                    tmp[j].push_back(c1);
              }
            }
          } else {
            if (j == 1) {
              for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                  if (c2 != a[i][j]) now++;
                  tmp[j].push_back(c2);
                }
                if (i % 2 == 1) {
                  if (c4 != a[i][j]) now++;
                  tmp[j].push_back(c4);
                }
              }
            } else {
              int tmp1 = 0, tmp2 = 0;
              for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                  if (c2 != a[i][j]) tmp1++;
                  if (c4 != a[i][j]) tmp2++;
                } else {
                  if (c2 != a[i][j]) tmp2++;
                  if (c4 != a[i][j]) tmp1++;
                }
              }
              if (tmp1 <= tmp2) {
                now += tmp1;
                for (int i = 0; i < n; i++)
                  if (i % 2 == 0)
                    tmp[j].push_back(c2);
                  else
                    tmp[j].push_back(c4);
              } else {
                now += tmp2;
                for (int i = 0; i < n; i++)
                  if (i % 2 == 0)
                    tmp[j].push_back(c4);
                  else
                    tmp[j].push_back(c2);
              }
            }
          }
        }
        if (now < ans) {
          ans = now;
          for (int i = 0; i < n; i++) best[i].clear();
          for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) best[i].push_back(fc(tmp[j][i]));
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) printf("%c", best[i][j]);
    puts("");
  }
  return 0;
}
