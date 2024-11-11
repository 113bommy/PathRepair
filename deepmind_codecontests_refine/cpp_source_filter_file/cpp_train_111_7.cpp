#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int a[n], sum = 0, mx = 0;
  for (int(i) = (0); (i) < (n); ++(i)) {
    cin >> a[i];
    sum += a[i];
    mx = max(mx, a[i]);
  }
  cout << min(mx, 2 * sum / n + 1) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  solve();
  return 0;
}
