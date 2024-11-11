#include <bits/stdc++.h>
const int inf = 0x7FFFFFFF;
using namespace std;
int X[1000100];
int main() {
  int n, m;
  long long ans = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) scanf("%d", X + i);
  sort(X, X + n);
  int mid = n / 2, i;
  for (i = 0; i < mid; i += m) ans += (X[mid] - X[i]) * 2LL;
  for (i = n - 1; i > mid; i -= m) ans += (X[i] - X[mid]) * 2LL;
  cout << ans << endl;
  return 0;
}
