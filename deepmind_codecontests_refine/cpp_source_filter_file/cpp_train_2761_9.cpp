#include <bits/stdc++.h>
using namespace std;
const int maxn = (2e5) + 2;
int n, k, q, tt;
long long t[2][4 * maxn], a, b;
void upd(int ind, int v, int tl, int tr, int pos, int x) {
  if (tl == tr) {
    if (ind == 0)
      t[ind][v] += min(t[ind][v] + x, b);
    else
      t[ind][v] += min(t[ind][v] + x, a);
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      upd(ind, v + v, tl, tm, pos, x);
    else
      upd(ind, v + v + 1, tm + 1, tr, pos, x);
    t[ind][v] = t[ind][v + v] + t[ind][v + v + 1];
  }
}
long long get(int ind, int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (tl > r || tr < l) return 0;
  if (l <= tl && tr <= r)
    return t[ind][v];
  else {
    int tm = (tl + tr) / 2;
    return get(ind, v + v, tl, tm, l, r) +
           get(ind, v + v + 1, tm + 1, tr, l, r);
  }
}
int main() {
  cin >> n >> k >> a >> b >> q;
  for (int i = 1; i <= q; i++) {
    cin >> tt;
    if (tt == 1) {
      int di, ai;
      cin >> di >> ai;
      upd(0, 1, 1, n, di, ai);
      upd(1, 1, 1, n, di, ai);
    } else {
      int pi;
      cin >> pi;
      cout << get(0, 1, 1, n, 1, pi - 1) + get(1, 1, 1, n, pi + k, n) << endl;
    }
  }
  return 0;
}
