#include <bits/stdc++.h>
using namespace std;
class vec {
 public:
  int x, y;
  vec() { x = y = 0; }
  vec(int tx, int ty) { x = tx, y = ty; }
  vec operator-(const vec &t) const { return vec(x - t.x, y - t.y); }
  vec operator+(const vec &t) const { return vec(x + t.x, y + t.y); }
  long long operator*(const vec &t) const {
    return (long long)x * t.y - (long long)y * t.x;
  }
  long long operator^(const vec &t) const {
    return (long long)x * t.x + (long long)y * t.y;
  }
  bool operator<(const vec &t) const { return (*this) * t > 0; }
  bool operator==(const vec &t) const { return (*this) * t == 0; }
} v[500010];
vector<vec> lsa, lsb;
int idcnt, Q, opt[500010], x[500010], y[500010], R, alpha[500010], Beta[500010];
class delheap {
 public:
  priority_queue<int> A, B;
  void insert(int v) { A.push(v); }
  void erase(int v) { B.push(v); }
  int top() {
    while (!A.empty() && !B.empty() && A.top() == B.top()) A.pop(), B.pop();
    if (A.empty()) return -1e9;
    return A.top();
  }
};
class sgt {
 public:
  delheap q[500010];
  int mx[2000010];
  void build(int p, int l, int r) {
    mx[p] = -1e9;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build((p << 1), l, mid);
    build(((p << 1) | 1), mid + 1, r);
  }
  void modify(int p, int l, int r, int pos, int v, bool opt) {
    if (l == r) {
      if (opt)
        q[l].insert(v);
      else
        q[l].erase(v);
      mx[p] = q[l].top();
      return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
      modify((p << 1), l, mid, pos, v, opt);
    else
      modify(((p << 1) | 1), mid + 1, r, pos, v, opt);
    mx[p] = max(mx[(p << 1)], mx[((p << 1) | 1)]);
  }
  int query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return mx[p];
    int mid = (l + r) >> 1, ret = -1e9;
    if (ql <= mid) ret = query((p << 1), l, mid, ql, qr);
    if (qr > mid) ret = max(ret, query(((p << 1) | 1), mid + 1, r, ql, qr));
    return ret;
  }
} T;
int main() {
  scanf("%d%d", &R, &Q);
  for (int i = 1; i <= Q; i++) {
    scanf("%d%d", &opt[i], &x[i]);
    if (opt[i] == 1) {
      scanf("%d", &y[i]);
      v[++idcnt] = vec(x[i], y[i]);
      x[i] = idcnt;
    } else if (opt[i] == 3)
      scanf("%d", &y[i]);
  }
  vec lft(-R, 0), rgt(R, 0);
  for (int i = 1; i <= idcnt; i++) {
    lsa.push_back(v[i] - lft);
    lsb.push_back(v[i] - rgt);
  }
  sort(lsa.begin(), lsa.end());
  sort(lsb.begin(), lsb.end());
  lsa.erase(unique(lsa.begin(), lsa.end()), lsa.end());
  lsb.erase(unique(lsb.begin(), lsb.end()), lsb.end());
  T.build(1, 0, lsb.size() - 1);
  for (int i = 1; i <= idcnt; i++) {
    alpha[i] = lower_bound(lsa.begin(), lsa.end(), v[i] - lft) - lsa.begin();
    Beta[i] = lower_bound(lsb.begin(), lsb.end(), v[i] - rgt) - lsb.begin();
  }
  for (int i = 1; i <= Q; i++) {
    if (opt[i] == 1) {
      T.modify(1, 0, lsb.size() - 1, Beta[x[i]], alpha[x[i]], 1);
    } else if (opt[i] == 2) {
      T.modify(1, 0, lsb.size() - 1, Beta[x[i]], alpha[x[i]], 0);
    } else {
      int ta = min(alpha[x[i]], alpha[y[i]]), tb = max(Beta[x[i]], Beta[y[i]]);
      if (lsa[ta] * lsb[tb] < 0)
        puts("NO");
      else {
        T.modify(1, 0, lsb.size() - 1, Beta[x[i]], alpha[x[i]], 0);
        T.modify(1, 0, lsb.size() - 1, Beta[y[i]], alpha[y[i]], 0);
        if (T.query(1, 0, lsb.size() - 1, 0, tb) >= ta)
          puts("NO");
        else
          puts("YES");
        T.modify(1, 0, lsb.size() - 1, Beta[x[i]], alpha[x[i]], 1);
        T.modify(1, 0, lsb.size() - 1, Beta[y[i]], alpha[y[i]], 1);
      }
    }
  }
  return 0;
}
