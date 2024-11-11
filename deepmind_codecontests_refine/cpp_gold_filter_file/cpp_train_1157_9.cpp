#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int main() {
  int n;
  cin >> n;
  int arr[n];
  int tem;
  for (int tt = 0; tt < n; tt++) {
    cin >> tem;
    arr[tt] = tem;
  }
  auto max = [](int a, int b) { return a > b ? a : b; };
  long max_cost = 100000000;
  int viable_x = 0;
  for (int x = 1; x <= n; x++) {
    long cst = 0;
    for (int t = 1; t <= n; t++) {
      cst += 4 * max(t - 1, x - 1) * arr[t - 1];
    }
    if (cst < max_cost) {
      max_cost = cst;
      viable_x = x;
    }
  }
  cout << max_cost;
  return 0;
}
