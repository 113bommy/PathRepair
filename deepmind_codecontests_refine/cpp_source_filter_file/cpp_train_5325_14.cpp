#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1000005;
long long pw(long long b, long long r, long long md) {
  long long ans = 1;
  while (r) {
    if (r & 1) ans = (ans * b) % md;
    b = (b * b) % md;
    r >>= 1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i <= n - 1; ++i) cin >> arr[i];
  long long mn = 1e18, counter = 0;
  mn = arr[0];
  for (long long i = 0; i <= n - 1; ++i) {
    if (mn == arr[i])
      counter++;
    else if (mn > arr[i]) {
      mn = arr[i];
      counter;
    }
  }
  if (counter > (n / 2))
    cout << "Bob\n";
  else
    cout << "Alice" << '\n';
  return 0;
}
