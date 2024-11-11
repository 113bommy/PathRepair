#include <bits/stdc++.h>
using namespace std;
const int sz = (1 << 18) - 1;
int t1[sz * 2], t2[sz * 2], a, b;
void upd1(int pos, int x) {
  t1[pos += sz] += x;
  t1[pos] = min(t1[pos], b);
  while ((pos /= 2) >= 1) t1[pos] = t1[pos * 2] + t1[pos * 2 + 1];
}
int get1(int l, int r) {
  int res = 0;
  for (l += sz, r += sz; l <= r; l /= 2, r /= 2) {
    if (l % 2 == 1) res += t1[l++];
    if (r % 2 == 0) res += t1[r--];
    if (l > r) break;
  }
  return res;
}
void upd2(int pos, int x) {
  t2[pos += sz] += x;
  t2[pos] = min(t2[pos], a);
  while ((pos /= 2) >= 1) t2[pos] = t2[pos * 2] + t2[pos * 2 + 1];
}
int get2(int l, int r) {
  int res = 0;
  for (l += sz, r += sz; l <= r; l /= 2, r /= 2) {
    if (l % 2 == 1) res += t2[l++];
    if (r % 2 == 0) res += t2[r--];
    if (l > r) break;
  }
  return res;
}
int n, k, q, tupe, d, f, p;
int main() {
  cin >> n >> k >> a >> b >> q;
  for (int i = 1; i <= q; ++i) {
    cin >> tupe;
    if (tupe == 1) {
      cin >> d >> f;
      upd1(d, f);
      upd2(d, f);
    } else {
      cin >> p;
      cout << get1(1, p - 1) + get2(p + k, n) << endl;
    }
  }
  return 0;
}
