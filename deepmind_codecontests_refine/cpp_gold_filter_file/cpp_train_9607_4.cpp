#include <bits/stdc++.h>
using namespace std;
long long t, n, m;
queue<pair<long long, long long>> ans;
bool x[105][105];
void q(long long a, long long b, long long dr, long long dc) {
  ans.push({a, b});
  ans.push({a + dr, b});
  ans.push({a, b + dc});
  ans.push({a, b});
  ans.push({a + dr, b + dc});
  ans.push({a, b + dc});
  ans.push({a, b});
  ans.push({a + dr, b + dc});
  ans.push({a + dr, b});
}
int main() {
  long long i, j, k, a, b;
  char c;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld%lld", &n, &m);
    getchar();
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        scanf("%c", &c);
        x[i][j] = c - '0';
      }
      getchar();
    }
    for (i = 1; i < n; i++)
      for (j = 1; j < m; j++)
        if (x[i][j]) q(i, j, 1, 1);
    for (i = 1; i < n; i++)
      if (x[i][m]) q(i, m, 1, -1);
    for (i = 1; i < m; i++)
      if (x[n][i]) q(n, i, -1, 1);
    if (x[n][m]) q(n, m, -1, -1);
    printf("%lu \n", ans.size() / 3);
    while (!ans.empty()) {
      tie(a, b) = ans.front();
      ans.pop();
      printf("%lld %lld ", a, b);
      tie(a, b) = ans.front();
      ans.pop();
      printf("%lld %lld ", a, b);
      tie(a, b) = ans.front();
      ans.pop();
      printf("%lld %lld ", a, b);
      printf("\n");
    }
  }
}
