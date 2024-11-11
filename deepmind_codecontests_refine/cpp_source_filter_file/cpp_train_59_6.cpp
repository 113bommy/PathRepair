#include <bits/stdc++.h>
using namespace std;
int a[1000000 + 9];
long long inst[1000000 + 9], perm[1000000 + 9];
long long d[1000000 + 9];
void updateRange(int x, int k, int l, int r) {
  inst[l] += x;
  perm[l + 1] += k;
  perm[r + 1] -= k;
  inst[r + 1] -= x + (long long)(r - l) * k;
}
void acc(long long* a, int l, int r) {
  long long val = 0, inc = 0;
  for (int i = l; i <= r; i++) {
    val += inst[i];
    inc += perm[i];
    val += inc;
    a[i] = val;
  }
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    if (a[i] >= i) {
      int x = a[i] - i;
      updateRange(x, -1, 0, x);
      updateRange(1, 1, x + 1, n - i);
      updateRange(a[i] - 1, -1, n - i + 1, n - 1);
    } else {
      int x = i - a[i];
      updateRange(x, 1, 0, n - i);
      updateRange(a[i] - 1, -1, n - i + 1, n - i + a[i]);
      updateRange(1, 1, n - i + a[i] + 1, n - 1);
    }
  }
  acc(d, 0, n - 1);
  int bestDev = d[0], besti = 0;
  for (int i = 0; i <= n - 1; i++) {
    if (d[i] < bestDev) {
      bestDev = d[i];
      besti = i;
    }
  }
  cout << bestDev << " " << besti << endl;
  return 0;
}
