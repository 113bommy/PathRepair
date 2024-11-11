#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int n, m, a[N], t[N], r[N], second[N];
pair<int, int> T[2][N * 4];
pair<int, int> get_max(int l, int r, int v = 1, int tl = 1, int tr = n) {
  if (tl > r || tr < l) return make_pair(-mod, 0);
  if (l <= tl && tr <= r) return T[0][v];
  int tm = (tl + tr) / 2;
  return max(get_max(l, r, v * 2, tl, tm),
             get_max(l, r, v * 2 + 1, tm + 1, tr));
}
pair<int, int> get_min(int l, int r, int v = 1, int tl = 1, int tr = n) {
  if (tl > r || tr < l) return make_pair(mod, 0);
  if (l <= tl && tr <= r) return T[1][v];
  int tm = (tl + tr) / 2;
  return min(get_min(l, r, v * 2, tl, tm),
             get_min(l, r, v * 2 + 1, tm + 1, tr));
}
void upd(int p, int v = 1, int tl = 1, int tr = n) {
  if (tl == tr) {
    T[0][v] = T[1][v] = make_pair(a[p], p);
    return;
  }
  int tm = (tl + tr) / 2;
  if (p <= tm)
    upd(p, v * 2, tl, tm);
  else
    upd(p, v * 2 + 1, tm + 1, tr);
  T[0][v] = max(T[0][v * 2], T[0][v * 2 + 1]);
  T[1][v] = min(T[1][v * 2], T[1][v * 2 + 1]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    upd(i);
  }
  for (int i = 1; i <= m; i++) cin >> t[i] >> r[i];
  for (int i = m; i; i--) second[i] = max(second[i + 1], r[i]);
  for (int i = 1; i <= m; i++) {
    if (r[i] > second[i + 1]) {
      if (t[i] == 1) {
        for (int j = r[i]; j > second[i + 1]; j--) {
          pair<int, int> x = get_max(1, j);
          swap(a[x.second], a[j]);
          upd(x.second);
          upd(j);
        }
      } else {
        for (int j = r[i]; j > second[i + 1]; j--) {
          pair<int, int> x = get_min(1, j);
          swap(a[x.second], a[j]);
          upd(x.second);
          upd(j);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
  return 0;
}
