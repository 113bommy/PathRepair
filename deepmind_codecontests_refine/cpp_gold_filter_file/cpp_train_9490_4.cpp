#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;
const ll INF = 1001001001;
const int MAX = 510000;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> want(n);
  for (int i = 0; i < n; i++) cin >> want[i];
  vector<pair<int, int>> sale(m);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    sale[i] = {a, b};
  }
  ll ok = 0, ng = 0;
  for (int i = 0; i < n; i++) {
    ok += want[i] * 2;
  }
  while (ok - ng > 1) {
    ll mid = (ok + ng) / 2;
    auto f = [&]() {
      vector<int> lst(n, -1);
      for (int i = 0; i < m; i++) {
        if (sale[i].first < mid)
          lst[sale[i].second] = max(sale[i].first, lst[sale[i].second]);
      }
      vector<vector<int>> off(200001);
      for (int i = 0; i < n; i++) {
        if (lst[i] != -1) {
          off[lst[i]].push_back(i);
        }
      }
      vector<int> need = want;
      int mny = 0;
      for (int i = 0; i < mid; i++) {
        mny++;
        if (i > 200000) continue;
        for (int v : off[i]) {
          if (mny >= need[v]) {
            mny -= need[v];
            need[v] = 0;
          } else {
            need[v] -= mny;
            mny = 0;
            break;
          }
        }
      }
      return accumulate(need.begin(), need.end(), 0) * 2 <= mny;
    };
    if (f())
      ok = mid;
    else
      ng = mid;
  }
  cout << ok << endl;
}
