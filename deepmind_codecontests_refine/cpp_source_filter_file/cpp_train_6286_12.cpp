#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int n, m, k;
vector<pair<int, int> > v;
vector<int> res;
struct dsu {
  int par[510], num = 0;
  int FIND(int pos) {
    if (par[pos] != pos) par[pos] = FIND(par[pos]);
    return par[pos];
  }
  void UNION(int pos1, int pos2) {
    int p = FIND(pos1), q = FIND(pos2);
    if (p != q) {
      par[p] = q;
      num++;
    }
  }
} dpl[10010], dpr[10010], ans;
void INIT(dsu &s) {
  for (int i = 1; i <= 505; i++) s.par[i] = i;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    v.push_back({x, y});
  }
  for (int i = 0; i < 1005; i++) INIT(dpl[i]), INIT(dpr[i]);
  for (int i = 0; i < m; i++) {
    dpl[i + 1] = dpl[i];
    dpl[i + 1].UNION(v[i].first, v[i].second);
  }
  for (int i = m - 1; i >= 0; i--) {
    dpr[i + 1] = dpr[i + 2];
    dpr[i + 1].UNION(v[i].first, v[i].second);
  }
  cin >> k;
  while (k--) {
    int x, y;
    scanf("%d%d", &x, &y);
    ans = dpl[x - 1];
    for (int i = 1; i <= n; i++) {
      if (dpr[y + 1].par[i] != i) ans.UNION(i, dpr[y + 1].par[i]);
    }
    res.push_back(n - ans.num);
  }
  for (int i = 0; i < res.size(); i++) cout << res[i] << endl;
  return 0;
}
