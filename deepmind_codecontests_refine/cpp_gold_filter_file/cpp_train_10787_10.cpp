#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int DEG = 30;
const int INF = 0x3f3f3f3f;
int N[maxn];
int Max[maxn][DEG + 1];
int n;
void init() {
  for (int i = 1; i <= n; i++) Max[i][0] = max(N[i], N[i + 1]);
  for (int deg = 1; deg <= DEG; deg++)
    for (int i = 1; i <= n; i++) {
      if (i + (1 << (deg - 1)) <= n)
        Max[i][deg] = max(Max[i][deg - 1], Max[i + (1 << (deg - 1))][deg - 1]);
    }
}
int queryMax(int l, int r) {
  if (r < l) return 0;
  int res = N[l];
  for (int i = DEG; i >= 0; i--) {
    if (l + (1 << i) <= r) {
      res = max(res, Max[l][i]);
      l = l + (1 << i);
    }
  }
  return res;
}
int query(int initMax, int l, int r, int val) {
  if (initMax >= val) return l - 1;
  int Mx = initMax;
  for (int i = DEG; i >= 0; i--) {
    if (l + (1 << i) <= r) {
      if (max(Mx, Max[l][i]) < val) {
        Mx = max(Mx, Max[l][i]);
        l = l + (1 << i);
      }
    }
  }
  return l;
}
vector<int> V[DEG + 1];
vector<pair<int, int> > temp;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &N[i]);
    for (int j = 0; j <= DEG; j++)
      if (N[i] & (1 << j)) V[j].push_back(i);
  }
  init();
  long long Ans = 0;
  for (int i = 1; i <= n; i++) {
    temp.clear();
    for (int j = 0; j <= DEG; j++) {
      int pos = lower_bound(V[j].begin(), V[j].end(), i) - V[j].begin();
      if (pos >= 0 && pos < V[j].size()) {
        temp.push_back(make_pair(V[j][pos], j));
      }
    }
    sort(temp.begin(), temp.end());
    int res = 0;
    temp.push_back(make_pair(n + 1, 0));
    for (int j = 0; j < temp.size() - 1; j++) {
      res |= (1 << temp[j].second);
      if (temp[j].first == temp[j + 1].first) continue;
      int Q = query(queryMax(i, temp[j].first), temp[j].first,
                    temp[j + 1].first - 1, res);
      Ans += Q - (temp[j].first - 1);
    }
  }
  printf("%I64d\n", Ans);
  return 0;
}
