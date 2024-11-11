#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int i, n, x, y;
  cin >> n >> x >> y;
  long long arr[n + 10];
  arr[0] = 0;
  arr[1] = x;
  for (i = 2; i < n + 1; i += 1) {
    long long a = arr[i - 1] + x, b = arr[(i + 1) >> 1] + y;
    if (i & 1) b += x;
    arr[i] = min(a, b);
  }
  cout << arr[n] << '\n';
  return 0;
}
