#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long z = 2 * n;
    long long a[z + 1];
    a[0] = 0;
    for (long long i = 1; i <= z; i++) cin >> a[i];
    sort(a, a + z);
    long long x = z / 2;
    long long y = (z / 2) + 1;
    long long ans = abs(a[x] - a[y]);
    cout << ans << endl;
  }
}
