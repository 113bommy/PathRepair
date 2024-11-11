#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, k;
  cin >> n >> k;
  if (k >= (n * (n + 1)) / 2) {
    cout << "no solution";
    return 0;
  }
  for (long long int i = 0; i < n; i++) {
    cout << 0 << " " << i << endl;
  }
}
