#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, sa[N], rk[N], ht[N], cnt[N], f[N];
int tmp1[N << 1], tmp2[N << 1], lg[N];
char s[N];
struct segment_tree {
  int o[N << 2];
  void Update(int rt) { o[rt] = max(o[rt << 1], o[rt << 1 | 1]); }
  void Build(int l, int r, int rt) {
    if (l == r) {
      o[rt] = -1;
      return;
    }
    int mid = l + r >> 1;
    Build(l, mid, rt << 1);
    Build(mid + 1, r, rt << 1 | 1);
    Update(rt);
  }
  int Query(int l, int r, int rt, int ql, int qr) {
    if (ql <= l && r <= qr) {
      return o[rt];
    }
    int mid = l + r >> 1, res = -1;
    if (ql <= mid) {
      res = max(res, Query(l, mid, rt << 1, ql, qr));
    }
    if (qr > mid) {
      res = max(res, Query(mid + 1, r, rt << 1 | 1, ql, qr));
    }
    return res;
  }
  void Modify(int l, int r, int rt, int p, int v) {
    if (l == r) {
      o[rt] = v;
      return;
    }
    int mid = l + r >> 1;
    if (p <= mid) {
      Modify(l, mid, rt << 1, p, v);
    } else {
      Modify(mid + 1, r, rt << 1 | 1, p, v);
    }
    Update(rt);
  }
} sgt;
struct sparse_table {
  int o[N][20];
  void Build() {
    for (int i = 1; i <= n; i++) {
      o[i][0] = i;
    }
    for (int k = 1; (1 << k) <= n; k++) {
      for (int i = 1; i + (1 << k) - 1 <= n; i++) {
        int a = o[i][k - 1], b = o[i + (1 << k - 1)][k - 1];
        o[i][k] = ht[a] < ht[b] ? a : b;
      }
    }
  }
  int Query(int l, int r) {
    int k = lg[r - l + 1];
    int a = o[l][k], b = o[r - (1 << k) + 1][k];
    return ht[a] < ht[b] ? a : b;
  }
} st;
void BuildSA() {
  int *x = tmp1, *y = tmp2, m = N - 1;
  fill(cnt, cnt + m + 1, 0);
  for (int i = 1; i <= n; i++) {
    cnt[x[i] = s[i] - 'a' + 1]++;
  }
  for (int i = 1; i <= m; i++) {
    cnt[i] += cnt[i - 1];
  }
  for (int i = n; i; i--) {
    sa[cnt[x[i]]--] = i;
  }
  for (int k = 1; k <= n; k <<= 1) {
    int p = 0;
    for (int i = n - k + 1; i <= n; i++) {
      y[++p] = i;
    }
    for (int i = 1; i <= n; i++) {
      if (sa[i] > k) {
        y[++p] = sa[i] - k;
      }
    }
    fill(cnt, cnt + m + 1, 0);
    for (int i = 1; i <= n; i++) {
      cnt[x[y[i]]]++;
    }
    for (int i = 1; i <= m; i++) {
      cnt[i] += cnt[i - 1];
    }
    for (int i = n; i; i--) {
      sa[cnt[x[y[i]]]--] = y[i];
    }
    swap(x, y);
    x[sa[1]] = 1;
    for (int i = 2; i <= n; i++) {
      x[sa[i]] = x[sa[i - 1]] +
                 (y[sa[i]] != y[sa[i - 1]] || y[sa[i] + k] != y[sa[i - 1] + k]);
    }
    m = x[sa[n]];
    if (m == n) {
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    rk[sa[i]] = i;
  }
}
void BuildHeight() {
  for (int i = 1, h = 0; i <= n; i++) {
    if (h) {
      h--;
    }
    while (s[i + h] == s[sa[rk[i] - 1] + h]) {
      h++;
    }
    ht[rk[i]] = h;
  }
}
pair<int, int> Get(int p, int k) {
  int L, R, lb, rb;
  lb = 1;
  rb = p;
  while (lb < rb) {
    int mid = lb + rb >> 1;
    int u = st.Query(mid + 1, p);
    if (ht[u] >= k) {
      rb = mid;
    } else {
      lb = mid + 1;
    }
  }
  L = rb;
  lb = p;
  rb = n;
  while (lb < rb) {
    int mid = lb + rb + 1 >> 1;
    int u = st.Query(p + 1, mid);
    if (ht[u] >= k) {
      lb = mid;
    } else {
      rb = mid - 1;
    }
  }
  R = lb;
  return make_pair(L, R);
}
int main() {
  cin >> n >> (s + 1);
  lg[1] = 0;
  for (int i = 2; i <= n; i++) {
    lg[i] = lg[i >> 1] + 1;
  }
  BuildSA();
  BuildHeight();
  sgt.Build(1, n, 1);
  st.Build();
  f[n] = 1;
  int j = n;
  pair<int, int> rng;
  for (int i = n - 1; i; i--) {
    int k = f[i + 1] + 1;
    while (1) {
      while (j >= i + k) {
        sgt.Modify(1, n, 1, rk[j], f[j]);
        j--;
      }
      rng = Get(rk[i], k - 1);
      if (sgt.Query(1, n, 1, rng.first, rng.second) >= k - 1) {
        break;
      }
      rng = Get(rk[i + 1], k - 1);
      if (sgt.Query(1, n, 1, rng.first, rng.second) >= k - 1) {
        break;
      }
      k--;
    }
    f[i] = k;
  }
  cout << *max_element(f + 1, f + n + 1) << endl;
  return 0;
}
