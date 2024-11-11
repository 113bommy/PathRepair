#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int ma;
vector<int> G[100100];
int d[100100];
int dp[100100];
void dfs(int pos, int fa, int dep) {
  int va = 0;
  int mk = 0;
  int num = 0;
  dp[pos] = dep;
  for (int i : G[pos]) {
    if (i != fa) {
      num++;
      if (d[i] == 1) {
        mk = 1;
      }
    }
  }
  if (!mk) {
    ma += num;
    for (int i : G[pos]) {
      if (i != fa) dfs(i, pos, dep + 1);
    }
  } else {
    ma++;
    for (int i : G[pos]) {
      if (i != fa && d[i] > 1) {
        ma++;
      }
    }
    for (int i : G[pos]) {
      if (i != fa) dfs(i, pos, dep + 1);
    }
  }
  return;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int f, t;
    scanf("%d%d", &f, &t);
    G[f].push_back(t);
    G[t].push_back(f);
    d[f]++;
    d[t]++;
  }
  int rt = 0;
  for (int i = 1; i < +n; i++) {
    if (d[i] != 1) {
      rt = i;
      break;
    }
  }
  dfs(rt, -1, 1);
  int cnt = -1;
  for (int i = 1; i <= n; i++) {
    if (d[i] == 1) {
      if (cnt == -1) {
        cnt = dp[i] % 2;
      } else {
        if (dp[i] % 2 != cnt) cnt = -2;
      }
    }
  }
  printf("%d %d\n", (cnt == -2) ? 3 : 1, ma);
  return 0;
}
