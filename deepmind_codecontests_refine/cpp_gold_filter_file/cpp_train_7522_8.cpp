#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int arr[n];
    for (long long int i = 0; i < n; i++) cin >> arr[i];
    for (long long int i = n - 2; i >= 0; i--) arr[i] += arr[i + 1];
    long long int m = numeric_limits<long long int>::min();
    for (long long int i = 0; i < n; i++) {
      long long int k = arr[i];
      m = max(m, k);
    }
    cout << m << endl;
  }
  return 0;
}
