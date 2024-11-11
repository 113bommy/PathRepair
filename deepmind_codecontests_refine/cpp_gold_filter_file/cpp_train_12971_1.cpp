#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int MAXN = 100005;
const int MAXM = 5005;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const double FINF = 10000000;
const long long MOD = 1000000007;
const double PI = acos(-1);
vector<int> v[MAXN];
int cntA[MAXN * 100], cntB[MAXN * 100], pA, pB;
int dep[MAXN], val[MAXN];
bool vis[MAXN];
int maxx, maxv;
void dfs(int u, int fa, int cur) {
  dep[u] = cur;
  vis[u] = 1;
  maxx = max(cur, maxx);
  for (int i = 0; i < v[u].size(); ++i) {
    int vv = v[u][i];
    if (vis[vv]) continue;
    dfs(vv, u, cur + 1);
  }
}
int main() {
  int n, tmp, f;
  pA = pB = 0;
  memset(cntA, 0, sizeof(cntA));
  memset(cntB, 0, sizeof(cntB));
  memset(vis, 0, sizeof(vis));
  scanf("%d", &n);
  maxv = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &val[i]);
    maxv = max(maxv, val[i]);
  }
  for (int i = 2; i <= n; ++i) {
    scanf("%d", &tmp);
    v[tmp].push_back(i);
  }
  int s = 0;
  maxx = 0;
  dfs(1, 1, 1);
  f = maxx % 2;
  for (int i = 1; i <= n; ++i) {
    if (dep[i] % 2 == f) {
      cntA[val[i]]++;
      s ^= val[i];
      pA++;
    } else {
      cntB[val[i]]++;
      pB++;
    }
  }
  long long ans = 0;
  if (s == 0) {
    ans += pA * 1LL * (pA - 1) / 2;
    ans += pB * 1LL * (pB - 1) / 2;
    for (int i = 1; i <= maxv; ++i) {
      ans += cntA[i] * 1LL * cntB[i];
    }
  } else {
    for (int i = 1; i <= maxv; ++i) {
      if ((s ^ i) > MAXN * 100) continue;
      ans += cntA[i] * 1LL * cntB[s ^ i];
    }
  }
  cout << ans << endl;
}
