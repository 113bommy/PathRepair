#include <bits/stdc++.h>
using namespace std;
struct Video {
  int l, r, len, i;
};
struct Channel {
  int a, b, c;
};
struct Node {
  int l, r, mx, i;
  Node() { l = r = mx = i = 0; }
};
const int N = 200005;
Video vid[N];
Channel cha[N];
int ptr, mxind[N], root[N];
Node tree[N * 20];
int update(int v, int l, int r, int ind, int len, int i) {
  int u = ptr++;
  if (l == r) {
    tree[u].l = tree[u].r = 0;
    if (tree[v].mx > len) {
      tree[u].mx = tree[v].mx;
      tree[u].i = tree[v].i;
    } else {
      tree[u].mx = len;
      tree[u].i = i;
    }
    return u;
  }
  int m = (l + r) / 2;
  if (ind <= m) {
    tree[u].l = update(tree[v].l, l, m, ind, len, i);
    tree[u].r = tree[v].r;
    if (tree[tree[u].l].mx > tree[tree[u].r].mx) {
      tree[u].mx = tree[tree[u].l].mx;
      tree[u].i = tree[tree[u].l].i;
    } else {
      tree[u].mx = tree[tree[u].r].mx;
      tree[u].i = tree[tree[u].r].i;
    }
  } else {
    tree[u].r = update(tree[v].r, m + 1, r, ind, len, i);
    tree[u].l = tree[v].l;
    if (tree[tree[u].l].mx > tree[tree[u].r].mx) {
      tree[u].mx = tree[tree[u].l].mx;
      tree[u].i = tree[tree[u].l].i;
    } else {
      tree[u].mx = tree[tree[u].r].mx;
      tree[u].i = tree[tree[u].r].i;
    }
  }
  return u;
}
pair<int, int> query(int v, int s, int e, int l, int r) {
  if (l <= s && e <= r) return {tree[v].mx, tree[v].i};
  int m = (s + e) / 2;
  if (r <= m) return query(tree[v].l, s, m, l, r);
  if (m < l) return query(tree[v].r, m + 1, e, l, r);
  return max(query(tree[v].l, s, m, l, r), query(tree[v].r, m + 1, e, l, r));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> vid[i].l >> vid[i].r;
    vid[i].len = vid[i].r - vid[i].l;
    vid[i].i = i;
  }
  for (int i = 1; i <= m; i++) {
    cin >> cha[i].a >> cha[i].b >> cha[i].c;
  }
  sort(vid + 1, vid + n + 1, [&](Video a, Video b) { return a.l < b.l; });
  for (int i = 1; i <= n; i++) {
    mxind[i] = i;
    if (i > 1) {
      if (vid[mxind[i - 1]].r > vid[i].r) {
        mxind[i] = mxind[i - 1];
      }
    }
  }
  long long ans = 0;
  int videoIndex = -1;
  int channelIndex = -1;
  for (int i = 1; i <= m; i++) {
    if (cha[i].a < vid[1].l) {
      continue;
    }
    int lo = 1, hi = n;
    while (lo < hi) {
      int mi = lo + (hi - lo + 1) / 2;
      if (vid[mi].l <= cha[i].a)
        lo = mi;
      else
        hi = mi - 1;
    }
    long long val =
        cha[i].c * 1LL * (min(cha[i].b, vid[mxind[lo]].r) - cha[i].a);
    if (val > ans) {
      ans = val;
      videoIndex = vid[mxind[lo]].i;
      channelIndex = i;
    }
  }
  sort(vid + 1, vid + n + 1, [&](Video a, Video b) { return a.r < b.r; });
  for (int i = n; i >= 1; i--) {
    mxind[i] = i;
    if (i < n) {
      if (vid[mxind[i + 1]].l < vid[i].l) {
        mxind[i] = mxind[i + 1];
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    if (vid[n].r < cha[i].b) {
      continue;
    }
    int lo = 1, hi = n;
    while (lo < hi) {
      int mi = lo + (hi - lo) / 2;
      if (cha[i].b <= vid[mi].r)
        hi = mi;
      else
        lo = mi + 1;
    }
    long long val =
        cha[i].c * 1LL * (cha[i].b - max(cha[i].a, vid[mxind[lo]].l));
    if (val > ans) {
      ans = val;
      videoIndex = vid[mxind[lo]].i;
      channelIndex = i;
    }
  }
  vector<int> indl, indr;
  for (int i = 1; i <= n; i++) {
    indl.push_back(vid[i].l);
  }
  sort(indl.begin(), indl.end());
  indl.resize(unique(indl.begin(), indl.end()) - indl.begin());
  int sz = indl.size();
  root[0] = 0;
  ptr = 1;
  for (int i = 1; i <= n; i++) {
    int ind =
        1 + (lower_bound(indl.begin(), indl.end(), vid[i].l) - indl.begin());
    root[i] = update(root[i - 1], 1, sz, ind, vid[i].len, vid[i].i);
  }
  for (int i = 1; i <= m; i++) {
    if (cha[i].b < vid[1].r) {
      continue;
    }
    int lo = 1, hi = n;
    while (lo < hi) {
      int mi = lo + (hi - lo + 1) / 2;
      if (vid[mi].r <= cha[i].b)
        lo = mi;
      else
        hi = mi - 1;
    }
    int ind =
        1 + (lower_bound(indl.begin(), indl.end(), cha[i].a) - indl.begin());
    if (ind > sz) continue;
    pair<int, int> tmp = query(root[lo], 1, sz, ind, sz);
    long long val = tmp.first * 1LL * cha[i].c;
    if (val > ans) {
      ans = val;
      videoIndex = tmp.second;
      channelIndex = i;
    }
  }
  cout << ans << '\n';
  if (ans != 0) cout << videoIndex << " " << channelIndex << '\n';
  return 0;
}
