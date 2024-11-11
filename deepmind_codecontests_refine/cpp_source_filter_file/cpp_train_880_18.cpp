#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int M = 1e9;
const int inf = 1e9 + 7;
const long long base = 1e18;
const double pi = acos(-1);
const double ep = 1e-9;
int n, m, k, q;
vector<pair<int, int> > rook;
vector<pair<pair<pair<int, int>, pair<int, int> >, int> > rect;
int a[N * 3], ans[N];
void update(int i, int l, int r, int x, int gt) {
  if (l == x && r == x) {
    a[i] = gt;
    return;
  }
  int g = (l + r) >> 1, next = i << 1;
  if (x <= g)
    update(next, l, g, x, gt);
  else
    update(next + 1, g + 1, r, x, gt);
  a[i] = max(a[next], a[next + 1]);
}
int get(int i, int l, int r, int u, int v) {
  if (l == u && r == v) {
    return a[i];
  }
  int g = (l + r) >> 1, next = i << 1;
  int tmp = 0;
  if (u <= g) tmp = max(tmp, get(next, l, g, u, min(g, v)));
  if (g < v) tmp = max(tmp, get(next + 1, g + 1, r, max(u, g + 1), v));
  return tmp;
}
void solve() {
  for (int i = (int)1; i < (int)m + 1; i++) {
    update(1, 1, m, i, inf);
  }
  int j = k - 1;
  int cur = q - 1;
  for (int x = n; x > 0; x--) {
    while (j >= 0 && rook[j].first >= x) {
      update(1, 1, m, rook[j].second, rook[j].first);
      j--;
    }
    while (cur >= 0 && rect[cur].first.first.first == x) {
      pair<pair<int, int>, pair<int, int> > rec = rect[cur].first;
      int id = rect[cur].second;
      int tmp = get(1, 1, m, rec.first.second, rec.second.second);
      if (tmp <= rec.second.first) ans[id] = 1;
      cur--;
    }
  }
}
int main() {
  cin >> n >> m >> k >> q;
  for (int i = (int)0; i < (int)k; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    rook.push_back(make_pair(u, v));
  }
  for (int i = (int)0; i < (int)q; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    pair<int, int> fir = make_pair(u, v);
    scanf("%d%d", &u, &v);
    pair<int, int> sec = make_pair(u, v);
    rect.push_back(make_pair(make_pair(fir, sec), i));
  }
  sort(rook.begin(), rook.end());
  sort(rect.begin(), rect.end());
  solve();
  for (int i = (int)0; i < (int)k; i++) swap(rook[i].first, rook[i].second);
  for (int i = (int)0; i < (int)q; i++) {
    swap(rect[i].first.first.first, rect[i].first.first.second);
    swap(rect[i].first.second.first, rect[i].first.second.second);
  }
  swap(n, m);
  sort(rook.begin(), rook.end());
  sort(rect.begin(), rect.end());
  solve();
  for (int i = (int)0; i < (int)q; i++)
    if (ans[i])
      puts("YES");
    else
      puts("NO");
}
