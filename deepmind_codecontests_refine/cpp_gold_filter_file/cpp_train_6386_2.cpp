#include <bits/stdc++.h>
const int N = 1e3 + 10;
using namespace std;
int n, a[N];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = min(a[0], a[n - 1]);
  int x = 1e9;
  for (int i = 1; i < n - 2; i++) x = min(x, max(a[i], a[i + 1]));
  cout << min(x, ans);
  return 0;
}
