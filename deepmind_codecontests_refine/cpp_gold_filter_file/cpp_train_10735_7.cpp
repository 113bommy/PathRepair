#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
const int mod = 1e9 + 7;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int q, n = 1000000;
long long seg[maxn * 4], lazy[maxn * 4];
void build(int id = 1, int l = 1, int r = n) {
  if (l == r) {
    seg[id] = l;
    return;
  }
  int mid = (l + r) / 2;
  build(id * 2, l, mid);
  build(id * 2 + 1, mid + 1, r);
  seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}
void upd(int id, long long val) {
  seg[id] += val;
  lazy[id] += val;
}
void shift(int id) {
  if (!lazy[id]) return;
  upd(id * 2, lazy[id]);
  upd(id * 2 + 1, lazy[id]);
  lazy[id] = 0;
}
void modify(int first, int second, long long val, int id = 1, int l = 1,
            int r = n) {
  if (l > second || r < first) return;
  if (l >= first && r <= second) {
    upd(id, val);
    return;
  }
  shift(id);
  int mid = (l + r) / 2;
  modify(first, second, val, id * 2, l, mid);
  modify(first, second, val, id * 2 + 1, mid + 1, r);
  seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}
long long query(int first, int second, int id = 1, int l = 1, int r = n) {
  if (l > second || r < first) return 0;
  if (l >= first && r <= second) return seg[id];
  shift(id);
  int mid = (l + r) / 2;
  return max(query(first, second, id * 2, l, mid),
             query(first, second, id * 2 + 1, mid + 1, r));
}
long long f[maxn];
void add(int i, long long a) {
  for (; i <= n; i += i & -i) f[i] += a;
}
long long get(int i) {
  long long ret = 0;
  for (; i > 0; i -= i & -i) ret += f[i];
  return ret;
}
long long get(int l, int r) { return get(r) - get(l - 1); }
pair<int, int> que[300005];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  build();
  cin >> q;
  for (int i = 1; i <= q; i++) {
    char type;
    cin >> type;
    if (type == '+') {
      int pos, d;
      cin >> pos >> d;
      modify(1, pos, d);
      add(pos, d);
      que[i] = {pos, d};
    } else if (type == '-') {
      int id, pos, d;
      cin >> id;
      tie(pos, d) = que[id];
      modify(1, pos, -d);
      add(pos, -d);
    } else {
      int pos;
      cin >> pos;
      long long sum = query(1, pos);
      sum -= get(pos + 1, n);
      cout << sum - pos << "\n";
    }
  }
  return 0;
}
