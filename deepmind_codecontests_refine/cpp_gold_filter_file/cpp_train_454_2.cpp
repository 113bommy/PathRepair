#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N];
void enter() {
  cin >> n;
  for (int i = (1), _b = (n); i <= _b; ++i) cin >> a[i];
}
int par[N];
int fn(int x) { return par[x] == x ? x : par[x] = fn(par[x]); }
inline void uni(int x, int y) { par[fn(x)] = fn(y); }
void process() {
  int ans = 0;
  for (int i = (1), _b = (n + 2); i <= _b; ++i) par[i] = i;
  vector<int> New, cur;
  for (int i = (1), _b = (n); i <= _b; ++i) cur.push_back(i);
  int p;
  while (!cur.empty()) {
    New.clear();
    for (int i = (0), _b = (((int)(cur).size())); i < _b; ++i) {
      p = cur[i];
      if (fn(p) != p) continue;
      if (fn(p + 1) <= n && a[p] > a[fn(p + 1)]) {
        New.push_back(p);
        p = fn(p + 1);
        while (fn(p + 1) <= n && a[p] > a[fn(p + 1)]) {
          uni(p, p + 1);
          p = fn(p + 1);
        }
        uni(p, p + 1);
      }
    }
    ++ans;
    cur = New;
  }
  cout << ans - 1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  enter();
  process();
  return 0;
}
