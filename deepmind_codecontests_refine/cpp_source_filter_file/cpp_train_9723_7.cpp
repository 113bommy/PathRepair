#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005, maxk = maxn << 2;
int n, nums, tot, tott;
int num[maxn << 1], opt[maxn], xx[maxn], yy[maxn], f[maxn], L[maxn], R[maxn];
int lc[maxk], rc[maxk];
vector<int> pos[maxk];
map<int, int> mp;
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
void build(int l, int r, int now) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  lc[now] = now << 1, rc[now] = now << 1 | 1;
  build(l, mid, lc[now]), build(mid + 1, r, rc[now]);
}
void modify(int l, int r, int now, int posi, int p) {
  if (pos[now].size() > 0) {
    for (int i = 0; i < pos[now].size(); i++) {
      int x = find(pos[now][i]);
      f[x] = p, L[p] = min(L[p], L[x]), R[p] = max(R[p], R[x]);
    }
    pos[now].clear(), pos[now].push_back(p);
  }
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (posi <= mid)
    modify(l, mid, lc[now], posi, p);
  else
    modify(mid + 1, r, rc[now], posi, p);
}
void update(int l, int r, int now, int L, int R, int p) {
  if (L <= l && r <= R) {
    pos[now].push_back(p);
    return;
  }
  int mid = (l + r) >> 1;
  if (L <= mid) update(l, mid, lc[now], L, R, p);
  if (mid < R) update(mid + 1, r, rc[now], L, R, p);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &opt[i], &xx[i], &yy[i]);
    if (opt[i] == 1) num[++nums] = xx[i], num[++nums] = yy[i];
  }
  sort(num + 1, num + 1 + nums);
  for (int i = 1; i <= nums; i++)
    if (i == 1 || num[i] != num[i - 1]) mp[num[i]] = ++tot;
  build(1, n, 1);
  for (int i = 1; i <= n; i++) {
    if (opt[i] == 1) {
      int x = mp[xx[i]], y = mp[yy[i]];
      tott++, f[tott] = tott, L[tott] = x, R[tott] = y;
      modify(1, tot, 1, x, tott), modify(1, tot, 1, y, tott);
      if (x + 1 <= y - 1) update(1, tot, 1, x + 1, y - 1, tott);
    }
    if (opt[i] == 2) {
      int a = find(xx[i]), b = find(yy[i]);
      if (a == b || (L[b] < L[a] && L[a] < R[b]) ||
          (L[b] < R[a] && R[a] < R[b]))
        puts("YES");
      else
        puts("NO");
    }
  }
  return 0;
}
