#include <bits/stdc++.h>
using namespace std;
int mul[10];
int bit(int mask, int i) { return (mask / mul[i]) % 10; }
int t, t1;
void solve() {
  int n, k;
  cin >> n >> k;
  if (n == 1e9) {
    if (k == 1) {
      cout << 1111111111;
    } else {
      cout << 1e9;
    }
    cout << '\n';
    return;
  }
  bool c[10] = {0};
  int cnt = 0;
  int j = 8;
  while (bit(n, j) == 0) {
    j--;
  }
  int cur = 0;
  int mincs = 10;
  int res = 0;
  for (int i = 0; i <= j; i++) {
    res += mul[i] * (bit(n, j) + 1);
  }
  for (int i = j; i >= 0; i--) {
    if (!c[bit(n, i)]) {
      c[bit(n, i)] = 1;
      cnt++;
      mincs = min(mincs, bit(n, i));
    }
    cur *= 10;
    cur += bit(n, i);
    if (i > 0 && bit(n, i - 1) == 9) continue;
    if (cnt <= k) {
      if (i == 0) {
        res = n;
      } else {
        if (cnt < k) {
          if (cnt < k - 1) {
            res = min(res, cur * mul[i] + (bit(n, i - 1) + 1) * mul[i - 1]);
          } else {
            int tmp = cur * mul[i] + (bit(n, i - 1) + 1) * mul[i - 1];
            for (int z = 0; z < i - 1; z++) {
              tmp += mul[z] * min(mincs, bit(n, i - 1) + 1);
            }
            res = min(res, tmp);
          }
        }
        int z;
        for (z = bit(n, i - 1) + 1; z < 10; z++) {
          if (c[z]) {
            break;
          }
        }
        if (z < 10) {
          if (cnt < k) {
            res = min(res, cur * mul[i] + z * mul[i - 1]);
          } else {
            int tmp = cur * mul[i] + z * mul[i - 1];
            for (int y = 0; y < i - 1; y++) {
              tmp += mul[y] * mincs;
            }
            res = min(res, tmp);
          }
        }
      }
    }
  }
  cout << res << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  mul[0] = 1;
  for (int i = 1; i < 10; i++) {
    mul[i] = mul[i - 1] * 10;
  }
  cin >> t;
  for (t1 = 1; t1 <= t; t1++) {
    solve();
  }
}
