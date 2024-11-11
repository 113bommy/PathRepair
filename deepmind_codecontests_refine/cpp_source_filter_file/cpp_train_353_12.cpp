#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n;
int u;
int seg[4 * maxn];
int lazy[4 * maxn];
int max1[4 * maxn];
int min1[4 * maxn];
int a[maxn];
int b[maxn];
int c[maxn];
int d[3 * maxn];
int w[3 * maxn];
int f[3 * maxn];
int a1[3 * maxn];
int b1[3 * maxn];
int c1[3 * maxn];
int cnt;
int s;
int m;
bool check;
vector<int> ans;
inline void compress();
inline void ans2();
inline void ans3();
inline void ok_w();
inline void ok_updseg();
inline void ok_forbuildseg();
void build(int v, int l, int r);
inline void ok_seg();
inline void ok_array();
void ok_ans();
int get(int v, int l, int r, int u, int t);
void update(int v, int l, int r, int k, int e, int val);
void shift();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  compress();
  ans2();
  ans3();
  ok_w();
  ok_updseg();
  ok_forbuildseg();
  build(1, 0, n);
  ok_ans();
  sort(ans.begin(), ans.end());
  cout << min(ans[0], m);
}
inline void compress() {
  for (int i = 0; i < n; i++) {
    d[i * 3] = a[i];
    d[i * 3 + 1] = b[i];
    d[i * 3 + 2] = c[i];
  }
  sort(d, d + 3 * n);
  u = unique(d, d + (3 * n)) - d;
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(d, d + u, a[i]) - d;
    b[i] = lower_bound(d, d + u, b[i]) - d;
    c[i] = lower_bound(d, d + u, c[i]) - d;
  }
  return;
}
inline void ans2() {
  for (int i = 0; i < n; i++) {
    if (f[a[i]] == 0) {
      cnt++;
    }
    if (cnt == u) {
      m = i + 1;
      cnt++;
    }
    f[a[i]]++;
  }
  fill(f, f + 3 * maxn, 0);
  cnt = 0;
  for (int i = 0; i < n; i++) {
    if (f[b[i]] == 0) {
      cnt++;
    }
    if (cnt == u) {
      if (m == 0) {
        m = i + 1;
        cnt++;
      } else {
        m = min(m, i + 1);
        cnt++;
      }
    }
    f[b[i]]++;
  }
  fill(f, f + 3 * maxn, 0);
  cnt = 0;
  for (int i = 0; i < n; i++) {
    if (f[c[i]] == 0) {
      cnt++;
    }
    if (cnt == u) {
      if (m == 0) {
        m = i + 1;
        cnt++;
      } else {
        m = min(m, i + 1);
        cnt++;
      }
    }
    f[c[i]]++;
  }
  if (m == 0) {
    m = 3 * n + 1;
  }
  fill(f, f + 3 * maxn, 0);
  cnt = 0;
}
inline void ans3() {
  for (int i = 0; i < n; i++) {
    if (f[a[i]] == 0) {
      cnt++;
    }
    f[a[i]]++;
  }
  int j = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (; j < n && cnt != u; j++) {
      if (f[c[j]] == 0) {
        cnt++;
      }
      f[c[j]]++;
    }
    if (cnt == u) {
      m = min(i + 1 + j + 1, m);
    }
    if (f[a[i]] == 1) {
      cnt--;
    }
    f[a[i]]--;
  }
  fill(f, f + 3 * maxn, 0);
  cnt = 0;
}
inline void ok_w() {
  for (int i = 0; i < n; i++) {
    w[a[i]]++;
    if (w[a[i]] == 1) {
      cnt++;
    }
  }
}
inline void ok_updseg() {
  fill(a1, a1 + 3 * maxn, -1);
  fill(b1, b1 + 3 * maxn, -1);
  fill(c1, c1 + 3 * maxn, -1);
  for (int i = 0; i < n; i++) {
    if (f[a[i]] == 0) {
      a1[a[i]] = i;
      f[a[i]]++;
    }
  }
  fill(f, f + 3 * maxn, 0);
  for (int i = 0; i < n; i++) {
    if (f[b[i]] == 0) {
      b1[b[i]] = i;
      f[b[i]]++;
    }
  }
  fill(f, f + 3 * maxn, 0);
  for (int i = 0; i < n; i++) {
    if (f[c[i]] == 0) {
      c1[c[i]] = i;
      f[c[i]]++;
    }
  }
  return;
}
inline void ok_forbuildseg() {
  fill(f, f + 3 * maxn, 0);
  for (int i = 0; i < n; i++) {
    if (w[b[i]] == 0) {
      w[b[i]]++;
      cnt++;
    } else {
      w[b[i]]++;
    }
  }
  int j = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (; j < n && cnt != u; j++) {
      if (w[c[j]] == 0) {
        cnt++;
        w[c[j]]++;
      } else {
        w[c[j]]++;
      }
    }
    if (cnt != u) {
      s = max(s, i + 1);
    }
    f[i] = j - 1;
    if (cnt == u) {
      ans.emplace_back(f[i] + 1 + n + i + 1);
    }
    if (i >= 0) {
      if (w[b[i]] == 1) {
        cnt--;
      }
      w[b[i]]--;
    }
  }
}
void build(int v, int l, int r) {
  if (r - l == 1) {
    seg[v] = (r + f[l] + 1);
    max1[v] = f[l] + 1;
    min1[v] = f[l] + 1;
    return;
  }
  int mid = l + r;
  mid /= 2;
  build((v << 1), l, mid);
  build((v << 1) + 1, mid, r);
  min1[v] = min(min1[(v << 1)], min1[(v << 1) + 1]);
  max1[v] = max(max1[v << 1], max1[(v << 1) + 1]);
  seg[v] = min(seg[v << 1], seg[(v << 1) + 1]);
  return;
}
inline void ok_array(int v) {
  if (c1[v] == -1 && b1[v] == -1) {
    check = true;
  } else if (c1[v] == -1) {
    s = max(s, b1[v]);
  } else if (b1[v] == -1) {
    update(1, 0, n, s, n, c1[v]);
  } else {
    if (s <= b1[v]) {
      update(1, 0, n, s, b1[v], c1[v]);
    }
  }
  return;
}
void ok_ans() {
  fill(lazy, lazy + 4 * maxn, -1);
  for (int i = n - 1; i >= 0; i--) {
    if (a1[a[i]] == i) {
      w[a[i]]--;
      ok_array(a[i]);
    } else {
      w[a[i]]--;
    }
    if (check == false) {
      ans.emplace_back(get(1, 0, n, s, n) + i);
    }
  }
}
void shift(int v, int l, int r) {
  if (lazy[v] != -1) {
    lazy[v << 1] = lazy[v];
    lazy[(v << 1) + 1] = lazy[v];
    seg[(v << 1)] = l + 1 + lazy[v];
    seg[(v << 1) + 1] = (l + r) / 2 + 1 + lazy[v];
    min1[v << 1] = lazy[v];
    min1[(v << 1) + 1] = lazy[v];
    max1[v << 1] = lazy[v];
    max1[(v << 1) + 1] = lazy[v];
    lazy[v] = -1;
    return;
  }
  return;
}
int get(int v, int l, int r, int u, int t) {
  if (u <= l && r <= t) {
    shift(v, l, r);
    return seg[v];
  }
  if (l >= t || r <= u) {
    shift(v, l, r);
    return 10000000;
  }
  shift(v, l, r);
  min1[v] = min(min1[(v << 1)], min1[(v << 1) + 1]);
  max1[v] = max(max1[v << 1], max1[(v << 1) + 1]);
  seg[v] = min(seg[v << 1], seg[(v << 1) + 1]);
  return min(get(v << 1, l, (l + r) >> 1, u, t),
             get((v << 1) + 1, (l + r) >> 1, r, u, t));
}
void update(int v, int l, int r, int k, int t, int val) {
  if (max1[v] == min1[v] && max1[v] < val + 1 && k <= l && r <= t) {
    shift(v, l, r);
    seg[v] = val + l + 2;
    lazy[v] = val + 1;
    min1[v] = val + 1;
    max1[v] = val + 1;
    return;
  }
  if (min1[v] >= val + 1 || (r <= k || t <= l)) {
    shift(v, l, r);
    return;
  }
  shift(v, l, r);
  int mid = l + r;
  mid /= 2;
  update(v << 1, l, mid, k, t, val);
  update((v << 1) + 1, mid, r, k, t, val);
  min1[v] = min(min1[(v << 1)], min1[(v << 1) + 1]);
  max1[v] = max(max1[v << 1], max1[(v << 1) + 1]);
  seg[v] = min(seg[v << 1], seg[(v << 1) + 1]);
  return;
}
