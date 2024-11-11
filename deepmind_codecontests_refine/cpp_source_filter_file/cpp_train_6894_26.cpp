#include <bits/stdc++.h>
using namespace std;
long long fx[4] = {1, -1, 0, 0};
long long fy[4] = {0, 0, 1, -1};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    if (n < m) swap(n, m);
    if (m * 2 == n)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}
