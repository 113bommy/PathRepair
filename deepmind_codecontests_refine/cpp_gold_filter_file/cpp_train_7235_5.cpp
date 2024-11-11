#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long a[n];
  long long ans = 0;
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
    if (i == 0)
      ans += abs(a[i]);
    else
      ans += abs(a[i] - a[i - 1]);
  }
  cout << ans << endl;
}
