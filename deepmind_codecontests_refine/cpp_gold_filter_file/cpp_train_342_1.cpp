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
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int n, m, k;
int fl[205];
int dp[(1 << (7)) + 5][205];
pair<int, int> go[(1 << (7)) + 5][205];
int X[10], Y[10];
char ans[205];
bool lgl[205];
inline int code(int x, int y) { return x * m + y; }
void dfs(int x, int y) {
  ans[y] = 'X';
  if (go[x][y].second == y) {
    if (go[x][y].first) {
      dfs(go[x][y].first, go[x][y].second);
      dfs(x ^ go[x][y].first, go[x][y].second);
    }
  } else {
    if (go[x][y].first) {
      dfs(go[x][y].first, go[x][y].second);
    }
  }
}
int main() {
  fio >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      fio >> fl[code(i, j)];
    }
  }
  memset((void*)dp, 0x3f, sizeof(dp));
  for (int i = 0; i < k; i++) {
    fio >> X[i] >> Y[i];
    X[i]--;
    Y[i]--;
    dp[(1 << (i))][code(X[i], Y[i])] = fl[code(X[i], Y[i])];
  }
  for (int i = 1; i < (1 << (k)); i++) {
    queue<int> q;
    memset((void*)lgl, 0, sizeof(lgl));
    for (int j = 0; j < n * m; j++) {
      q.push(j);
      lgl[j] = 1;
      for (int k = i & (i - 1); k; k = i & (k - 1)) {
        int val = dp[k][j] + dp[i ^ k][j] - fl[j];
        if (val < dp[i][j]) {
          dp[i][j] = val;
          go[i][j] = make_pair(k, j);
        }
      }
    }
    while (((int)(q).size())) {
      int j = q.front() / m, k = q.front() % m;
      lgl[q.front()] = 0;
      q.pop();
      for (int l = 0; l < 4; l++) {
        int x = j + dx[l], y = k + dy[l];
        if (x < 0 || x >= n || y < 0 || y >= m) {
          continue;
        }
        int num = dp[i][code(j, k)] + fl[code(x, y)];
        if (num < dp[i][code(x, y)]) {
          dp[i][code(x, y)] = num;
          go[i][code(x, y)] = make_pair(i, code(j, k));
          if (!lgl[code(x, y)]) {
            q.push(code(x, y));
            lgl[code(x, y)] = 1;
          }
        }
      }
    }
  }
  memset(ans, '.', sizeof(ans));
  int minx = ((int)0x3f3f3f3f), mnpos;
  for (int i = 0; i < n * m; i++) {
    if (dp[(1 << (k)) - 1][i] < minx) {
      minx = dp[(1 << (k)) - 1][i];
      mnpos = i;
    }
  }
  fio << minx << '\n';
  dfs((1 << (k)) - 1, mnpos);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      fio << ans[code(i, j)];
    }
    fio << '\n';
  }
  return 0;
}
