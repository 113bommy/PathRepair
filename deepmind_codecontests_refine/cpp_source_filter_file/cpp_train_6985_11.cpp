#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 5e5 + 5;
const double eps = 1e-8;
int par[MAXN];
long long N, M, K;
long long a[MAXN];
pair<int, int> Edege[MAXN];
map<long long, vector<int> > F;
long long pw[MAXN];
int findSet(int p) {
  if (par[p] == p)
    return par[p];
  else
    return par[p] = findSet(par[p]);
}
bool Union(int u, int v) {
  int x = findSet(u);
  int y = findSet(v);
  if (x == y) return true;
  par[y] = x;
  return false;
}
long long solve(vector<int> id) {
  int ans = N;
  vector<int> choose;
  for (__typeof((id).begin()) it = (id).begin(); it != (id).end(); it++) {
    int u = *it;
    choose.push_back(Edege[u].first);
    choose.push_back(Edege[u].second);
  }
  for (__typeof((id).begin()) it = (id).begin(); it != (id).end(); it++) {
    int u = *it;
    int x = Edege[u].first;
    int y = Edege[u].second;
    if (Union(x, y) == false) {
      ans--;
    }
  }
  for (int i = 0; i < choose.size(); ++i) par[choose[i]] = choose[i];
  return pw[ans];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  scanf("%lld %lld %lld", &N, &M, &K);
  pw[0] = 1LL;
  for (int i = 1; i <= N; ++i) pw[i] = (pw[i - 1] * 2) % MOD;
  for (int i = 1; i <= N; ++i) par[i] = i;
  for (int i = 1; i <= N; ++i) scanf("%lld", &a[i]);
  set<long long> myset;
  for (int i = 1; i <= M; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    Edege[i].first = u, Edege[i].second = v;
    long long cur = a[u] ^ a[v];
    myset.insert(cur);
    F[cur].push_back(i);
  }
  long long ans = 0;
  for (__typeof((F).begin()) it = (F).begin(); it != (F).end(); it++) {
    ans += solve(it->second);
    ans %= MOD;
  }
  long long cur = (pw[K] - myset.size()) % MOD;
  cur = (cur * pw[N]) % MOD;
  ans = (ans + cur) % MOD;
  cout << ans;
  return 0;
}
