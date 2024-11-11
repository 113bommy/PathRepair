#include <bits/stdc++.h>
using namespace std;
template <typename T>
using V = vector<T>;
template <typename T>
using VV = vector<V<T>>;
template <typename T>
istream& operator>>(istream& cin, V<T>& arr) {
  for (T& val : arr) {
    cin >> val;
  }
  return cin;
}
template <typename T>
ostream& operator<<(ostream& cout, V<T>& arr) {
  for (T& val : arr) {
    cout << val << " ";
  }
  return cout;
}
int main() {
  long long n, k, A, B;
  cin >> n >> k >> A >> B;
  long long ans = 0;
  if (k == 1) {
    ans = A * (n - 1);
    n = 1;
  }
  while (n > 1) {
    if (n % k == 0) {
      if ((n - n / k) * A < B)
        ans += (n - n / k) * A;
      else
        ans += B;
      n /= k;
    } else if (n < k) {
      ans += (n - 1) * A;
      n = 1;
    } else {
      ans += (n % k) * A;
      n -= n % k;
    }
  }
  cout << ans;
  return 0;
}
