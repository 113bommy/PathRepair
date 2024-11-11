#include <bits/stdc++.h>
inline long long rd() {
  long long _x = 0;
  int _ch = getchar(), _f = 1;
  for (; !isdigit(_ch) && (_ch != '-') && (_ch != EOF); _ch = getchar())
    ;
  if (_ch == '-') {
    _f = 0;
    _ch = getchar();
  }
  for (; isdigit(_ch); _ch = getchar()) _x = _x * 10 + _ch - '0';
  return _f ? _x : -_x;
}
void write(long long _x) {
  if (_x >= 10)
    write(_x / 10), putchar(_x % 10 + '0');
  else
    putchar(_x + '0');
}
inline void wrt(long long _x, char _p) {
  if (_x < 0) putchar('-'), _x = -_x;
  write(_x);
  if (_p) putchar(_p);
}
struct node {
  std::vector<std::pair<int, int> > v;
  std::pair<int, int> operator[](const int x) { return v[x]; }
  int size() { return v.size(); }
} tr[150005 << 2];
int n, m, p;
int tag[150005 << 2];
inline node operator+(node A, node B) {
  node ans = B;
  for (int i = 0; i < A.size(); i++) {
    bool flag = 0;
    for (int j = 0; j < B.size(); j++)
      if (A[i].first == B[j].first) {
        ans.v[j].second += A[i].second;
        flag = 1;
      }
    if (flag) continue;
    if (A.size() < p) {
      ans.v.push_back(A[i]);
      continue;
    }
    int t = 0;
    for (int j = 1; j < ans.size(); j++)
      if (ans[j].second < ans[t].second) t = j;
    if (ans[t].second < A[i].second) std::swap(ans.v[t], A.v[i]);
    for (int j = 0; j < ans.size(); j++) ans.v[j].second -= A[i].second;
  }
  return ans;
}
void pushdown(int pos, int l, int r) {
  if (!tag[pos]) return;
  int mid = (l + r) >> 1;
  tag[pos << 1 | 1] = tag[pos << 1] = tag[pos];
  tr[pos << 1] = {{std::make_pair(tag[pos], mid - l + 1)}};
  tr[pos << 1 | 1] = {{std::make_pair(tag[pos], r - mid)}};
  tag[pos] = 0;
}
int a[150005];
void build(int pos, int l, int r) {
  if (l == r) {
    tr[pos] = {{std::make_pair(a[l], 1)}};
    return;
  }
  int mid = (l + r) >> 1;
  build(pos << 1, l, mid), build(pos << 1 | 1, mid + 1, r);
  tr[pos] = tr[pos << 1] + tr[pos << 1 | 1];
}
void update(int pos, int l, int r, int ql, int qr, int x) {
  if (r < ql || l > qr) return;
  if (ql <= l && r <= qr) {
    tr[pos] = {{std::make_pair(x, r - l + 1)}};
    tag[pos] = x;
    return;
  }
  pushdown(pos, l, r);
  int mid = (l + r) >> 1;
  update(pos << 1, l, mid, ql, qr, x);
  update(pos << 1 | 1, mid + 1, r, ql, qr, x);
  tr[pos] = tr[pos << 1] + tr[pos << 1 | 1];
}
node query(int pos, int l, int r, int ql, int qr) {
  if (r < ql || l > qr) return {{}};
  if (ql <= l && r <= qr) return tr[pos];
  pushdown(pos, l, r);
  int mid = (l + r) >> 1;
  return query(pos << 1, l, mid, ql, qr) +
         query(pos << 1 | 1, mid + 1, r, ql, qr);
}
int main() {
  n = rd(), m = rd(), p = 100 / rd();
  for (int i = 1; i <= n; i++) a[i] = rd();
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int op = rd(), l = rd(), r = rd();
    if (op == 1) {
      int id = rd();
      update(1, 1, n, l, r, id);
    } else {
      node x = query(1, 1, n, l, r);
      wrt(x.size(), ' ');
      for (auto i : x.v) wrt(i.first, ' ');
      putchar('\n');
    }
  }
}
