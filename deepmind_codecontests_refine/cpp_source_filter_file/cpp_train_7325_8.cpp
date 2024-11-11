#include <bits/stdc++.h>
const double pi = acos(-1);
const long long MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 1e5 + 5;
const double eps = 1e-9;
using namespace std;
vector<int> pr[MAXN];
int cnt[MAXN], vis[MAXN], a[MAXN];
long long pw[205][MAXN];
int main() {
  int n;
  scanf("%d", &(n));
  for (int i = 0; i < (n); i++) scanf("%d", &(a[i]));
  for (long long i = 1; i <= 200; i++) {
    pw[i][0] = 1;
    for (int j = 1; j < MAXN; j++) pw[i][j] = pw[i][j - 1] * i % MOD;
  }
  for (int i = 0; i < n; i++) vis[a[i]]++;
  for (int k = 1; k < MAXN; k++) {
    for (int i = 1; i * i <= k; i++)
      if (k % i == 0) {
        cnt[k] += 1 + (i * i != k);
        pr[k].push_back(i);
        if (i * i != k) pr[k].push_back(k / i);
      }
    sort(pr[k].begin(), pr[k].end());
    vis[k] += vis[k - 1];
  }
  int ans = 1;
  for (int mx = 2; mx < MAXN; mx++) {
    long long cur = 1;
    for (int j = 0; j < cnt[mx] - 1; j++) {
      int tmp = vis[pr[mx][j + 1] - 1] - vis[pr[mx][j] - 1];
      cur = cur * pw[j + 1][tmp];
    }
    int tmp = n - vis[pr[mx].back() - 1];
    cur = (cur * (pw[cnt[mx]][tmp] - pw[cnt[mx] - 1][tmp] + MOD)) % MOD;
    ans = (ans + cur) % MOD;
  }
  printf("%d\n", (ans));
  return 0;
}
