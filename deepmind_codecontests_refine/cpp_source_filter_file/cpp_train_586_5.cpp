#include <bits/stdc++.h>
namespace LCP {
namespace SA {
int sa[1000000 + 5];
int rk[1000000 + 5], ht[1000000 + 5];
template <typename T>
void init(T s[], int n, int m) {
  static int t1[1000000 + 5], t2[1000000 + 5], c[1000000 + 5];
  int *x = t1, *y = t2;
  for (int i = 0; i < m; ++i) c[i] = 0;
  for (int i = 0; i < n; ++i) c[x[i] = s[i]]++;
  for (int i = 1; i < m; ++i) c[i] += c[i - 1];
  for (int i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i;
  for (int j = 1; j <= n; j <<= 1) {
    int p = 0;
    for (int i = n - j; i < n; ++i) y[p++] = i;
    for (int i = 0; i < n; ++i) {
      if (sa[i] >= j) y[p++] = sa[i] - j;
    }
    for (int i = 0; i < m; ++i) c[i] = 0;
    for (int i = 0; i < n; ++i) c[x[y[i]]]++;
    for (int i = 1; i < m; ++i) c[i] += c[i - 1];
    for (int i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
    std::swap(x, y);
    p = 1;
    x[sa[0]] = 0;
    for (int i = 1; i < n; ++i)
      x[sa[i]] = (y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + j] == y[sa[i] + j])
                     ? p - 1
                     : p++;
    if (p >= n) break;
    m = p;
  }
}
template <typename T>
void get_height(T s[], int n) {
  int k = 0;
  for (int i = 0; i < n; i++) rk[sa[i]] = i;
  for (int i = 0; i < n; i++) {
    if (k) --k;
    if (rk[i] == 0)
      ht[rk[i]] = 0;
    else {
      int j = sa[rk[i] - 1];
      while (s[i + k] == s[j + k]) ++k;
      ht[rk[i]] = k;
    }
  }
}
}  // namespace SA
template <typename T, typename Comparer, size_t MaxN>
class st_table {
  T dp[MaxN][32];
  Comparer comp;
  int n;

 public:
  st_table(Comparer _comp = Comparer()) : comp(_comp) {}
  void init(const T* array, int n) {
    this->n = n;
    for (int i = 0; i < n; ++i) dp[i][0] = array[i];
    for (int j = 1; (1 << j) <= n; ++j) {
      for (int i = 0; i + (1 << j) - 1 < n; ++i)
        dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1], comp);
    }
  }
  T query(int left, int right) const {
    int k = 8 * sizeof(int) - __builtin_clz(right - left + 1) - 1;
    return min(dp[left][k], dp[right - (1 << k) + 1][k], comp);
  }
};
template <typename T, size_t MaxN>
using st_table_min = st_table<T, std::less<int>, MaxN>;
st_table_min<int, 1000005> rmq;
void init(const char* s, int len) {
  SA::init(s, len + 1, 256);
  SA::get_height(s, len);
  rmq.init(SA::ht, len);
}
int query(int suf1, int suf2) {
  assert(suf1 != suf2);
  if (SA::rk[suf1] > SA::rk[suf2]) std::swap(suf1, suf2);
  return rmq.query(SA::rk[suf1] + 1, SA::rk[suf2]);
}
}  // namespace LCP
class segment_tree {
  int val[1000005 * 4];
  bool lazy[1000005 * 4];
  void lazy_pushdown(int segp) {
    if (lazy[segp]) {
      int lchild = ((segp) << 1);
      int rchild = (((segp) << 1) | 1);
      val[lchild] = std::max(val[lchild], val[segp]);
      val[rchild] = std::max(val[rchild], val[segp]);
      lazy[lchild] = lazy[rchild] = true;
      lazy[segp] = false;
    }
  }

 public:
  void init(int segleft, int segright, int segp) {
    val[segp] = -1;
    lazy[segp] = false;
    if (segleft != segright) {
      int mid = (segleft + segright) / 2;
      init(segleft, mid, ((segp) << 1));
      init(mid + 1, segright, (((segp) << 1) | 1));
    }
  }
  void update(int left, int right, int value, int segleft, int segright,
              int segp) {
    if (left == segleft && right == segright) {
      val[segp] = std::max(val[segp], value);
      lazy[segp] = true;
    } else {
      lazy_pushdown(segp);
      int mid = (segleft + segright) / 2;
      if (right <= mid)
        update(left, right, value, segleft, mid, ((segp) << 1));
      else if (left > mid)
        update(left, right, value, mid + 1, segright, (((segp) << 1) | 1));
      else {
        update(left, mid, value, segleft, mid, ((segp) << 1));
        update(mid + 1, right, value, mid + 1, segright, (((segp) << 1) | 1));
      }
    }
  }
  template <typename CallbackT>
  void collect(int left, int right, CallbackT callback, int segleft,
               int segright, int segp) {
    if (segleft == segright)
      callback(segleft, val[segp]);
    else {
      lazy_pushdown(segp);
      int mid = (segleft + segright) / 2;
      if (right <= mid)
        collect(left, right, callback, segleft, mid, ((segp) << 1));
      else if (left > mid)
        collect(left, right, callback, mid + 1, segright, (((segp) << 1) | 1));
      else {
        collect(left, mid, callback, segleft, mid, ((segp) << 1));
        collect(mid + 1, right, callback, mid + 1, segright,
                (((segp) << 1) | 1));
      }
    }
  }
};
char s[1000005];
int after[500005], before[500005];
segment_tree segtree;
int n;
int main(int argc, char* argv[]) {
  scanf("%d", &n);
  scanf("%s", s);
  int half = (n - 1) / 2;
  LCP::init(s, n);
  for (int i = 0; i <= half; ++i) {
    int mir = n - i - 1;
    if (i == mir) continue;
    after[i] = LCP::query(i, mir);
  }
  std::reverse(s, s + n);
  LCP::init(s, n);
  for (int i = 0; i <= half; ++i) {
    int mir = n - i - 1;
    if (i == mir) continue;
    before[i] = LCP::query(i, mir);
  }
  segtree.init(1, n, 1);
  for (int i = 0; i <= half; ++i) {
    int r = std::min(before[i], after[i]);
    if (r == 0) continue;
    assert(i - r + 1 >= 0);
    segtree.update(i - r + 1 + 1, i + 1, i + 1, 1, n, 1);
  }
  segtree.collect(
      1, half + 1,
      [](int pos, int value) {
        int len = -1;
        if (value != -1) {
          assert(value >= pos);
          len = (value - pos + 1) * 2 - 1;
        }
        printf("%d ", len);
      },
      1, n, 1);
  printf("\n");
  return 0;
}
