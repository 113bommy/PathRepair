#include <bits/stdc++.h>
using namespace std;
int MAX_INT = numeric_limits<int>::max();
int MIN_INT = numeric_limits<int>::min();
long long MAX_LL = numeric_limits<long long>::max();
long long MIN_LL = numeric_limits<long long>::min();
long long mod = 1e9 + 7;
long long n, m;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  vector<long long> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  long long res = 1;
  if (n > m) {
    cout << 0 << '\n';
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        res *= (abs(arr[i] - arr[j]) % m);
        res %= m;
      }
    }
  }
  cout << res << '\n';
}
