#include <bits/stdc++.h>
using namespace std;
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 1e2 + 9, OO = 1e9;
long long type[N], val[N], q[N];
int main() {
  cout << fixed << setprecision(0), ios::sync_with_stdio(false),
      cin.tie(nullptr), cout.tie(nullptr);
  ;
  int n, c;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> type[i];
    if (type[i] == 1) {
      cin >> val[i];
      q[i + 1] = 1;
    } else {
      cin >> val[i] >> c;
      q[i + 1] = val[i] * c;
    }
  }
  ++n;
  for (int i = 1; i <= n; ++i) q[i] += q[i - 1];
  --n;
  int m, t;
  cin >> m;
  while (m--) {
    cin >> c;
    while (1) {
      t = lower_bound(q, q + n, c) - q;
      --t;
      if (type[t] == 1) {
        cout << val[t] << ' ';
        break;
      }
      c -= q[t];
      c = (c - 1) % (val[t]) + 1;
    }
  }
  return 0;
}
