#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, t;
  cin >> n >> k >> t;
  if (k > t)
    cout << t << endl;
  else if (n >= t && k <= t)
    cout << k << endl;
  else
    cout << k - (t - n) << endl;
  return 0;
}
