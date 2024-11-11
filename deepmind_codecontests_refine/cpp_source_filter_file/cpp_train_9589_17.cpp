#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
const int MOD = 1e9 + 7;
const long long INF = 2e18;
vector<int> e[MAX];
long long a[MAX];
long long sum[MAX][21];
int nex[MAX][21];
int cal(pair<int, long long> now, int k, long long L, long long S) {
  int cnt = 0;
  for (int i = 20; i >= 0; i--) {
    if (sum[k][i] + now.second > S) continue;
    if ((1 << i) + now.first > L) continue;
    L -= 1 << i;
    S -= sum[k][i];
    k = nex[k][i];
    cnt += 1 << i;
  }
  return cnt;
}
long long L, S;
int ans = 0;
pair<int, long long> dfs(int k, int fa) {
  nex[k][0] = fa;
  for (int i = 1; i <= 20; i++) nex[k][i] = nex[nex[k][i - 1]][i - 1];
  sum[k][0] = a[k];
  for (int i = 1; i <= 20; i++)
    sum[k][i] = min(sum[k][i - 1] + sum[nex[k][i - 1]][i - 1], INF);
  pair<int, long long> QWQ = make_pair(0, 0);
  int cnt = 0;
  for (int i = 0; i < e[k].size(); i++) {
    pair<int, long long> now = dfs(e[k][i], i);
    if (cal(now, k, L, S) > cnt) {
      cnt = cal(now, k, L, S);
      QWQ = now;
    }
  }
  if (QWQ.first == 0 && ans != -1) {
    if (QWQ.first + 1 <= L && QWQ.second + a[k] <= S)
      ans++;
    else
      ans = -1;
  }
  return {QWQ.first + 1, QWQ.second + a[k]};
}
int main() {
  int n;
  cin >> n >> L >> S;
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 2; i <= n; i++) {
    int x;
    scanf("%d", &x);
    e[x].push_back(i);
  }
  memset(nex, 0, sizeof nex);
  memset(sum, 0, sizeof sum);
  for (int i = 0; i <= 20; i++) sum[0][i] = INF;
  dfs(1, 0);
  cout << ans << endl;
  return 0;
}
