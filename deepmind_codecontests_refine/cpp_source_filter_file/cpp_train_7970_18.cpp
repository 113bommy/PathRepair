#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  int r = 240 - k, sum = 0, i;
  if (r == 0)
    cout << r;
  else {
    for (i = 1; i < n; ++i) {
      sum += (5 * i);
      if (sum >= r) break;
    }
    cout << i;
  }
  return 0;
}
