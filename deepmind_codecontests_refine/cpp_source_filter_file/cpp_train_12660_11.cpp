#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 300;
long long n, m, q, p;
char a[MAXN][MAXN];
long long ans[MAXN][MAXN];
long long mark[MAXN][MAXN];
struct st {
  long long a, b, c;
};
void bfs(long long stage, long long i, long long j, long long now) {
  queue<st> Q;
  ans[i][j] += now;
  Q.push({i, j, now});
  mark[i][j] = stage;
  while (!Q.empty()) {
    st tmp = Q.front();
    Q.pop();
    if (tmp.c / 2 != 0) {
      if (tmp.a != 0 && a[tmp.a - 1][tmp.b] != '*' &&
          mark[tmp.a - 1][tmp.b] != stage) {
        ans[tmp.a - 1][tmp.b] += tmp.c / 2;
        mark[tmp.a - 1][tmp.b] = stage;
        Q.push({tmp.a - 1, tmp.b, tmp.c / 2});
      }
      if (tmp.b != 0 && a[tmp.a][tmp.b - 1] != '*' &&
          mark[tmp.a][tmp.b - 1] != stage) {
        ans[tmp.a][tmp.b - 1] += tmp.c / 2;
        mark[tmp.a][tmp.b - 1] = stage;
        Q.push({tmp.a, tmp.b - 1, tmp.c / 2});
      }
      if (tmp.a != n - 1 && a[tmp.a + 1][tmp.b] != '*' &&
          mark[tmp.a + 1][tmp.b] != stage) {
        ans[tmp.a + 1][tmp.b] += tmp.c / 2;
        mark[tmp.a + 1][tmp.b] = stage;
        Q.push({tmp.a + 1, tmp.b, tmp.c / 2});
      }
      if (tmp.b != m - 1 && a[tmp.a][tmp.b + 1] != '*' &&
          mark[tmp.a][tmp.b + 1] != stage) {
        ans[tmp.a][tmp.b + 1] = tmp.c / 2;
        mark[tmp.a][tmp.b + 1] = stage;
        Q.push({tmp.a, tmp.b + 1, tmp.c / 2});
      }
    }
  }
}
void solve() {
  cin >> n >> m >> q >> p;
  for (long long i = (long long)0; i <= (long long)n - 1; i++) {
    for (long long j = (long long)0; j <= (long long)m - 1; j++) {
      cin >> a[i][j];
    }
  }
  long long now = 0;
  for (long long i = (long long)0; i <= (long long)n - 1; i++) {
    for (long long j = (long long)0; j <= (long long)m - 1; j++) {
      if (a[i][j] >= 'A' && a[i][j] <= 'Z') {
        bfs(++now, i, j, (a[i][j] - 'A' + 1) * q);
      }
    }
  }
  long long answer = 0;
  for (long long i = (long long)0; i <= (long long)n - 1; i++) {
    for (long long j = (long long)0; j <= (long long)m - 1; j++) {
      if (ans[i][j] >= p) {
        answer++;
      }
    }
  }
  cout << answer;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
