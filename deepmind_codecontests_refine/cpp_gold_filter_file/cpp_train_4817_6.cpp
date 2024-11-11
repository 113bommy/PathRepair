#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long t, n;
  cin >> t;
  for (long i = 0; i < t; i++) {
    cin >> n;
    long long arr[n], sum = 0;
    for (long j = 0; j < n; j++) {
      cin >> arr[j];
      sum += arr[j];
    }
    sort(arr, arr + n, greater<long long>());
    if (arr[0] > sum - arr[0] || sum % 2 == 1) {
      cout << "T" << endl;
    } else {
      cout << "HL" << endl;
    }
  }
  return 0;
}
