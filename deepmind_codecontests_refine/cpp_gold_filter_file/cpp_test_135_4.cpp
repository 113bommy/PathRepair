#include <bits/stdc++.h>
using namespace std;
template <class T>
T solve(T n, T k) {
  vector<T> arr(n);
  for (T i = 0; i < n; i++) {
    cin >> arr[i];
  }
  T sum = 0;
  sort(arr.begin(), arr.end(), greater<int>());
  for (int i = 2 * k; i < n; i++) {
    sum += arr[i];
  }
  for (T i = 0; i < k; ++i) {
    sum += (arr[i + k] / arr[i]);
  }
  return sum;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    cout << solve(n, k) << "\n";
  }
  return 0;
}
