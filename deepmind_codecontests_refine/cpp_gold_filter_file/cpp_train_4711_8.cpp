#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    long long min = a[1] - a[0], curr = 0;
    for (long long i = 0; i < n - 1; i++) {
      curr = a[i + 1] - a[i];
      if (curr < min) min = curr;
    }
    cout << min << "\n";
  }
}
