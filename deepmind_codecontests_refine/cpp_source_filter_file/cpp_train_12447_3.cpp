#include <bits/stdc++.h>
const int MOD = 1000000007;
const int N = 5E5 + 15;
const int maxn = 400 + 14;
const int mm = 100000 + 15;
const int letter = 130;
const int INF = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-8;
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, c, a[N], ps[N];
vector<int> g[N];
void add(int l, int r) { ps[l]++, ps[r + 1]--; }
int main() {
  int x, y;
  scanf("%d%d", &n, &c);
  for (int i = 0; i < n; i++) {
    scanf("%d", &y);
    while (y--) {
      scanf("%d", &x);
      g[i].push_back(x);
    }
  }
  for (int i = 0; i < n - 1; i++) {
    int sz = min(g[i].size(), g[i + 1].size());
    int flag = 1;
    for (int j = 0; j < sz; j++) {
      int a = g[i][j], b = g[i + 1][j];
      if (a == b)
        continue;
      else if (a > b)
        add(0, c - a), add(c - b + 1, c - 1);
      else
        add(c - b + 1, c - a + 1);
      flag = 0;
      break;
    }
    if (flag) {
      if (g[i].size() > g[i + 1].size()) {
        printf("%d\n", -1);
        return 0;
      }
    }
  }
  int cc = 0;
  for (int i = 0; i <= c - 1; i++) {
    cc += ps[i];
    if (cc == 0) {
      printf("%d\n", i);
      return 0;
    }
  }
  puts("-1");
  return 0;
}
