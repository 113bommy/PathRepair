#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, y;
  cin >> n;
  int a[105] = {0};
  cin >> k;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x]++;
  }
  int mi = INT_MIN;
  for (int i = 1; i <= 105; i++) {
    mi = max(mi, a[i]);
  }
  if (mi % k == 0) {
    y = mi / k;
  } else {
    y = (mi / k) + 1;
  }
  int sum = 0;
  for (int i = 1; i <= 105; i++) {
    if (a[i] > 0) {
      sum += y * k;
      a[i] = 0;
    }
  }
  cout << sum - n << endl;
  return 0;
}
