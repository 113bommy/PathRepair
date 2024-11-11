#include <bits/stdc++.h>
using namespace std;
int main() {
  int no_testcases{};
  cin >> no_testcases;
  for (int i{1}; i <= no_testcases; i++) {
    int n{}, sum1{}, sum2{};
    cin >> n;
    int arr[n];
    for (int i = 1; i <= n / 2; i++) {
      arr[i - 1] = 2 * i;
      sum1 = sum1 + (2 * i);
    }
    for (int i{n / 2}, j{1}; i < n - 1; i++, j += 2) {
      arr[i] = j;
      sum2 = sum2 + j;
    }
    if ((sum1 - sum2) % 2 == 0) {
      cout << "NO\n";
    } else {
      arr[n - 1] = sum1 - sum2;
      cout << "YES\n";
      for (int i{}; i < n; i++) {
        cout << arr[i];
      }
      cout << endl;
    }
  }
  return 0;
}
