#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  int large = 2 * k + 1, small = k + 1;
  int pieces = n / large + (n % large > 0);
  cout << pieces << endl;
  int rem = n % large;
  if (rem == 0) {
    for (int i = small; i <= n; i += large) cout << i << " ";
    return 0;
  }
  if (small <= rem) {
    for (int i = rem - small; i < n; i += large) cout << i + 1 << " ";
  } else {
    rem += large - small;
    cout << "1 ";
    if (n - rem + small > 1) cout << n - rem + small << " ";
    for (int i = large; i < n - 1 - rem; i += large) cout << i + 1 << " ";
  }
  return 0;
}
