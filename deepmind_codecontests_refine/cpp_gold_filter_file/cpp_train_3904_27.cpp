#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long int n, m, k;
  cin >> n >> m >> k;
  long long int a, b;
  for (long long int i = 0; i < k; i++) {
    cin >> a >> b;
    long long int dis = min(min(a, n + 1 - a), min(b, m + 1 - b));
    if (dis <= 5) return cout << "YES", 0;
  }
  cout << "NO";
  return 0;
}
