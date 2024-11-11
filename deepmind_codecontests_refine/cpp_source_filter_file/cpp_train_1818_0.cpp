#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
vector<int> adj[55];
int fac[100100];
int n, k;
map<long long, vector<int> > mp;
int tot;
long long now, nei[55];
int flag[55], x[55], y[55], w[55];
vector<int> calc(long long);
void update(long long st, int u) {
  flag[u] = 1;
  now |= 1LL << u;
  for (int v : adj[u])
    if ((((st) >> (v)) & 1) && !flag[v]) update(st, v);
}
vector<int> calc1(long long st) {
  if (st == 0) return vector<int>(1, 1);
  int ct = __builtin_popcountll(st);
  if (ct < 36 && mp.count(st)) return mp[st];
  int mincnt = 55, minid = 0;
  for (int i = 0; i < k; i++)
    if ((((st) >> (i)) & 1)) {
      long long st1 = st ^ (1LL << i);
      int mxcnt = 0;
      memset(flag, 0, sizeof flag);
      for (int j = 0; j < k; j++)
        if ((((st1) >> (j)) & 1) && !flag[j]) {
          now = 0;
          update(st1, j);
          int ct1 = __builtin_popcountll(now);
          if (mxcnt < ct1) mxcnt = ct1;
        }
      if (mxcnt < mincnt) mincnt = mxcnt, minid = i;
    }
  long long st1 = st ^ (1LL << minid);
  vector<int> ans = calc(st1);
  vector<int> ans1 = calc(st1 ^ (st1 & nei[minid]));
  ans1.insert(ans1.begin(), 0);
  for (int i = 0; i < ans1.size(); i++)
    ans1[i] = (long long)ans1[i] * w[minid] % MOD;
  if (ans1.size() > ans.size()) swap(ans, ans1);
  for (int i = 0; i < ans1.size(); i++) ans[i] = (ans[i] + ans1[i]) % MOD;
  if (ct < 36) mp[st] = ans;
  return ans;
}
vector<int> calc(long long st) {
  if (st == 0) return vector<int>(1, 1);
  memset(flag, 0, sizeof flag);
  vector<long long> mem;
  for (int i = 0; i < k; i++) {
    if ((((st) >> (i)) & 1) && !flag[i]) {
      now = 0;
      update(st, i);
      mem.push_back(now);
    }
  }
  vector<int> ans(1, 1);
  for (long long x : mem) {
    vector<int> tmp = calc1(x);
    vector<int> tp(tmp.size() + ans.size() - 1, 0);
    for (int i = 0; i < ans.size(); i++)
      for (int j = 0; j < tmp.size(); j++) {
        tp[i + j] = (tp[i + j] + (long long)ans[i] * tmp[j]) % MOD;
      }
    ans = tp;
  }
  return ans;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < k; i++)
    cin >> x[i] >> y[i] >> w[i], w[i] = (w[i] + MOD - 1) % MOD;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++)
      if (i != j && (x[i] == x[j] || y[i] == y[j])) {
        adj[i].push_back(j);
        nei[i] |= 1LL << j;
      }
  }
  for (int i = fac[0] = 1; i <= n; i++)
    fac[i] = (long long)fac[i - 1] * i % MOD;
  vector<int> ans = calc((1LL << n) - 1);
  int res = 0;
  for (int i = 0; i < ans.size(); i++)
    res = (res + (long long)fac[n - i] * ans[i]) % MOD;
  cout << res << endl;
  return 0;
}
