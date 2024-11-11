#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, k, t;
  cin >> n >> k >> t;
  if (t <= k) {
    cout << t << endl;
  } else if (t <= n) {
    cout << k << endl;
  } else {
    cout << k - (n - t) << endl;
  }
}
