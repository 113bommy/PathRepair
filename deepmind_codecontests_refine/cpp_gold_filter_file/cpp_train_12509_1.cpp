#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long t = 1;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    long long a[7] = {INT_MAX, 4, 8, 15, 16, 23, 42};
    long long ans[7] = {INT_MAX, 0, 0, 0, 0, 0, 0};
    for (long long i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= 6; j++) {
        if (a[j] == arr[i] && ans[j - 1] > ans[j] && ans[j - 1]) {
          ans[j]++;
        }
      }
    }
    long long m = ans[6];
    cout << endl << n - (6 * m) << endl;
  }
  return 0;
}
