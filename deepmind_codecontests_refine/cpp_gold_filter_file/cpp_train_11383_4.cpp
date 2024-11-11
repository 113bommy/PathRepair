#include <bits/stdc++.h>
using namespace std;
long long sum[111111], arr[111111], n;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i(0), _n(n); i < _n; ++i) cin >> arr[i + 1];
  for (int i(0), _n(n - 1); i < _n; ++i) {
    for (int j(33), _b(0); j >= _b; --j) {
      if (i + 1 + (1LL << j) <= n) {
        arr[i + 1 + (1LL << j)] += arr[i + 1];
        sum[i + 1] = sum[i] + arr[i + 1];
        break;
      }
    }
  }
  for (int i(0), _n(n - 1); i < _n; ++i) {
    cout << sum[i + 1] << endl;
  }
}
