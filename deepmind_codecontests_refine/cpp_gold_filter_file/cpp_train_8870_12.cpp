#include <bits/stdc++.h>
using ll = long long int;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, n, a, b, k, i, j, r, h;
  cin >> n >> a >> b >> k;
  vector<int> kk(n);
  int d, rr;
  for (i = 0; i < n; ++i) {
    cin >> h;
    r = h % (a + b);
    if (r == 0) {
      if (a > b) {
        d = 1;
      } else {
        rr = (b - a) % a;
        d = (b - a) / a + (rr != 0) + 1;
      }
    } else {
      if (r <= a) {
        d = 0;
      } else {
        rr = (r - a) % a;
        d = (r - a) / a + (rr != 0);
      }
    }
    kk[i] = d;
  }
  sort(kk.begin(), kk.end());
  int cur_k;
  cur_k = 0;
  for (i = 0; i < n; ++i) {
    if (cur_k + kk[i] <= k) {
      cur_k += kk[i];
    } else {
      break;
    }
  }
  cout << i;
  return 0;
}
