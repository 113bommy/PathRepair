#include <bits/stdc++.h>
using namespace std;
int n, t[1000000];
multiset<int> S;
multiset<int>::iterator it1, it2, it, cit;
inline void Union(int x, int y) {
  if (x == y) return;
  t[x] += t[y];
  t[y] = x;
}
inline int Find(int x) {
  int cx = x;
  while (t[x] > 0) x = t[x];
  int rad = x;
  while (t[cx] > 0) {
    x = t[cx];
    t[cx] = rad;
    cx = x;
  }
  return rad;
}
inline void Solve(int st, int dr) {
  if (S.find(st) == S.end()) S.insert(st);
  if (S.find(dr + 1) == S.end()) S.insert(dr + 1);
  it1 = S.find(st);
  it2 = S.find(dr + 1);
  for (it = it1; *it != dr + 1; ++it) Union(Find(*it), Find(dr));
  for (it = it2, --it; *it != st;) {
    cit = it;
    --it;
    S.erase(cit);
  }
}
int main() {
  int i, m, tip, x, y;
  cin.sync_with_stdio(0);
  cin >> n >> m;
  for (i = 1; i <= n; ++i) {
    t[i] = -1;
    S.insert(i);
  }
  while (m--) {
    cin >> tip >> x >> y;
    if (tip == 3) {
      if (Find(x) == Find(y))
        cout << "YES\n";
      else
        cout << "NO\n";
    }
    if (tip == 2) Solve(x, y);
    if (tip == 1) Union(Find(x), Find(y));
  }
  return 0;
}
