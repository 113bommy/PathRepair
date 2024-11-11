#include <bits/stdc++.h>
#pragma optimization_level 3
using namespace std;
long long t = 1;
long long k, n, m, a[1008][1008];
pair<long long, long long> dp[1008][1008];
void MAIN() {
  cin >> k;
  cout << "2 3\n";
  long long maxx = 1 << 17;
  cout << maxx + k << " " << k << " " << 0 << "\n";
  cout << k << " " << maxx + k << " " << 0 << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  while (t--) {
    MAIN();
  }
}
