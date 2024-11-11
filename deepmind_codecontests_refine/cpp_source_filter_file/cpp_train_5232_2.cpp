#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int MAX(int &a, int b) { return a = max(a, b); }
const int MIN(int &a, int b) { return a = min(a, b); }
int n;
pair<int, int> a[200005], r[200005];
void read() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
}
set<int> ma[200005];
void solve() {
  for (int i = 0; i < 200005; i++) ma[i].clear();
  sort(a, a + n);
  int tmp = 0;
  r[0] = make_pair(++tmp, a[0].second);
  for (int i = 1; i <= n - 1; i++) {
    if (a[i].first != a[i - 1].first) {
      r[i] = make_pair(++tmp, a[i].second);
    } else {
      r[i] = make_pair(tmp, a[i].second);
    }
  }
  for (int i = 0; i < n; i++) ma[r[i].first].insert(r[i].second);
  int ptr = 0;
  set<int> pre = ma[0];
  int cur = ma[0].size();
  int best = cur;
  for (int i = 1; i <= n - 1; i++) {
    set<int> now = ma[i];
    if (*pre.begin() < *now.begin())
      cur++;
    else {
      cur = 1;
    }
    pre = now;
    MAX(best, cur);
  }
  cout << n - best << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    read();
    solve();
  }
}
