#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
template <class T>
void Read(T &x) {
  char c;
  bool f = 0;
  while (c = getchar(), c != EOF)
    if (c == '-')
      f = 1;
    else if (c >= '0' && c <= '9') {
      x = c - '0';
      while (c = getchar(), c >= '0' && c <= '9') x = x * 10 + c - '0';
      ungetc(c, stdin);
      if (f) x = -x;
      return;
    }
}
inline int lowbit(int x) { return x & (-x); }
template <class T>
inline void arrUpdate(T *c, int x, T d, int N) {
  while (x <= N) {
    c[x] += d;
    x += lowbit(x);
  }
}
template <class T>
inline T arrGetsum(T *c, int x) {
  T ret = 0;
  while (x) {
    ret += c[x];
    x -= lowbit(x);
  }
  return ret;
}
int n, m, sw;
char a[50 + 10][50 + 10], s[50 + 10];
vector<pair<int, int> > sol1, sol2;
void Transfer(vector<pair<int, int> > &ans) {
  for (int j = 0; j < m; j++)
    for (int i = 0; i < n; i += 2) {
      if (a[i][j] == 'L') {
        for (int k = 0; i + k < n && j + k < m; k++) {
          if (a[i + k + 1][j + k] == 'L') {
            for (int l = k; l >= 0; l--) {
              ans.push_back(pair<int, int>(i + l, j + l));
              a[i + l][j + l] = a[i + l][j + l + 1] = 'U';
              a[i + l + 1][j + l] = a[i + l + 1][j + l + 1] = 'D';
              if (l > 0) {
                ans.push_back(pair<int, int>(i + l, j + l - 1));
                a[i + l][j + l - 1] = a[i + l + 1][j + l - 1] = 'L';
                a[i + l][j + l] = a[i + l + 1][j + l] = 'R';
              }
            }
            break;
          }
          if (a[i + k + 1][j + k + 1] == 'U') {
            for (int l = k; l >= 0; l--) {
              ans.push_back(pair<int, int>(i + l + 1, j + l));
              a[i + l + 1][j + l] = a[i + l + 2][j + l] = 'L';
              a[i + l + 1][j + l + 1] = a[i + l + 2][j + l + 1] = 'R';
              ans.push_back(pair<int, int>(i + l, j + l));
              a[i + l][j + l] = a[i + l][j + l + 1] = 'U';
              a[i + l + 1][j + l] = a[i + l + 1][j + l + 1] = 'D';
            }
            break;
          }
        }
      }
    }
}
inline char opp(char c) {
  if (c == 'L')
    return 'U';
  else if (c == 'R')
    return 'D';
  else if (c == 'U')
    return 'L';
  else
    return 'R';
}
int main() {
  Read(n), Read(m);
  if (n & 1) {
    sw = 1;
    for (int i = 0; i < n; i++) {
      scanf("%s", s);
      for (int j = 0; j < m; j++) a[j][i] = opp(s[j]);
    }
    swap(n, m);
  } else {
    for (int i = 0; i < n; i++) scanf("%s", a[i]);
  }
  Transfer(sol1);
  if (sw) {
    for (int i = 0; i < m; i++) {
      scanf("%s", s);
      for (int j = 0; j < n; j++) a[j][i] = opp(s[j]);
    }
  } else {
    for (int i = 0; i < n; i++) scanf("%s", a[i]);
  }
  Transfer(sol2);
  reverse(sol2.begin(), sol2.end());
  for (auto p : sol2) sol1.push_back(p);
  if (sw) {
    for (auto &p : sol1) swap(p.first, p.second);
  }
  printf("%d\n", sol1.size());
  for (auto p : sol1) printf("%d %d\n", p.first + 1, p.second + 1);
  return 0;
}
