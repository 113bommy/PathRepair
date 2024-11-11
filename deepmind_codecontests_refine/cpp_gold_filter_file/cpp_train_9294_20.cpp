#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int N, a[MAXN], t[4 * MAXN];
bool ok[MAXN];
void upd(int v, int tl, int tr, int loc, int val) {
  if (tl == tr)
    t[v] = val;
  else {
    int tm = (tl + tr) / 2;
    if (loc <= tm)
      upd(2 * v, tl, tm, loc, val);
    else
      upd(2 * v + 1, tm + 1, tr, loc, val);
    t[v] = min(t[2 * v], t[2 * v + 1]);
  }
}
int get(int v, int tl, int tr, int l, int r) {
  if (l > r) return 1e9;
  if (tl == l && tr == r) return t[v];
  int tm = (tl + tr) / 2;
  return min(get(2 * v, tl, tm, l, min(r, tm)),
             get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    if (a[i] != 1) {
      ok[1] = true;
      if (get(1, 1, N + 1, a[i], a[i]) < get(1, 1, N + 1, 1, a[i] - 1)) {
        ok[a[i]] = true;
      }
    }
    upd(1, 1, N + 1, a[i], i);
  }
  for (int i = 2; i <= N + 1; i++) {
    if (get(1, 1, N + 1, i, i) < get(1, 1, N + 1, 1, i - 1)) ok[i] = true;
  }
  int ans = 1;
  while (ok[ans]) ans++;
  cout << ans << "\n";
}
