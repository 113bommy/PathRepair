#include <bits/stdc++.h>
using namespace std;
char ch[4507][4507];
const int N = 4507;
bool prime[N];
int p[N], tot;
void init() {
  for (int i = 2; i < N; i++) prime[i] = true;
  for (int i = 2; i < N; i++) {
    if (prime[i]) p[tot++] = i;
    for (int j = 0; j < tot && i * p[j] < N; j++) {
      prime[i * p[j]] = false;
      if (i % p[j] == 0) break;
    }
  }
}
int sum[4507][4507];
int n, m;
int ac(int k) {
  memset(sum, 0, sizeof sum);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      sum[i / k][j / k] += ch[i][j] - '0';
    }
  }
  int ret = 0;
  for (int i = 0; i <= (n - 1) / k; i++) {
    for (int j = 0; j <= (m - 1) / k; j++) {
      ret += min(sum[i][j], k * k - sum[i][j]);
    }
  }
  return ret;
}
int main() {
  init();
  scanf("%d%d", &n, &m);
  int ans = n * m;
  for (int i = 0; i < n; i++) {
    scanf("%s", ch[i]);
    for (int j = 0; j < m; j++) {
    }
  }
  for (int i = 0; p[i] < 3; i++) {
    ans = min(ans, ac(p[i]));
  }
  printf("%d\n", ans);
  return 0;
}
