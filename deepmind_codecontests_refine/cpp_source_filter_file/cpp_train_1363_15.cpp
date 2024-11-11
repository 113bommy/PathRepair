#include <bits/stdc++.h>
using namespace std;
double prefix[10000];
double arr[10000];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  prefix[1] = arr[1];
  for (int i = 2; i <= n; i++) {
    prefix[i] = prefix[i - 1] + arr[i];
  }
  double ans = -1;
  for (int i = k; i < n; i++) {
    for (int j = k; j <= i; j++) {
      ans = max(ans, (prefix[i] - prefix[i - j]) / j);
    }
  }
  std::cout << setprecision(10);
  std::cout << ans << endl;
}
