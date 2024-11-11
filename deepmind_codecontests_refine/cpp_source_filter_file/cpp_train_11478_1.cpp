#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 200005;
struct Seg {
  int l, r, tp;
} b[N];
int n;
ll t[N];
int f[N][2], pre[N][2];
vector<int> v[N][2];
char ans[N];
ll sum(int l, int r) { return (r - l) * (r - l + 1ll) / 2; }
bool check(ll s, int l, int r) {
  if (s <= 0) return !s && r - l + 1 >= 0;
  if (l > r) return 0;
  int tl = 1, tr = r - l + 1;
  while (tl <= tr) {
    int mid = (tl + tr) >> 1;
    if (sum(l, l + mid - 1) <= s)
      tl = mid + 1;
    else
      tr = mid - 1;
  }
  return sum(r - (tl - 1) + 1, r) >= s;
}
void calc(vector<int> &v, ll s, int l, int r) {
  if (!s) return;
  int tll = n - r + 1, tl = 1, tr = r - l + 1;
  while (tl <= tr) {
    int mid = (tl + tr) >> 1;
    if (sum(tll, tll + mid - 1) <= s)
      tl = mid + 1;
    else
      tr = mid - 1;
  }
  --tl;
  for (int i = r; i >= l && tl; --i)
    if (sum(n - i + 2, n - i + tl) <= s - n + i - 1 &&
        sum(n - l - tl + 3, n - l + 1) >= s - n + i - 1)
      --tl, s -= n - i + 1, v.push_back(i);
}
void upd(int x, int y, int ty, int pos) {
  if (f[x][y] != -1 && f[x][y] <= pos) return;
  f[x][y] = pos;
  pre[x][y] = ty;
  v[x][y].clear();
  v[x][y].push_back(pos);
  calc(v[x][y], t[b[x].r] + y - t[b[x - 1].r] - ty - n + pos - 1,
       f[x - 1][ty] + 1, b[x].l - 1);
}
int a[N], idxa, idx;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    if (t[i]) a[++idxa] = i;
  }
  if (!idxa) {
    for (int i = 1; i <= n; i++) cout << 0;
    return 0;
  }
  b[0] = {0, 0, 0};
  b[++idx] = {a[1], a[1], 0};
  for (int i = 2; i <= idxa; i++) {
    if (t[a[i]] == t[b[idx].r])
      b[idx].r = a[i], b[idx].tp = 1;
    else if (t[a[i]] == t[b[idx].r] - 1)
      b[idx].r = a[i], b[idx].tp = 2;
    else
      b[++idx] = {a[i], a[i], 0};
  }
  b[idx + 1] = {n + 2, n + 2, 0};
  f[0][0] = -1;
  f[0][1] = 0;
  for (int i = 1; i <= idx; i++) {
    f[i][0] = f[i][1] = -1;
    for (int j = 0; j < 2; j++) {
      if (f[i - 1][j] == -1) continue;
      if (b[i].tp == 0 || b[i].tp == 1) {
        ll tt = t[b[i].r] - t[b[i - 1].r] - j;
        int pos;
        for (pos = max(b[i].r + 1ll, n - tt + 1); pos < b[i + 1].l; pos++)
          if (check(tt - n + pos - 1, n - b[i].l + 2, n - f[i - 1][j])) break;
        if (pos < b[i + 1].l) upd(i, 0, j, pos);
      }
      if (b[i].tp == 0 || b[i].tp == 2) {
        ll tt = t[b[i].r] + 1 - t[b[i - 1].r] - j - n + b[i].r - 1;
        if (check(tt, n - b[i].l + 2, n - f[i - 1][j])) upd(i, 1, j, b[i].r);
      }
    }
  }
  if (f[idx][0] == -1 && f[idx][1] == -1 && b[idx].tp == 1) {
    for (int j = 0; j < 2; j++) {
      if (f[idx - 1][j] == -1) continue;
      ll tt = t[b[idx].r] - t[b[idx - 1].r] - j;
      int pos;
      for (pos = max(b[idx].l * 1ll, n - tt + 1); pos <= b[idx].r; pos++)
        if (!t[pos] &&
            check(tt - n + pos - 1, n - b[idx].l + 2, n - f[idx - 1][j]))
          break;
      if (pos <= b[idx].r) upd(idx, 0, j, pos);
    }
  }
  for (int i = 1; i <= n; i++) ans[i] = '0';
  int cur = f[idx][1] != -1;
  for (int i = idx; i > 0; --i) {
    for (int j = 0; j < int(v[i][cur].size()); j++) ans[v[i][cur][j]] = '1';
    cur = pre[i][cur];
  }
  ans[n + 1] = 0;
  cout << ans + 1 << endl;
  return 0;
}
