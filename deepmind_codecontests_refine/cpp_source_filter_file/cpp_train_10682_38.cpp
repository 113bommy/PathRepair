#include <bits/stdc++.h>
using namespace std;
long long a[1000];
long long n, k, t;
int main() {
  cin >> n >> k >> t;
  if (t <= k) {
    cout << t;
    return 0;
  }
  if (t > k) {
    cout << k - (t - n);
    return 0;
  }
  cout << k;
}
