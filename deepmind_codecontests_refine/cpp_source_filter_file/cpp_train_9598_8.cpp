#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  clock_t tStart = clock();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, a, b;
  cin >> n >> a >> b;
  cout << max(n - b, a + 1) << "\n";
}
