#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> current;
int n, i, j, d[1000001], a[1000001];
int T[4000001];
void Build(int v, int tl, int tr) {
  if (tl == tr) {
    T[v] = a[tl];
    return;
  }
  int tm = (tl + tr) / 2;
  Build(2 * v, tl, tm);
  Build(2 * v + 1, tm + 1, tr);
  T[v] = min(T[2 * v], T[2 * v + 1]);
}
int mini(int v, int tl, int tr, int l, int r) {
  if (l > r) return 1000000LL;
  if (tl == l && tr == r) return T[v];
  int tm = (tl + tr) / 2;
  return min(mini(2 * v, tl, tm, l, min(tm, r)),
             mini(2 * v + 1, tm + 1, tr, max(tm + 1, l), r));
}
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  Build(1, 1, n);
  current[{-1, n}]++;
  int maxi = 0;
  for (i = 1; i <= n; i++) {
    while (1) {
      pair<pair<int, int>, int> p = (*(current.begin()));
      if (p.first.second < i) {
        current[p.first]--;
        if (current[p.first] == 0) current.erase(p.first);
      } else
        break;
    }
    pair<pair<int, int>, int> p = *current.begin();
    d[i] = -p.first.first;
    maxi = max(maxi, a[i]);
    int l, r, mid;
    l = i + 1;
    r = n;
    if (i == n) break;
    while (l < r) {
      if (l == r - 1) {
        if (mini(1, 1, n, i + 1, r) >= maxi) l = r;
        break;
      }
      mid = (l + r) / 2;
      int u = mini(1, 1, n, i + 1, mid);
      if (u >= maxi)
        l = mid;
      else
        r = mid - 1;
    }
    if (mini(1, 1, n, i + 1, l) >= maxi) current[{-(d[i] + 1), l}]++;
  }
  cout << d[n];
  return 0;
}
