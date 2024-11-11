#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 14;
struct Seg {
  set<int> iman[maxn << 2];
  int mx[maxn << 2];
  Seg() { memset(mx, -1, sizeof mx); }
  void majid(int x, int y, bool ad = 1, int l = 0, int r = maxn, int id = 1) {
    if (r - l == 1) {
      if (ad)
        iman[id].insert(y);
      else
        iman[id].erase(y);
      mx[id] = iman[id].size() ? *iman[id].rbegin() : -1;
      return;
    }
    int mid = l + r >> 1;
    if (x < mid)
      majid(x, y, ad, l, mid, id << 1);
    else
      majid(x, y, ad, mid, r, id << 1 | 1);
    mx[id] = max(mx[id << 1], mx[id << 1 | 1]);
  }
  bool hamid(int x, int y, int l = 0, int r = maxn, int id = 1) {
    if (r <= x) return false;
    if (l >= x) return mx[id] >= y;
    int mid = l + r >> 1;
    return hamid(x, y, l, mid, id << 1) || hamid(x, y, mid, r, id << 1 | 1);
  }
} up, down;
int n, m, q;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> q;
  set<pair<int, int> > unavailable;
  bool ans = true;
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    int px = x / 2, py = y / 2;
    if (unavailable.insert({x, y}).second) {
      if (x % 2)
        if (down.hamid(n - px, m - py))
          ans = false;
        else
          up.majid(px, py);
      else if (up.hamid(px, py))
        ans = false;
      else
        down.majid(n - px, m - py);
    }
    cout << (ans ? "YES" : "NO") << '\n';
  }
}
