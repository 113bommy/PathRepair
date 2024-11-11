#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000010;
struct line {
  int l, r;
} t[MAXN];
int Max[MAXN] = {0};
int Min[MAXN] = {0};
int room[MAXN] = {0};
int vis[MAXN] = {0};
int fa[MAXN] = {0};
int b[MAXN] = {0};
int N;
int cnt = 0;
int flag = 0;
int ta[MAXN] = {0};
int getfa(int x) {
  if (fa[x] == x) return x;
  return fa[x] = getfa(fa[x]);
}
void merge(int x, int y) {
  if (getfa(x) == getfa(y)) {
    vis[fa[x]]++;
    return;
  }
  ta[1] = Max[fa[x]];
  ta[2] = Min[fa[x]];
  ta[3] = Max[fa[y]];
  ta[4] = Min[fa[y]];
  sort(ta + 1, ta + 1 + 4);
  Max[fa[y]] = ta[4];
  Min[fa[y]] = ta[3];
  vis[fa[y]] += vis[fa[x]];
  fa[fa[x]] = fa[y];
}
int find(int x) {
  int l = 1, r = cnt, mid;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (b[mid] < x) {
      l = mid + 1;
      continue;
    }
    if (b[mid] > x) {
      r = mid - 1;
      continue;
    }
    return mid;
  }
}
void prepare() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    scanf("%d %d", &t[i].l, &t[i].r);
    room[2 * i - 1] = t[i].l;
    room[2 * i] = t[i].r;
  }
  sort(room + 1, room + 1 + 2 * N);
  for (int i = 1; i <= 2 * N; i++) {
    if (i == 1 || room[i] != room[i - 1]) {
      b[++cnt] = room[i];
    }
  }
  for (int i = 1; i <= cnt; i++) {
    fa[i] = i;
    Max[i] = b[i];
    Min[i] = -1;
  }
  for (int i = 1; i <= N; i++) {
    merge(find(t[i].l), find(t[i].r));
  }
  int tt;
  int MM = 0;
  for (int i = 1; i <= cnt; i++) {
    tt = getfa(i);
    if (!vis[tt]) {
      MM = max(MM, Min[tt]);
    }
    if (vis[tt] == 1) {
      MM = max(MM, Max[tt]);
    }
    if (vis[tt] >= 2) {
      cout << -1 << endl;
      return;
    }
  }
  cout << MM << endl;
}
void solve() {}
int main() {
  prepare();
  solve();
  return 0;
}
