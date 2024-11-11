#include <bits/stdc++.h>
using namespace std;
int main() {
  long long d;
  cin >> d;
  long long n;
  cin >> n;
  long long a[n + 1];
  for (long long i = 1; i <= n; i++) cin >> a[i];
  long long ans = 0;
  for (long long i = 2; i <= n; i++) {
    ans += (d - a[i - 1]);
  }
  cout << ans << endl;
}
