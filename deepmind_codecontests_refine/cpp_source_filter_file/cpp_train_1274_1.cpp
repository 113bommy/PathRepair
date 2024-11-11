#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
int t, n;
int a[N];
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long sum = a[1];
    int last = a[1];
    for (int i = 2; i <= n; i++) {
      if (1LL * a[i] * a[i - 1] < 0)
        sum += a[i], last = a[i];
      else if (a[i] > last)
        sum += a[i] - a[i - 1], last = a[i];
    }
    cout << sum << '\n';
  }
  return 0;
}
