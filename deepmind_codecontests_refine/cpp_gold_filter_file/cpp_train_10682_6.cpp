#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, t, r = 0;
  cin >> n >> k >> t;
  if (t <= k)
    r = t;
  else if (t <= n)
    r = k;
  else
    r = n + k - t;
  cout << r << endl;
  return 0;
}
