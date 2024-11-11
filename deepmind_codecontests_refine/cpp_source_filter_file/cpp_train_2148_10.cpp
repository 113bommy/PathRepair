#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9, PI = acos(-1);
const int N = 2e5 + 5, oo = 1e6, M = 1e5 + 5;
int32_t main() {
  int n;
  cin >> n;
  int last[N];
  for (int i = 0; i < N; i++) last[i] = 1e6;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    last[a] = i;
  }
  int mn = INT_MAX, ans;
  for (int i = 1; i <= N; i++) {
    if (last[i] < mn) mn = last[i], ans = i;
  }
  cout << ans;
  return 0;
}
