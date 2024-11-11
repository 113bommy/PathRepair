#include <bits/stdc++.h>
using namespace std;
long long a[52];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  if (a[0] != a[n / 2])
    cout << "Alice" << endl;
  else
    cout << "Bob" << endl;
  return 0;
}
