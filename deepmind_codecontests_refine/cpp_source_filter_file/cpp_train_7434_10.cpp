#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000, N = 110;
int main() {
  int n, d, m;
  cin >> n >> d;
  int a[N];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cin >> m;
  sort(a + 1, a + n + 1);
  for (int i = n + 1; i <= 100; i++) {
    a[i] -= d;
  }
  int res = 0;
  for (int i = 1; i <= m; i++) {
    res += a[i];
  }
  cout << res << '\n';
  return 0;
}
