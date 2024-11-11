#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, t;
  cin >> n >> k >> t;
  if (t < k && t >= 0) {
    cout << t << endl;
  } else if (t >= k && t < n) {
    cout << k << endl;
  } else if (t > n) {
    cout << n + k - t << endl;
  } else
    cout << "0";
  return 0;
}
