#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, y, n;
  cin >> x >> y;
  cin >> n;
  long long arr[6];
  arr[0] = x - y;
  arr[1] = x;
  arr[2] = y;
  arr[3] = y - x;
  arr[4] = -x;
  arr[5] = -y;
  n %= 6;
  if (arr[n] < 0) {
    if (arr[n] < 2 * 1000000007)
      cout << (arr[n] + 2 * 1000000007) << endl;
    else
      cout << arr[n] + 1000000007 << endl;
  } else
    cout << arr[n] % 1000000007 << endl;
  return 0;
}
