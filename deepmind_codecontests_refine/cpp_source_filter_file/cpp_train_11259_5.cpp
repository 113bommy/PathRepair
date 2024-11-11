#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, t, i, count = 0;
  cin >> n >> t;
  long long int a[n], b[n], ref = t, ans = 99999999999;
  for (i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (i = 0; i < n; i++) {
    if (a[i] > t) {
      ref = a[i];
    } else if (a[i] == t) {
      count = i + 1;
      break;
    } else {
      while (t > a[i]) {
        a[i] = a[i] + b[i];
      }
      ref = a[i] - t;
    }
    if (ref < ans) {
      ans = ref;
      count = i + 1;
    }
  }
  cout << count;
}
