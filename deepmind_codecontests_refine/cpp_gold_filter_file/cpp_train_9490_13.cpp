#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
int n, m, need[2000010], need2[2000010], tmp[2000010];
vector<int> orders[2000010];
vector<pair<int, int> > last;
int can(int k) {
  for (int i = 1; i <= n; i++) {
    tmp[i] = 0;
    need2[i] = need[i];
  }
  last.clear();
  for (int i = 1; i <= k; i++)
    for (int j = 0; j < orders[i].size(); j++) tmp[orders[i][j]] = i;
  for (int i = 1; i <= n; i++) last.push_back(make_pair(tmp[i], i));
  sort(last.begin(), last.end());
  int used = 0;
  for (int i = 0; i < last.size(); i++) {
    need2[last[i].second] -=
        min(max((last[i].first - used), 0), need[last[i].second]);
    used += need[last[i].second] - need2[last[i].second];
  }
  int remain = 0;
  for (int i = 1; i <= n; i++) remain += need2[i];
  remain *= 2;
  return k >= remain + used;
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> need[i];
  int d, t;
  for (int i = 1; i <= m; i++) {
    cin >> d >> t;
    orders[d].push_back(t);
  }
  int l = 1, r = 4e5, m;
  while (l <= r) {
    m = (l + r) / 2;
    if (can(m))
      r = m - 1;
    else
      l = m + 1;
  }
  if (can(r))
    cout << r;
  else
    cout << l;
}
int main() { solve(); }
