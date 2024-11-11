#include <bits/stdc++.h>
using namespace std;
const long double PIE = 3.14159265358979323846;
const int N = 1e5 + 5;
long long seg[N << 2];
int n;
void upd(int pos, long long val, int rt = 1, int tl = 1, int tr = n) {
  if (tl > pos || tr < pos) return;
  if (tl == tr)
    seg[rt] = max(seg[rt], val);
  else {
    int mid = (tl + tr) >> 1;
    upd(pos, val, rt << 1, tl, mid);
    upd(pos, val, rt << 1 | 1, mid + 1, tr);
    seg[rt] = max(seg[rt << 1], seg[rt << 1 | 1]);
  }
}
long long query(int L, int R, int rt = 1, int tl = 1, int tr = n) {
  if (tl > R || tr < L) return 0;
  if (tl >= L && tr <= R) return seg[rt];
  int mid = (tl + tr) >> 1;
  return max(query(L, R, rt << 1, tl, mid),
             query(L, R, rt << 1 | 1, mid + 1, tr));
}
void solve() {
  cin >> n;
  int rad[n], ht[n];
  long long vol[n];
  map<long long, int> m;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> rad[i] >> ht[i];
    vol[i] = rad[i] * 1ll * rad[i] * ht[i];
    m[vol[i]] = 1;
  }
  for (auto &v : m) {
    v.second = ++cnt;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long prev = query(1, m[vol[i]] - 1);
    ans = max(ans, vol[i] + prev);
    upd(m[vol[i]], vol[i] + prev);
  }
  cout << fixed << setprecision(6) << ans * PIE << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
