#include <bits/stdc++.h>
using namespace std;
void push(int &v, vector<long long> &now, vector<long long> &p) {
  if (now[v] == 1e11) return;
  p[v * 2] = min(p[v * 2], now[v]);
  p[v * 2 + 1] = min(p[v * 2 + 1], now[v]);
  now[v * 2] = min(now[v * 2], now[v]);
  now[v * 2 + 1] = min(now[v * 2 + 1], now[v]);
  now[v] = 1e11;
}
void modify(int v, int ls, int rs, int l, int r, long long val,
            vector<long long> &p, vector<long long> &now) {
  if (l > r) return;
  if (ls == l && rs == r) {
    now[v] = min(now[v], val);
    p[v] = min(p[v], val);
    return;
  }
  int mid = (ls + rs) / 2;
  push(v, now, p);
  modify(v * 2, ls, mid, l, min(r, mid), val, p, now);
  modify(v * 2 + 1, mid + 1, rs, max(mid + 1, l), r, val, p, now);
  p[v] = min(p[v * 2], p[v * 2 + 1]);
}
long long get(int v, int ls, int rs, int l, int r, vector<long long> &p,
              vector<long long> &now) {
  if (l > r) return 1e11;
  if (ls == l && rs == r) return p[v];
  int mid = (ls + rs) / 2;
  push(v, now, p);
  return min(get(v * 2, ls, mid, l, min(r, mid), p, now),
             get(v * 2 + 1, mid + 1, rs, max(mid + 1, l), r, p, now));
}
int main() {
  int n, k;
  ios_base ::sync_with_stdio(0);
  cin >> n >> k;
  vector<bool> f(n, 0);
  vector<long long> p(4 * n + 16, 1e11), now(4 * n + 16, 1e11);
  for (int i = 0; i < n; ++i) {
    char symbol;
    cin >> symbol;
    if (symbol == '1') f[i] = 1;
  }
  for (int i = 0; i < n; ++i) {
    modify(1, 0, n, i + 1, i + 1,
           i + 1 + ((i == 0) ? 0 : get(1, 0, n, i, i, p, now)), p, now);
    if (f[i]) {
      long long _now;
      if (i - k <= 0)
        _now = i + 1;
      else
        _now = get(1, 0, n, i - k, i, p, now) + i + 1;
      modify(1, 0, n, i + 1, min(n, i + k + 1), _now, p, now);
    }
  }
  cout << get(1, 0, n, n, n, p, now) << endl;
  return 0;
}
