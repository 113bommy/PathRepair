#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, k, q = 0;
  cin >> n >> m >> k;
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    if (x < 5 || n - x < 5 || y < 5 || m - y < 5) q = 1;
  }
  if (q == 1)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
