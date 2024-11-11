#include <bits/stdc++.h>
using namespace std;
int const INF = 1e9 + 10;
long long const BINF = 1e18 + 10;
int const MAXN = 1e6 + 10;
long double const EPS = 1e-6;
int n, aa, min1, cost[MAXN], p, mini;
set<int>::iterator it;
vector<set<int> > st;
pair<int, int> a[MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));
  cin >> n;
  st.resize(7);
  for (int i = 1; i <= n; i++) {
    cin >> cost[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].second;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
    if (a[i].first == 1 && a[i].second == 1) st[1].insert(cost[i]);
    if (a[i].first == 1 && a[i].second == 2) st[2].insert(cost[i]);
    if (a[i].first == 1 && a[i].second == 3) st[3].insert(cost[i]);
    if (a[i].first == 2 && a[i].second == 2) st[4].insert(cost[i]);
    if (a[i].first == 2 && a[i].second == 3) st[5].insert(cost[i]);
    if (a[i].first == 3 && a[i].second == 3) st[6].insert(cost[i]);
  }
  cin >> p;
  for (int j = 1; j <= p; j++) {
    cin >> aa;
    min1 = INF;
    if (aa == 1) {
      for (int i = 1; i <= 3; i++) {
        if (!st[i].empty()) {
          it = st[i].begin();
          if (*it < min1) mini = i;
          min1 = min(min1, *it);
        }
      }
    } else if (aa == 2) {
      for (int i = 2; i <= 5; i++) {
        if (i == 3) continue;
        if (!st[i].empty()) {
          it = st[i].begin();
          if (*it < min1) mini = i;
          min1 = min(*it, min1);
        }
      }
    } else {
      for (int i = 3; i <= 6; i++) {
        if (i == 4) continue;
        if (!st[i].empty()) {
          it = st[i].begin();
          if (*it < min1) mini = i;
          min1 = min(*it, min1);
        }
      }
    }
    if (min1 == INF)
      cout << -1 << " ";
    else {
      cout << min1 << " ";
      st[mini].erase(*st[mini].begin());
    }
  }
  return 0;
}
