#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 9;
pair<int, int> p[MAX];
set<pair<int, int> > a;
int n, t;
void f(int l, int r) {
  if (r - l < 2) return;
  int m = l + r >> 1;
  for (int i = l; i < r; i++) a.insert({p[m].first, p[i].second});
  f(l, m), f(m, r);
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second, a.insert(p[i]);
  sort(p, p + n), f(0, n);
  cout << a.size() << '\n';
  for (auto i : a) cout << i.first << " " << i.second << '\n';
}
