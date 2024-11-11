#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
const int N = 1e6 + 3;
int n, m, bit[N << 1], ans[N], cur[N << 1];
bool in[N];
void upd(int p, int v) {
  for (; p <= m + n; p += p & -p) bit[p] += v;
}
int query(int num) {
  int pos = 0, sum = 0;
  for (int i = (20); i >= (0); --i)
    if (pos + (1 << i) <= m + n && sum + bit[pos + (1 << i)] < num) {
      pos += 1 << i;
      sum += bit[pos];
    }
  return pos + 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  bool ok = 1;
  cin >> n >> m;
  for (int i = (m + 1); i <= (m + n); ++i) upd(i, 1);
  for (int i = (1); i <= (m); ++i) {
    int x, pos;
    cin >> x >> pos;
    int p = query(pos);
    if (p > m) {
      if (in[x])
        ok = 0;
      else {
        ans[p - m] = x;
        in[x] = 1;
        upd(p, -1);
        upd(m - i + 1, 1);
        cur[m - i + 1] = x;
        cur[p] = 0;
      }
    } else {
      if (cur[p] != x)
        ok = 0;
      else {
        upd(p, -1);
        upd(m - i + 1, 1);
        cur[m - i + 1] = x;
        cur[p] = 0;
      }
    }
  }
  int p = 1;
  if (!ok)
    cout << -1;
  else
    for (int i = (1); i <= (n); ++i) {
      if (ans[i])
        cout << ans[i] << ' ';
      else {
        while (p <= n && in[p]) p++;
        cout << p << ' ';
        p++;
      }
    }
  return 0;
}
