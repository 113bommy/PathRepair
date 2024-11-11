#include <bits/stdc++.h>
using namespace std;
long long qpow(long long a, long long b) {
  long long res = 1, base = a;
  while (b) {
    if (b % 2) res = res * base;
    base = base * base;
    b /= 2;
  }
  return res;
}
long long powmod(long long a, long long b) {
  long long res = 1, base = a;
  while (b) {
    if (b % 2) res = res * base % 1000000007;
    base = base * base % 1000000007;
    b /= 2;
  }
  return res;
}
int sum[200005 << 2];
int add[200005 << 2];
vector<pair<int, int> > q[200005];
pair<int, int> p;
int res[200005];
stack<int> s;
int a[200005];
int b[200005];
int n, m;
void pushup(int o) { sum[o] = sum[o << 1] + sum[o << 1 | 1]; }
void pushdown(int o, int L, int R) {
  if (add[o]) {
    int mid = (L + R) >> 1;
    sum[o << 1] += (mid - L + 1) * add[o];
    sum[o << 1 | 1] += (R - mid) * add[o];
    add[o << 1] += add[o];
    add[o << 1 | 1] += add[o];
    add[o] = 0;
  }
}
void update(int o, int L, int R, int ql, int qr, int v) {
  if (ql <= L && qr >= R) {
    sum[o] += (R - L + 1) * v;
    add[o] += v;
    return;
  }
  pushdown(o, L, R);
  int mid = (L + R) >> 1;
  if (ql <= mid) update(o << 1, L, mid, ql, qr, v);
  if (qr > mid) update(o << 1 | 1, mid + 1, R, ql, qr, v);
  pushup(o);
}
int query(int o, int L, int R, int pos) {
  if (L == R) return sum[o];
  pushdown(o, L, R);
  int mid = (L + R) >> 1;
  int ans = 0;
  if (pos <= mid)
    ans = query(o << 1, L, mid, pos);
  else
    ans = query(o << 1 | 1, mid + 1, R, pos);
  pushup(o);
  return ans;
}
void read(void) {
  int aa, bb;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &aa, &bb);
    q[bb].push_back(make_pair(aa, i));
  }
}
void work(void) {
  for (int k = 2; k <= n; k++) {
    while (!s.empty()) {
      int id = s.top();
      if (a[k - 1] + b[k - 1] >= a[id] + b[id])
        s.pop();
      else
        break;
    }
    s.push(k - 1);
    bool flag = false;
    while (!s.empty()) {
      int id = s.top();
      if (a[id] + b[id] >= a[k]) break;
      int t = a[k] - a[id] - b[id], pre = 1;
      s.pop();
      if (!s.empty()) pre = s.top();
      update(1, 1, n, pre, id, t);
      b[id] += t;
      flag = true;
    }
    if (flag) s.push(k - 1);
    for (int i = 0; i < q[k].size(); i++)
      res[q[k][i].second] = query(1, 1, n, q[k][i].first);
  }
  for (int i = 1; i <= m; i++) printf("%d\n", res[i]);
}
int main(void) {
  read();
  work();
  return 0;
}
