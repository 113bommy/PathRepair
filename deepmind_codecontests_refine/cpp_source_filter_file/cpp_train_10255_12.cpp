#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int MAXN = 2005;
int n, p[MAXN], s[MAXN];
int from[MAXN], to[MAXN];
vector<pair<int, int> > mov;
set<int> S;
void solve() {
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    from[p[i]] = i;
    to[s[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    ans += abs(from[i] - to[i]);
  }
  ans /= 2;
  printf("%d\n", ans);
  mov.clear();
  bool change = true;
  while (change) {
    change = false;
    S.clear();
    for (int i = n; i >= 1; i--) {
      if (to[p[i]] > i) {
        set<int>::iterator it = S.upper_bound(i);
        if (it != S.end()) {
          int j = *it;
          if (j <= to[p[i]]) {
            from[p[i]] = j;
            from[p[j]] = i;
            swap(p[i], p[j]);
            mov.push_back(make_pair(i, j));
            change = true;
            S.erase(j);
          }
        }
      }
      if (to[p[i]] < i) {
        S.insert(i);
      }
      if (from[p[i]] > i) {
        S.erase(from[p[i]]);
      }
    }
  }
  printf("%d\n", (int)mov.size());
  for (int i = 0; i < (int)mov.size(); i++) {
    printf("%d %d\n", mov[i].first, mov[i].second);
  }
}
int main() {
  while (scanf("%d", &n) == 1) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", p + i);
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", s + i);
    }
    solve();
  }
}
