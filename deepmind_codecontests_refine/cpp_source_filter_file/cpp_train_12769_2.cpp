#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("-O2")
const int LIM = 1e5 + 5, MOD = 1e9 + 7;
int n, x[LIM], y[LIM], t1, t2;
long long a1, b1, c1, a2, b2, c2;
bool solve(int i, int j) {
  a1 = y[j] - y[i];
  b1 = x[i] - x[j];
  c1 = x[i] * a1 + y[i] * b1;
  t1 = j + 1;
  while (t1 < n) {
    if (t2 == 0 && a1 * x[t1] + b1 * y[t1] != c1)
      t2 = t1;
    else if (t2 != 0 && a1 * x[t1] + b1 * y[t1] != c1) {
      break;
    }
    t1++;
  }
  if (t1 == (n - 1)) {
    return 1;
  }
  a2 = y[t2] - y[t1];
  b2 = x[t1] - x[t2];
  c2 = x[t1] * a2 + y[t1] * b2;
  for (int i = t1 + 1; i < n; i++) {
    if (a1 * x[i] + b1 * y[i] != c1 && a2 * x[i] + b1 * y[i] != c2) return 0;
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  if (n <= 4) {
    cout << "Yes";
    return 0;
  }
  bool ans = solve(0, 1);
  if (ans) {
    cout << "Yes";
    return 0;
  }
  t2 = 0;
  ans = solve(1, 2);
  if (ans) {
    if (t1 == n || t2 == 0) {
      cout << "Yes";
      return 0;
    } else {
      a2 = y[t2] - y[t1];
      b2 = x[t1] - x[t2];
      c2 = x[t1] * a2 + y[t1] * b2;
      if (a2 * x[0] + b2 * y[0] == c2) {
        cout << "Yes";
        return 0;
      }
    }
  }
  t2 = 0;
  ans = solve(0, 2);
  if (ans) {
    if (t1 == n || t2 == 0) {
      cout << "Yes";
      return 0;
    } else {
      a2 = y[t2] - y[t1];
      b2 = x[t1] - x[t2];
      c2 = x[t1] * a2 + y[t1] * b2;
      if (a2 * x[1] + b2 * y[1] == c2) {
        cout << "Yes";
        return 0;
      }
    }
  }
  cout << "No";
  return 0;
}
