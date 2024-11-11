#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  cin >> n >> k;
  long long int A[n];
  for (long long int i = 0; i < n; i++) {
    cin >> A[i];
  }
  long long int ans = 0;
  for (long long int i = 0; i < n - 1; i++) {
    if (A[i] + A[i + 1] >= k) {
      continue;
    } else if (A[i] + A[i + 1] < k) {
      long long int prevsum = (A[i] + A[i + 1]);
      A[i + 1] += (k - prevsum);
      ans += (k - prevsum);
    }
  }
  cout << ans << "\n";
  for (long long int i = 0; i < n; i++) {
    cout << A[i] << " ";
  }
  cout << "\n";
}
