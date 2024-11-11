#include <bits/stdc++.h>
using namespace std;
int a[301], t[301];
int dp[2][150001];
int sp[150001][18];
int n, m, d, tt;
long long vv = 0;
int rr[150001];
void build(int id, int n) {
  for (int i = 1; i <= n; i++) {
    sp[0][i] = dp[id][i];
  }
  for (int i = 1; (1 << i) <= n; i++) {
    for (int j = 1; j + (1 << i) - 1 <= n; j++) {
      sp[i][j] = min(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
    }
  }
}
inline int get(int L, int R) {
  int id = rr[R - L + 1];
  return min(sp[id][L], sp[id][R - (1 << id) + 1]);
}
int main() {
  scanf("%d %d %d", &n, &m, &d);
  for (int i = 1; i <= m; i++) scanf("%d %d %d", &a[i], &tt, &t[i]), vv += tt;
  for (int i = 0; i <= 17; i++) rr[1 << i] = 1;
  rr[0] = -1;
  for (int i = 1; i <= n; i++) rr[i] += rr[i - 1];
  for (int i = 1; i <= n; i++) dp[1][i] = abs(a[1] - i);
  for (int i = 2; i <= m; i++) {
    int lf = 1, rg = 0, nlf, nrg;
    int delta = (int)min((long long)n, (long long)(t[i] - t[i - 1]) * d);
    int cur = i % 2;
    int pr = 1 - cur;
    build(pr, n);
    for (int j = 1; j <= n; j++)
      dp[cur][j] = get(max(1, j - delta), min(n, j + delta)) + abs(a[i] - j);
  }
  cout << vv - *min_element(dp[m % 2] + 1, dp[m % 2] + n + 1) << endl;
  return 0;
}
