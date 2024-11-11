#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 0;
  char c = getchar();
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  return f ? -x : x;
}
int n, m, a[110][110];
char s[110];
struct node {
  int a, b, c, d, e, f;
  node() {}
  node(int _a, int _b, int _c, int _d, int _e, int _f) {
    a = _a;
    b = _b;
    c = _c;
    d = _d;
    e = _e;
    f = _f;
  }
};
vector<node> ans;
inline void do1(int i, int j) {
  if (i < n && j < m) {
    ans.push_back(node(i, j, i + 1, j, i, j + 1));
    ans.push_back(node(i, j, i, j + 1, i + 1, j + 1));
    ans.push_back(node(i, j, i + 1, j, i + 1, j + 1));
  } else if (i > 1 && j > 1) {
    ans.push_back(node(i, j, i - 1, j, i, j - 1));
    ans.push_back(node(i, j, i, j - 1, i - 1, j - 1));
    ans.push_back(node(i, j, i - 1, j, i - 1, j - 1));
  } else if (i > 1 && j < m) {
    ans.push_back(node(i, j, i - 1, j, i, j + 1));
    ans.push_back(node(i, j, i, j + 1, i - 1, j + 1));
    ans.push_back(node(i, j, i - 1, j, i - 1, j + 1));
  } else if (i < n && j > 1) {
    ans.push_back(node(i, j, i + 1, j, i, j - 1));
    ans.push_back(node(i, j, i, j - 1, i + 1, j - 1));
    ans.push_back(node(i, j, i + 1, j, i + 1, j - 1));
  }
}
inline void do2h(int i, int j) {
  if (i < n) {
    ans.push_back(node(i, j, i + 1, j + 1, i + 1, j));
    ans.push_back(node(i, j + 1, i + 1, j + 1, i + 1, j));
  } else if (i > 1) {
    ans.push_back(node(i, j, i - 1, j + 1, i - 1, j));
    ans.push_back(node(i, j + 1, i - 1, j + 1, i - 1, j));
  }
}
inline void do2s(int i, int j) {
  if (j < n) {
    ans.push_back(node(i, j, i + 1, j + 1, i, j + 1));
    ans.push_back(node(i + 1, j, i + 1, j + 1, i, j + 1));
  } else if (j > 1) {
    ans.push_back(node(i, j, i + 1, j - 1, i, j - 1));
    ans.push_back(node(i + 1, j, i + 1, j - 1, i, j - 1));
  }
}
inline void do2x(int i, int j) {
  ans.push_back(node(i, j, i + 1, j, i, j + 1));
  ans.push_back(node(i + 1, j + 1, i + 1, j, i, j + 1));
}
inline void do2y(int i, int j) {
  ans.push_back(node(i, j, i + 1, j, i, j - 1));
  ans.push_back(node(i + 1, j - 1, i + 1, j, i, j - 1));
}
inline void do31(int i, int j) {
  ans.push_back(node(i + 1, j + 1, i + 1, j, i, j + 1));
}
inline void do32(int i, int j) {
  ans.push_back(node(i - 1, j, i - 1, j + 1, i, j + 1));
}
inline void do33(int i, int j) {
  ans.push_back(node(i, j - 1, i + 1, j - 1, i + 1, j));
}
inline void do34(int i, int j) {
  ans.push_back(node(i - 1, j - 1, i - 1, j, i, j - 1));
}
void work() {
  cin >> n >> m;
  ans.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s + 1);
    for (int j = 1; j <= m; ++j) a[i][j] = s[j] - '0';
  }
  if (n & 1 && m & 1 && a[n][m]) {
    ans.push_back(node(n, m, n - 1, m, n, m - 1));
    a[n - 1][m] ^= 1;
    a[n][m - 1] ^= 1;
  }
  if (n & 1)
    for (int i = 1; i < m; i += 2) {
      if (a[n][i])
        ans.push_back(node(n, i, n - 1, i, n - 1, i + 1)), a[n - 1][i] ^= 1,
            a[n - 1][i + 1] ^= 1;
      if (a[n][i + 1])
        ans.push_back(node(n, i + 1, n - 1, i, n - 1, i + 1)), a[n - 1][i] ^= 1,
            a[n - 1][i + 1] ^= 1;
    }
  if (m & 1)
    for (int i = 1; i < n; i += 2) {
      if (a[i][m])
        ans.push_back(node(i, m, i, m - 1, i + 1, m - 1)), a[i][m - 1] ^= 1,
            a[i + 1][m - 1] ^= 1;
      if (a[i + 1][m])
        ans.push_back(node(i + 1, m, i, m - 1, i + 1, m - 1)), a[i][m - 1] ^= 1,
            a[i + 1][m - 1] ^= 1;
    }
  for (int i = 1; i < n; i += 2)
    for (int j = 1; j < m; j += 2) {
      int s = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];
      if (s == 1) {
        if (a[i][j])
          do1(i, j);
        else if (a[i + 1][j])
          do1(i + 1, j);
        else if (a[i][j + 1])
          do1(i, j + 1);
        else if (a[i + 1][j + 1])
          do1(i + 1, j + 1);
      }
      if (s == 2) {
        if (a[i][j] && a[i + 1][j + 1])
          do2x(i, j);
        else if (a[i][j] && a[i][j + 1])
          do2h(i, j);
        else if (a[i][j] && a[i + 1][j])
          do2s(i, j);
        else if (a[i + 1][j] && a[i][j + 1])
          do2y(i, j + 1);
        else if (a[i + 1][j] && a[i + 1][j + 1])
          do2h(i + 1, j);
        else if (a[i][j + 1] && a[i + 1][j + 1])
          do2s(i, j + 1);
      } else if (s == 3) {
        if (!a[i][j])
          do31(i, j);
        else if (!a[i + 1][j])
          do32(i + 1, j);
        else if (!a[i][j + 1])
          do33(i, j + 1);
        else if (!a[i + 1][j + 1])
          do34(i + 1, j + 1);
      } else if (s == 4)
        do31(i, j), do1(i, j);
    }
  cout << ans.size() << endl;
  for (auto u : ans)
    printf("%d %d %d %d %d %d\n", u.a, u.b, u.c, u.d, u.e, u.f);
}
int main() {
  int T;
  cin >> T;
  while (T--) work();
  return 0;
}
