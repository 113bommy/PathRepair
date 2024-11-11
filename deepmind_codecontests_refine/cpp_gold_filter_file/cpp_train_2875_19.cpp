#include <bits/stdc++.h>
using namespace std;
const int tinf = (int)1e9 + 7;
const long long inf = (long long)1e18 + 7;
const int N = 4e5 + 5;
int main() {
  {
    ios ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  }
  long long n, k;
  cin >> n >> k;
  if (n == k || !k) {
    cout << 0 << " " << 0;
    return 0;
  }
  cout << 1 << " ";
  if (k <= n / 3) {
    cout << k * 2;
  } else {
    long long ans = n / 3 * 2;
    if (n % 3 == 2)
      k--, ans++;
    else if (n % 3 == 1)
      k--;
    k -= n / 3;
    cout << ans - k;
  }
}
