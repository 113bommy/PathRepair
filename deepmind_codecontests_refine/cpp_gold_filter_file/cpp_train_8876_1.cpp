#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  long long sum = 0, res = 0;
  for (int i = 1; i <= k; i++) {
    int a, b;
    cin >> a >> b;
    sum += b;
    res += 1LL * a * b;
  }
  if (sum > n) {
    cout << -1;
  } else if (sum < n) {
    cout << 1;
  } else {
    if (res % n == 1LL * n * (n + 1) / 2 % n) {
      cout << 1;
    } else {
      cout << -1;
    }
  }
  return 0;
}
