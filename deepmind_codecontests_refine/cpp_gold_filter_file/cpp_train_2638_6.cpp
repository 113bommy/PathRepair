#include <bits/stdc++.h>
using namespace std;
map<int, int> tab;
int pos[200010], tree[200010 * 8], x[200010 * 2], id[200010], f[200010 * 2];
bool vis[200010];
int h, m, n;
void build_tree(int l, int r, int i) {
  if (l == r) {
    pos[l] = i;
    tree[i] = 1;
    return;
  }
  int mid = (l + r) / 2;
  build_tree(l, mid, i + i);
  build_tree(mid + 1, r, i + i + 1);
  tree[i] = r - l + 1;
}
int get_sum(int tl, int tr, int l, int r, int i) {
  if (r < tl || l > tr) return 0;
  if (tl <= l && r <= tr) return tree[i];
  int mid = (l + r) / 2;
  return get_sum(tl, tr, l, mid, i + i) +
         get_sum(tl, tr, mid + 1, r, i + i + 1);
}
int query(int num, int l, int r, int i) {
  if (l == r) return l;
  int mid = (l + r) / 2;
  if (tree[i + i] < num) return query(num - tree[i + i], mid + 1, r, i + i + 1);
  return query(num, l, mid, i + i);
}
void change(int x, int v) {
  int t = tree[x] - v;
  while (x > 0) {
    tree[x] -= t - v;
    x /= 2;
  }
}
void init() {
  cin >> h >> m >> n;
  int l = 0;
  for (int i = 0; i <= h - 1; i++)
    if (!vis[i]) {
      int now = i, t = 0;
      while (!vis[now]) {
        x[++l] = now;
        id[now] = l;
        vis[now] = true;
        now = (now + m) % h;
        t++;
      }
      for (int k = 1; k <= t; k++) {
        x[l + k] = x[l + k - t];
        f[l + k] = l + k - t;
        f[l + k - t] = l + k;
      }
      l += t;
    }
}
void solve() {
  build_tree(1, 2 * h, 1);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    char ch;
    cin >> ch;
    if (ch == '+') {
      int a, p;
      cin >> a >> p;
      int s = get_sum(1, id[p] - 1, 1, 2 * h, 1);
      int t = query(s + 1, 1, 2 * h, 1);
      tab[a] = t;
      ans += t - id[p];
      change(pos[tab[a]], 0);
      change(pos[f[tab[a]]], 0);
    } else {
      int a;
      cin >> a;
      change(pos[tab[a]], 1);
      change(pos[f[tab[a]]], 1);
    }
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  init();
  solve();
  return 0;
}
