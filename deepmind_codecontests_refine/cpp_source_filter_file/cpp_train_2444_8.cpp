#include <bits/stdc++.h>
using namespace std;
long long num[51][51];
char s[55][55];
bool visit[55][55];
long long xy[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
long long n, m;
bool dfs(long long x, long long y, long long n1, long long col) {
  bool ans = false;
  num[x][y] = n1;
  visit[x][y] = 1;
  for (long long i = 0; i < 4; i++) {
    long long a = x + xy[i][0], b = y + xy[i][1];
    if (a < n and b < m and a >= 0 and b >= 0 and visit[a][b] and
        abs(num[a][b] - n1) >= 3 and s[a][b] - 'A' == col) {
      return true;
    } else if (a < n and b < m and b >= 0 and a >= 0 and !visit[a][b] and
               s[a][b] - 'A' == col) {
      ans |= dfs(a, b, n1 + 1, col);
    }
  }
  return ans;
}
int main() {
  scanf("%lld %lld", &n, &m);
  for (long long i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  long long ans = false;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      if (!visit[i][j]) ans |= dfs(i, j, 1, s[i][j] - 'A');
    }
  }
  if (ans)
    printf("Yes");
  else
    printf("No");
}
