#include <bits/stdc++.h>
using namespace std;
using namespace std;
long long n, k, t;
int main() {
  cin >> n >> k >> t;
  if (t <= k)
    return cout << t, 0;
  else if (t <= n)
    return cout << k, 0;
  cout << n + k - t;
  return 0;
}
