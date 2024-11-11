#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int n, m;
  cin >> n >> m;
  int mm[11] = {};
  int i;
  int total = 0;
  for (i = 1; i <= n; i++) {
    int a;
    cin >> a;
    mm[a]++;
    total++;
  }
  long long ans = 0;
  for (i = 1; i <= m; i++) {
    ans += mm[i] * (total - mm[i]);
  }
  cout << ans / 2 << "\n";
  return 0;
}
