#include <bits/stdc++.h>
using namespace std;
int a[1100];
int n, k, l, r, sum, sk;
void deal(int sum, int id1, int id2, int l, int r) {
  for (int i = id1; i <= id2; i++) {
    a[i] = l;
    sum -= l;
  }
  int h = id1;
  while (sum) {
    if (sum >= (r - l)) {
      a[h++] += r - l;
      sum -= (r - l);
    } else {
      a[h] += sum;
      break;
    }
  }
}
bool solve(int t) {
  int res = sum - sk;
  a[k] = t;
  if (!((n - k) * l <= res && res <= (n - k) * t)) return 0;
  if (!((k - 1) * t <= sk - t && sk - t <= (k - 1) * r)) return 0;
  deal(sk - t, 1, k - 1, t, r);
  deal(res, k + 1, n, l, t);
  return 1;
}
int main() {
  cin >> n >> k >> l >> r >> sum >> sk;
  for (int i = l; i <= r; i++) {
    if (solve(i)) {
      for (int i = 1; i <= n; i++) cout << a[i] << " ";
      return 0;
    }
  }
}
