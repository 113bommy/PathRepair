#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.141592653589793;
const int mod = 1e9 + 9;
int n, q, l, r;
long long A[1 << 20], x, diff[1 << 20];
long long psum = 0;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    diff[i] = A[i] - A[i - 1];
    if (i > 1) psum += max(0LL, diff[i]);
  }
  long long tmp = psum + diff[1];
  cout << ((1 & tmp) ? (1 + tmp) / 2 : tmp / 2) << endl;
  cin >> q;
  while (q--) {
    cin >> l >> r >> x;
    if (l - 1 > 0) {
      if (diff[l] > 0) psum -= diff[l];
      psum += max(0LL, diff[l] + x);
      diff[l] += x;
    }
    if (r + 1 <= n) {
      if (diff[r + 1] > 0) psum -= diff[r + 1];
      psum += max(0LL, diff[r + 1] - x);
      diff[r + 1] += x;
    }
    if (l == 1) diff[1] += x;
    tmp = psum + diff[1];
    cout << ((1 & tmp) ? (1 + tmp) / 2 : tmp / 2) << endl;
  }
  return 0;
}
