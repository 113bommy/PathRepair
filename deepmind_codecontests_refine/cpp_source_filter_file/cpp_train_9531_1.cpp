#include <bits/stdc++.h>
using namespace std;
const int N = 1002, M = 10002;
pair<int, long long> dp[N][M];
map<long long, int> di;
bool vis[N][M];
int nxt[N][M];
long long a[N], b[N], k;
int T[M][N];
int n;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  scanf("%d %lld", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", b + i);
    a[i] = gcd(b[i], k);
  }
  if (k == 1) return printf("%d\n%ld\n", 1, min_element(b, b + n) - b + 1);
  vector<long long> divisor;
  for (long long i = 1; i * i <= k; ++i)
    if (k % i == 0) {
      divisor.push_back(i);
      divisor.push_back(k / i);
    }
  sort(divisor.begin(), divisor.end());
  divisor.resize(unique(divisor.begin(), divisor.end()) - divisor.begin());
  int m = divisor.size();
  for (int i = 0; i < m; ++i) di[divisor[i]] = i;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      T[i][j] = di[divisor[i] / gcd(divisor[i], a[j])];
  nxt[n][0] = -1;
  dp[n][0] = {1, 0};
  for (int i = 1; i < m; ++i) dp[n][i] = {n + 1, 0};
  for (int i = 0; i < m; ++i)
    for (int j = n - 1; j >= 0; --j) {
      pair<int, long long> ans1 = dp[j + 1][i];
      pair<int, long long> ans2 = dp[j + 1][T[i][j]];
      ans2.first += 1;
      ans2.second += b[j];
      if (ans1 <= ans2) {
        nxt[j][i] = nxt[j + 1][i];
        dp[j][i] = ans1;
      } else {
        nxt[j][i] = j;
        dp[j][i] = ans2;
      }
    }
  pair<int, long long> ans = dp[0][m - 1];
  if (ans.first > n) return puts("-1"), 0;
  printf("%d\n", ans.first);
  int pos = 0;
  int nx = m - 1;
  while (pos != -1) {
    if (nxt[pos][nx] != pos)
      pos = nxt[pos][nx];
    else {
      nx = T[nx][pos];
      printf("%d ", pos + 1);
      pos += 1;
    }
  }
  puts("");
  return 0;
}
