#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;
int n, m;
int main() {
  cin >> n >> m;
  cout << min(n + 1, m + 1) << "\n";
  for (int i = 0; i <= m && n - i >= 0; i++) {
    cout << n - i << " " << i << "\n";
  }
  return 0;
}
