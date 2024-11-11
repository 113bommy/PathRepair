#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7f7f7f7f;
const long long linf = 1e18;
const int maxn = 3e5 + 9;
const int maxm = 1e7 + 9;
const double PI = acos(-1);
const double eps = 1e-5;
const long long mod = 998244353;
namespace IO {
long long read() {
  long long a = 1, b = 0;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') a = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    b = (b << 3) + (b << 1) + c - '0';
    c = getchar();
  }
  return a * b;
}
void print(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
}  // namespace IO
using namespace IO;
int n, m;
char s[600][600];
int ans[600][600];
vector<int> G[maxn];
const int mov[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
int col[maxn];
int id(pair<int, int> x) { return (x.first - 1) * m + x.second; }
void End() {
  puts("NO");
  exit(0);
}
void dfs(int now) {
  for (auto x : G[now]) {
    if (!col[x]) col[x] = 5 - col[now], dfs(x);
    if (col[x] != 5 - col[now]) End();
  }
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
  vector<pair<int, int> > tmp;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s[i][j] == 'X') {
        tmp.clear();
        for (int k = 0; k <= 3; ++k) {
          int nx = i + mov[k][0], ny = mov[k][1] + j;
          if (s[nx][ny] == '.') tmp.push_back(pair<int, int>(nx, ny));
        }
        if (tmp.size() & 1) {
          End();
        }
        if (tmp.size() == 2) {
          G[id(tmp[0])].push_back(id(tmp[1]));
          G[id(tmp[1])].push_back(id(tmp[0]));
        } else if (tmp.size() == 4) {
          G[id(tmp[0])].push_back(id(tmp[2]));
          G[id(tmp[2])].push_back(id(tmp[0]));
          G[id(tmp[3])].push_back(id(tmp[1]));
          G[id(tmp[1])].push_back(id(tmp[3]));
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s[i][j] == '.') {
        if (!col[id(pair<int, int>(i, j))]) {
          col[id(pair<int, int>(i, j))] = 1;
          dfs(id(pair<int, int>(i, j)));
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s[i][j] == '.') {
        ans[i][j] = col[id(pair<int, int>(i, j))];
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s[i][j] == 'X') {
        int sum = 0;
        for (int k = 0; k <= 3; ++k) {
          int nx = i + mov[k][0], ny = j + mov[k][1];
          if (s[nx][ny] == '.') sum += col[id(pair<int, int>(nx, ny))];
        }
        ans[i][j] = sum;
      }
    }
  }
  puts("YES");
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      print(ans[i][j]);
      putchar(' ');
    }
    putchar('\n');
  }
  return 0;
}
