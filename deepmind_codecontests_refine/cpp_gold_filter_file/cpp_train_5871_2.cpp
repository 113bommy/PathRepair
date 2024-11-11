#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const double PI = 3.1415926536;
int main() {
  int n;
  cin >> n;
  int arr[205];
  int neg = 0;
  for (int i = 0; i < 2 * n - 1; i++) {
    cin >> arr[i];
    if (arr[i] < 0) neg++;
  }
  int res = 0;
  for (int i = 0; i < 2 * n - 1; i++) res += abs(arr[i]);
  if (neg % 2 == 0 || n % 2) {
    cout << res << endl;
    return 0;
  }
  int m = 99999999;
  for (int i = 0; i < 2 * n - 1; i++) {
    m = min(abs(arr[i]), m);
  }
  cout << res - 2 * m << endl;
  return 0;
}
