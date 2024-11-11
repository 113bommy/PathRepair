#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
const int magic = 321;
int n, ar[N], max1[magic], cnt[magic][N], grp[N], off[magic], head[N],
    idx[magic][N];
int ceil(int x, int y) { return (x + y - 1) / y; }
int lef(int x) { return (x - 1) * magic + 1; }
int rig(int x) { return min(x * magic, n); }
int findd(int x) {
  if (head[x] < 0) {
    return x;
  }
  int y = findd(head[x]);
  head[x] = y;
  return y;
}
void unionn(int x, int y) { head[y] = x; }
void change1(int l, int r, int val) {
  int i;
  max1[grp[l]] = 0;
  for (i = lef(grp[l]); i <= rig(grp[l]); i++) {
    ar[i] = -head[findd(i)];
    cnt[grp[i]][ar[i]] = 0;
    idx[grp[i]][ar[i]] = 0;
    if (i >= l && i <= r && ar[i] - off[grp[i]] > val) {
      ar[i] -= val;
    }
    max1[grp[i]] = max(max1[grp[i]], ar[i]);
  }
  for (i = lef(grp[l]); i <= rig(grp[l]); i++) {
    head[i] = -ar[i];
    cnt[grp[i]][ar[i]]++;
    if (idx[grp[i]][ar[i]]) {
      unionn(idx[grp[i]][ar[i]], i);
    } else {
      idx[grp[i]][ar[i]] = i;
    }
  }
}
void change(int l, int r, int val) {
  int i, j;
  if (grp[l] == grp[r]) {
    change1(l, r, val);
    return;
  }
  change1(l, rig(grp[l]), val);
  change1(lef(grp[r]), r, val);
  for (i = grp[l] + 1; i < grp[r]; i++) {
    if (2 * val > max1[i] - off[i]) {
      for (j = val + 1 + off[i]; j <= max1[i]; j++) {
        if (idx[i][j]) {
          if (!idx[i][j - val]) {
            idx[i][j - val] = idx[i][j];
            head[idx[i][j]] = -(j - val);
          } else {
            unionn(idx[i][j - val], idx[i][j]);
          }
          cnt[i][j - val] += cnt[i][j];
          idx[i][j] = cnt[i][j] = 0;
        }
      }
      while (!idx[i][max1[i]]) {
        max1[i]--;
      }
    } else {
      for (j = off[i] + 1; j <= off[i] + val; j++) {
        if (idx[i][j]) {
          if (!idx[i][j + val]) {
            idx[i][j + val] = idx[i][j];
            head[idx[i][j]] = -(j + val);
          } else {
            unionn(idx[i][j + val], idx[i][j]);
          }
          cnt[i][j + val] += cnt[i][j];
          idx[i][j] = cnt[i][j] = 0;
        }
      }
      off[i] += val;
    }
  }
}
int take_ans(int l, int r, int val) {
  int i, ans = 0;
  if (grp[l] == grp[r]) {
    for (i = l; i <= r; i++) {
      if (-head[findd(i)] + off[grp[i]] == val) {
        ans++;
      }
    }
    return ans;
  }
  for (i = l; i <= rig(grp[l]); i++) {
    if (-head[findd(i)] + off[grp[l]] == val) {
      ans++;
    }
  }
  for (i = lef(grp[r]); i <= r; i++) {
    if (-head[findd(i)] + off[grp[r]] == val) {
      ans++;
    }
  }
  for (i = grp[l] + 1; i < grp[r]; i++) {
    if (val + off[i] < N - 1) {
      ans += cnt[i][val + off[i]];
    }
  }
  return ans;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m, i, j, k, l, x;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    cin >> ar[i];
    grp[i] = ceil(i, magic);
    cnt[grp[i]][ar[i]]++;
    head[i] = -ar[i];
    max1[grp[i]] = max(max1[grp[i]], ar[i]);
    if (idx[grp[i]][ar[i]]) {
      unionn(idx[grp[i]][ar[i]], i);
    } else {
      idx[grp[i]][ar[i]] = i;
    }
  }
  for (i = 1; i <= m; i++) {
    cin >> j >> k >> l >> x;
    if (j == 1) {
      change(k, l, x);
    } else {
      cout << take_ans(k, l, x) << '\n';
    }
  }
}
