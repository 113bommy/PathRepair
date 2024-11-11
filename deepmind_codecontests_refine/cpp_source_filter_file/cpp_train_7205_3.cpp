#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  clock_t launch = clock();
  long long t = 1;
  cin >> t;
  while (t--) {
    long long a[3], n;
    cin >> a[0] >> a[1] >> a[2] >> n;
    sort(a, a + 3);
    n = n - (a[2] - a[0]);
    n = n - (a[2] - a[1]);
    if (n and n % 3 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  clog << ((long double)(clock() - launch) / CLOCKS_PER_SEC) << "\n";
  return 0;
}
