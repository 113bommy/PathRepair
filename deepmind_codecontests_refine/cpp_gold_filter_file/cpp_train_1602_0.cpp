#include <bits/stdc++.h>
using namespace std;
long long sum[500];
int deep[500];
int in1[500];
int out1[500];
int in2[500];
int out2[500];
vector<int> maps1[500];
vector<int> maps2[500];
long long dp[150000];
long long n, m, t;
int cnt = 0;
void topo2() {
  queue<int> q;
  for (int i = 1; i <= n; ++i)
    if (in2[i] == 0) {
      q.push(i);
      deep[i] = 0;
    }
  int n1, n2;
  while (!q.empty()) {
    n1 = q.front();
    q.pop();
    cnt++;
    t -= deep[n1] * sum[n1];
    for (int i = 0; i < maps2[n1].size(); ++i) {
      n2 = maps2[n1][i];
      in2[n2]--;
      deep[n2] = max(deep[n2], deep[n1] + 1);
      if (in2[n2] == 0) q.push(n2);
    }
  }
}
void topo1() {
  queue<int> q;
  int n1, n2;
  for (int i = 1; i <= n; ++i)
    if (in1[i] == 0) {
      q.push(i);
    }
  while (!q.empty()) {
    n1 = q.front();
    q.pop();
    for (int i = 0; i < maps1[n1].size(); ++i) {
      n2 = maps1[n1][i];
      in1[n2]--;
      sum[n2] += sum[n1];
      if (in1[n2] == 0) {
        q.push(n2);
      }
    }
  }
}
int main() {
  scanf("%lld%lld%lld", &n, &m, &t);
  for (int i = 1; i <= n; ++i) scanf("%lld", &sum[i]);
  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    maps1[x].push_back(y);
    in1[y]++;
    out1[x]++;
    maps2[y].push_back(x);
    in2[x]++;
    out2[y]++;
  }
  topo2();
  if (t < 0 || cnt != n)
    printf("0\n");
  else {
    topo1();
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (long long i = 1; i <= n; ++i) {
      for (long long j = sum[i]; j <= t; ++j) {
        dp[j] += dp[j - sum[i]];
        dp[j] %= 1000000007;
      }
    }
    printf("%lld\n", dp[t]);
  }
  return 0;
}
