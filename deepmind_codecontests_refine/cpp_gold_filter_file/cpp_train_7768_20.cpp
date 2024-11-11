#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 7;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, x;
  cin >> n >> x;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    int y;
    cin >> y;
    sum += y;
  }
  if (x != sum + n - 1)
    cout << "NO";
  else
    cout << "YES";
}
