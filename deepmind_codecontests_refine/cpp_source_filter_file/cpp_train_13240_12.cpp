#include <bits/stdc++.h>
using namespace std;
template <typename T>
class SegmentTreeMin {
 public:
  inline T MinValue(T val1, T val2) { return min(val1, val2); }
  inline void Push(int v) {
    if (set_data[v] != -inf_value) {
      tree_data[v << 1] = tree_data[(v << 1) | 1] = set_data[v] + add_data[v];
      set_data[v << 1] = set_data[(v << 1) | 1] = set_data[v];
      add_data[v << 1] = add_data[(v << 1) | 1] = add_data[v];
      set_data[v] = -inf_value;
      add_data[v] = T{};
    } else {
      if (add_data[v] != T{}) {
        tree_data[v << 1] += add_data[v];
        tree_data[(v << 1) | 1] += add_data[v];
        add_data[v << 1] += add_data[v];
        add_data[(v << 1) | 1] += add_data[v];
        add_data[v] = T{};
      }
    }
  }
  T UpdateRange(int v, int tl, int tr, int l, int r, T new_val) {
    if (l > r) {
      return tree_data[v];
    }
    if (l == tl && tr == r) {
      set_data[v] = new_val;
      add_data[v] = T{};
      return tree_data[v] = new_val;
    } else {
      Push(v);
      int tm = (tl + tr) >> 1;
      T left_val = UpdateRange(v << 1, tl, tm, l, min(r, tm), new_val);
      T right_val =
          UpdateRange((v << 1) | 1, tm + 1, tr, max(l, tm + 1), r, new_val);
      return tree_data[v] = MinValue(left_val, right_val);
    }
  }
  inline void UpdateRange(int l, int r, T new_val) {
    UpdateRange(1, 0, n - 1, l, r, new_val);
  }
  inline void Update(int ind, T new_val) {
    UpdateRange(1, 0, n - 1, ind, ind, new_val);
  }
  T AddRange(int v, int tl, int tr, int l, int r, T add_val) {
    if (l > r) {
      return tree_data[v];
    }
    if (l == tl && tr == r) {
      add_data[v] += add_val;
      tree_data[v] += add_val;
      return tree_data[v];
    } else {
      Push(v);
      int tm = (tl + tr) >> 1;
      T left_val = AddRange(v << 1, tl, tm, l, min(r, tm), add_val);
      T right_val =
          AddRange((v << 1) | 1, tm + 1, tr, max(l, tm + 1), r, add_val);
      return tree_data[v] = MinValue(left_val, right_val);
    }
  }
  inline void AddRange(int l, int r, T add_val) {
    AddRange(1, 0, n - 1, l, r, add_val);
  }
  inline void Add(int ind, T add_val) {
    AddRange(1, 0, n - 1, ind, ind, add_val);
  }
  T GetMin(int v, int tl, int tr, int l, int r) {
    if (l > r) {
      return inf_value;
    }
    if (l == tl && r == tr) {
      return tree_data[v];
    }
    int tm = (tl + tr) >> 1;
    return MinValue(GetMin(v << 1, tl, tm, l, min(r, tm)),
                    GetMin((v << 1) | 1, tm + 1, tr, max(l, tm + 1), r));
  }
  inline T GetMin(int l, int r) { return GetMin(1, 0, n - 1, l, r); }
  inline void SetInf(T new_inf_value) { inf_value = new_inf_value; }
  inline void Assign(int new_n, T value) {
    n = new_n;
    tree_data.assign(n << 2, value);
    set_data.assign(n << 2, -inf_value);
    add_data.assign(n << 2, T{});
  }
  inline void Resize(int new_n) {
    n = new_n;
    tree_data.assign(n << 2, inf_value);
    set_data.assign(n << 2, -inf_value);
    add_data.assign(n << 2, T{});
  }
  inline void Clear() {
    n = 0;
    tree_data.clear();
    set_data.clear();
    add_data.clear();
  }
  inline SegmentTreeMin() {
    n = 0;
    SetInf(numeric_limits<T>::max());
  }
  inline SegmentTreeMin(int new_n) {
    SetInf(numeric_limits<T>::max());
    Resize(new_n);
  }
  inline SegmentTreeMin(int new_n, T init_value) {
    SetInf(numeric_limits<T>::max());
    Assign(new_n, init_value);
  }
  int n;
  T inf_value;
  vector<T> tree_data;
  vector<T> set_data;
  vector<T> add_data;
};
int n;
vector<int> a;
vector<int> unmap;
SegmentTreeMin<int> t;
int s;
inline void init() {
  scanf("%d", &n);
  t.Assign(n << 1, n);
  a.resize(n << 1);
  unmap.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];
    unmap[a[i]] = i;
    if (!a[i]) {
      s = i;
    }
  }
  for (int i = 0; i < (n << 1); ++i) {
    if (i >= n) {
      a[i] = a[i - n];
    }
    t.Update(i, a[i]);
  }
}
pair<pair<int, int>, int> q[1 << 20];
inline int att(int l, int r) {
  if (l > r) {
    return 0;
  }
  if (l < 0) {
    l += n;
    r += n;
  }
  int res = 0;
  int k = 0;
  int m = 0;
  int lvl = 0;
  int ll = 0;
  int rr = 0;
  q[k++] = pair<pair<int, int>, int>(pair<int, int>(l, r), 1);
  for (int i = 0; i < k; ++i) {
    ll = q[i].first.first;
    rr = q[i].first.second;
    lvl = q[i].second;
    res = max(res, lvl);
    ++lvl;
    if (ll != rr) {
      m = t.GetMin(ll, rr);
      m = unmap[m];
      if (m < ll) {
        m += n;
      }
      if (ll < m) {
        q[k++] = pair<pair<int, int>, int>(pair<int, int>(ll, m - 1), lvl);
      }
      if (rr > m) {
        q[k++] = pair<pair<int, int>, int>(pair<int, int>(m + 1, rr), lvl);
      }
    }
  }
  return res + 1;
}
inline int check(int lim) {
  int l = 0, r = n - 1;
  int cur = 0, cur2 = 0, mid = 0, lft = 0, rgt = 0;
  while (l <= r) {
    mid = (l + r) >> 1;
    lft = s - mid;
    rgt = s - 1;
    cur = att(lft, rgt);
    if (cur > lim) {
      r = mid - 1;
    } else {
      lft = s + 1;
      rgt = s + (n - mid - 1);
      cur2 = att(lft, rgt);
      if (cur2 <= lim) {
        return (n - mid) % n;
      }
      l = mid + 1;
    }
  }
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  init();
  if (n == 1) {
    printf("1 0\n");
    return 0;
  }
  int res = n, shift = 0;
  int l = 2, r = n - 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    int cur = check(mid);
    if (cur != -1) {
      res = mid;
      shift = cur;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  printf("%d %d\n", res, shift);
  return 0;
}
