#include <bits/stdc++.h>
using namespace std;
struct fastIO {
  inline fastIO operator>>(int& num) {
    num = 0;
    char c = getchar();
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    bool foo = 0;
    if (c == '-') {
      foo = 1;
      c = getchar();
    }
    while (c >= '0' && c <= '9') {
      num = (num << 3) + (num << 1) + c - '0';
      c = getchar();
    }
    if (foo) num = -num;
    return *this;
  }
  inline fastIO operator>>(long long& num) {
    num = 0;
    char c = getchar();
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    bool foo = 0;
    if (c == '-') {
      foo = 1;
      c = getchar();
    }
    while (c >= '0' && c <= '9') {
      num = (num << 3) + (num << 1) + c - '0';
      c = getchar();
    }
    if (foo) num = -num;
    return *this;
  }
  inline fastIO operator>>(float& num) {
    scanf("%f", &num);
    return *this;
  }
  inline fastIO operator>>(double& num) {
    scanf("%lf", &num);
    return *this;
  }
  inline fastIO operator>>(long double& num) {
    scanf("%Lf", &num);
    return *this;
  }
  inline fastIO operator>>(char& num) {
    num = getchar();
    while (num == ' ' || num == '\n') num = getchar();
    return *this;
  }
  inline fastIO operator>>(char* num) {
    int cnt = 0;
    char c = getchar();
    while (c == ' ' || c == '\n') c = getchar();
    while (c != ' ' && c != '\n') {
      num[cnt++] = c;
      c = getchar();
    }
    num[cnt] = 0;
    return *this;
  }
  inline fastIO operator>>(string& num) {
    cin >> num;
    return *this;
  }
  inline void printInt(const int& num) {
    if (num < 10) {
      putchar(num + '0');
      return;
    }
    printInt(num / 10);
    putchar((num % 10) + '0');
  }
  inline void printINT(const long long& num) {
    if (num < 10) {
      putchar(num + '0');
      return;
    }
    printINT(num / 10);
    putchar((num % 10) + '0');
  }
  inline fastIO operator<<(const int& num) {
    if (num < 0)
      putchar('-'), printInt(-num);
    else
      printInt(num);
    return *this;
  }
  inline fastIO operator<<(const long long& num) {
    if (num < 0)
      putchar('-'), printINT(-num);
    else
      printINT(num);
    return *this;
  }
  inline fastIO operator<<(const float& num) {
    printf("%.10f", num);
    return *this;
  }
  inline fastIO operator<<(const double& num) {
    printf("%.16lf", num);
    return *this;
  }
  inline fastIO operator<<(const long double& num) {
    printf("%.20Lf", num);
    return *this;
  }
  inline fastIO operator<<(const char& num) {
    putchar(num);
    return *this;
  }
  inline fastIO operator<<(const char* num) {
    for (int i = 0; num[i]; i++) putchar(num[i]);
    return *this;
  }
  inline fastIO operator<<(const string& num) {
    cout << num;
    return *this;
  }
} fio;
int a[15][15], c[15][15], a2c[15], c2a[15];
int n, m, k;
bool fucked(int x, int y) {
  for (int i = 0; i <= x; i++) {
    for (int j = 0; j <= y; j++) {
      if (c[i][j] == c[x][y] && (i != x || j != y)) {
        return 1;
      }
    }
  }
  for (int i = x; i < n; i++) {
    for (int j = y; j < m; j++) {
      if (c[i][j] == c[x][y] && (i != x || j != y)) {
        return 1;
      }
    }
  }
  return 0;
}
int dfs(int x, int y, int mx) {
  if (x == n) {
    int cur = 1;
    int fk = k;
    for (int i = 1; i <= mx; i++) {
      if (c2a[i]) {
        fk--;
      }
    }
    for (int i = 1; i <= mx; i++) {
      if (!c2a[i]) {
        cur *= fk;
        fk--;
      }
    }
    return cur;
  }
  if (y == m - 1) {
    return dfs(x + 1, 0, mx);
  }
  if (a[x][y] && a2c[a[x][y]]) {
    c[x][y] = a2c[a[x][y]];
    int cnt = 0;
    if (!fucked(x, y)) {
      cnt += dfs(x, y + 1, mx);
    }
    c[x][y] = 0;
    return cnt;
  }
  int cnt = 0;
  for (int i = 1; i <= min(k, mx + 1); i++) {
    c[x][y] = i;
    if (!fucked(x, y)) {
      if (a[x][y]) {
        if (!c2a[i]) {
          c2a[i] = a[x][y];
          a2c[a[x][y]] = i;
          cnt += dfs(x, y + 1, max(mx, i));
          if (cnt > 1000000007) {
            cnt -= 1000000007;
          }
          c2a[i] = 0;
          a2c[a[x][y]] = 0;
        }
      } else {
        cnt += dfs(x, y + 1, max(mx, i));
        if (cnt > 1000000007) {
          cnt -= 1000000007;
        }
      }
    }
    c[x][y] = -1;
  }
  return cnt;
}
int main() {
  fio >> n >> m >> k;
  if (n + m - 1 > k) {
    fio << 0 << '\n';
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      fio >> a[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    c[0][i] = i + 1;
    if (a[0][i]) {
      if (a2c[a[0][i]]) {
        fio << 0 << '\n';
        return 0;
      }
      a2c[a[0][i]] = i + 1;
      c2a[i + 1] = a[0][i];
    }
  }
  for (int i = 1; i < n; i++) {
    c[i][m - 1] = m + i;
    if (a[i][m - 1]) {
      if (a2c[a[i][m - 1]]) {
        fio << 0 << '\n';
        return 0;
      }
      a2c[a[i][m - 1]] = m + i;
      c2a[m + i] = a[i][m - 1];
    }
  }
  fio << dfs(1, 0, n + m - 1) << '\n';
  return 0;
}
