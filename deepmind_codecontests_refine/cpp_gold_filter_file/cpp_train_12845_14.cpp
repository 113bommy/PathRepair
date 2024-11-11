#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, k;
  cin >> n >> k;
  if ((n * (n - 1)) / 2 <= k)
    cout << "no solution";
  else {
    for (int i = 1; i <= n; ++i) {
      cout << 0 << " " << i;
      cout << '\n';
    }
  }
  return 0;
}
