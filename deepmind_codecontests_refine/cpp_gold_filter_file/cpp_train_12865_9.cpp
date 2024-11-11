#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > V;
vector<pair<int, int> > P;
vector<int> Res;
bool fnc(pair<int, int> L, pair<int, int> R) { return L.second < R.second; }
int main() {
  int n, m, s, e, s1, s2, end, k, l, r;
  scanf("%d%d", &n, &m);
  V.resize(n + 1);
  Res.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    V[i].resize(m + 1);
    for (int j = 1; j <= m; j++) cin >> V[i][j];
  }
  P.clear();
  for (int i = 1; i <= m; i++) {
    s = 1;
    e = 1;
    while (e < n) {
      if (V[e + 1][i] >= V[e][i])
        e++;
      else {
        P.push_back(make_pair(s, e));
        s = e = e + 1;
      }
    }
    P.push_back(make_pair(s, e));
  }
  sort(P.begin(), P.end(), fnc);
  s = P.size();
  s2 = n;
  for (int i = s - 1; i >= 0; i--) {
    end = P[i].second;
    s1 = P[i].first;
    s2 = min(s2, end);
    for (int j = s1; j <= s2; j++) {
      Res[j] = end;
    }
    s2 = min(s2, s1 - 1);
  }
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    scanf("%d%d", &l, &r);
    if (Res[l] >= r)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
