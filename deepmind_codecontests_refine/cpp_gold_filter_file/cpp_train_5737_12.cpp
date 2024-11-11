#include <bits/stdc++.h>
inline void read(int& x) {
  char c;
  while ((c = getchar()) < '0' || c > '9')
    ;
  x = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
}
using namespace std;
const int maxn = 3e5 + 10;
const int M = 131;
const int inf = 0x7fffffff;
const long long INF = 9E18;
const long long mod = 1e9 + 7;
const int eps = 1e-7;
const double pi = 3.1415926535898;
pair<int, int> p[maxn];
pair<int, int> pre[2][maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].first, &p[i].second);
  sort(p + 1, p + n + 1);
  for (int i = 1; i <= n; i++) {
    if (i == 1) {
      pre[0][i].first = p[i].first;
      pre[0][i].second = p[i].second;
    } else {
      int nowi = p[i].first;
      int nowj = p[i].second;
      pre[0][i].first = max(nowi, pre[0][i - 1].first);
      pre[0][i].second = min(nowj, pre[0][i - 1].second);
    }
  }
  for (int i = n; i >= 1; i--) {
    if (i == n) {
      pre[1][i].first = p[i].first;
      pre[1][i].second = p[i].second;
    } else {
      int nowi = p[i].first;
      int nowj = p[i].second;
      pre[1][i].first = max(nowi, pre[1][i + 1].first);
      pre[1][i].second = min(nowj, pre[1][i + 1].second);
    }
  }
  pre[0][0].first = 0;
  pre[0][0].second = inf;
  pre[1][n + 1].first = 0;
  pre[1][n + 1].second = inf;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int nowi = max(pre[1][i + 1].first, pre[0][i - 1].first);
    int nowj = min(pre[1][i + 1].second, pre[0][i - 1].second);
    ans = max(ans, max(nowj - nowi, 0));
  }
  cout << ans << endl;
  return 0;
}
