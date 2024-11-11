#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k, t;
  cin >> n >> k >> t;
  if (t <= k)
    cout << n;
  else if (t > k && t <= n)
    cout << k;
  else
    cout << k - t + n;
  return 0;
}
