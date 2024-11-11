#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, sx, sy;
  cin >> n >> sx >> sy;
  long long int x[n], y[n];
  for (long long int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    x[i] -= sx;
    y[i] -= sy;
  }
  long long int q[4] = {0}, a[4] = {0};
  for (long long int i = 0; i < n; i++) {
    if (x[i] < 0 && y[i] < 0) {
      q[2]++;
    }
    if (x[i] > 0 && y[i] < 0) {
      q[3]++;
    }
    if (x[i] < 0 && y[i] > 0) {
      q[1]++;
    }
    if (x[i] > 0 && y[i] > 0) {
      q[0]++;
    }
    if (x[i] < 0 && y[i] == 0) {
      a[2]++;
    }
    if (x[i] == 0 && y[i] < 0) {
      a[3]++;
    }
    if (x[i] == 0 && y[i] > 0) {
      a[1]++;
    }
    if (x[i] > 0 && y[i] == 0) {
      a[0]++;
    }
  }
  cout << max({q[0] + q[1] + a[1], q[1] + q[2] + a[2], q[2] + q[3] + a[3],
               q[3] + q[0] + a[0]})
       << "\n";
  long long int mx = -1, id = -1;
  ;
  for (long long int i = 0; i < 4; i++) {
    if (q[i] + q[(i + 1) % 4] + a[(i + 1) % 4] > mx) {
      mx = q[i] + q[(i + 1) % 4] + a[(i + 1) % 4];
      id = (i + 1) % 4;
    }
  }
  if (id == 0) cout << sx + 1 << " " << sy;
  if (id == 1) cout << sx << " " << sy + 1;
  if (id == 2) cout << sx - 1 << " " << sy;
  if (id == 3) cout << sx << " " << sy - 1;
}
