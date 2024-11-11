#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k;
  ios::sync_with_stdio(false);
  cin >> k;
  if (k > 2 * 18) {
    cout << -1;
    return 0;
  }
  while (k > 1) {
    k -= 2;
    cout << 8;
  }
  if (k == 1) cout << 0;
  return 0;
}
