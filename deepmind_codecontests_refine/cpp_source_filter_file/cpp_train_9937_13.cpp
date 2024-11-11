#include <bits/stdc++.h>
using namespace std;
int const N = 100050;
long long a[N];
long long b[N];
int main() {
  int n, m;
  cin >> n >> m;
  long long sa = 0, sb = 0;
  int mb = -(1 << 30);
  int ma = mb;
  int ia, ib;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    a[i] = t;
    sa += t;
    if (t > ma) {
      ma = t;
      ia = i;
    }
  }
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    b[i] = t;
    sb += t;
    if (t > mb) {
      mb = t;
      ib = i;
    }
  }
  long long ans1 = 0, ans2 = 0;
  for (int i = 0; i < n; i++) {
    if (i == ia) {
      ans1 += sb;
      continue;
    }
    ans1 += min(sb, a[i]);
  }
  for (int i = 0; i < n; i++) {
    if (i == ib) {
      ans2 += sa;
      continue;
    }
    ans2 += min(sa, b[i]);
  }
  cout << min(ans1, ans2) << '\n';
  return 0;
}
