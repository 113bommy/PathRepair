#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50, SQ = 300, SZ = N / SQ + 10, INF = 0, MOD = 0;
int n, P[N], mark[N], cnt[SZ][N];
vector<pair<int, pair<int, pair<int, int> > > > v;
pair<int, pair<int, int> > qu[N];
vector<int> U;
int get(int x) { return (int)(lower_bound(U.begin(), U.end(), x) - U.begin()); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0, a, t, x; i < n; i++) {
    cin >> a >> t >> x;
    qu[i].first = a, qu[i].second.first = t, qu[i].second.second = x;
    v.push_back(make_pair(t, make_pair(a, make_pair(x, i))));
    U.push_back(x);
    U.push_back(t);
  }
  sort(U.begin(), U.end());
  U.erase(unique(U.begin(), U.end()), U.end());
  for (int i = 0; i < n; i++) {
    qu[i].second.first = get(qu[i].second.first);
    qu[i].second.second = get(qu[i].second.second);
    v[i].first = get(v[i].first);
    v[i].second.second.first = get(v[i].second.second.first);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) P[v[i].second.second.second] = i;
  for (int j = 0; j < n; j++) {
    int a = qu[j].first, t = qu[j].second.first, x = qu[j].second.second;
    mark[P[j]] = 1;
    if (a == 1)
      cnt[P[j] / SQ][x]++;
    else if (a == 2) {
      int CNT = 0;
      for (int i = 0; i < (P[j] / SQ); i++) CNT += cnt[i][x];
      for (int i = (P[j] / SQ) * SQ; i < P[j]; i++) {
        if (v[i].second.second.first != x || mark[i] == 0) continue;
        if (v[i].second.first == 1)
          CNT++;
        else if (v[i].second.first == 2 && CNT > 0)
          CNT--;
      }
      if (CNT > 0) cnt[P[j] / SQ][x]--;
    } else {
      int CNT = 0;
      for (int i = 0; i < (P[j] / SQ); i++) CNT += cnt[i][x];
      for (int i = (P[j] / SQ) * SQ; i < P[j]; i++) {
        if (v[i].second.second.first != x || mark[i] == 0) continue;
        if (v[i].second.first == 1)
          CNT++;
        else if (v[i].second.first == 2 && CNT > 0)
          CNT--;
      }
      cout << CNT << '\n';
    }
  }
  return 0;
}
