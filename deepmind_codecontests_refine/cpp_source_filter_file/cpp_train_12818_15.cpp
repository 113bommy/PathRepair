#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  int a[n];
  int count = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < x) {
      count++;
    }
  }
  if (x <= y) {
    cout << count - 1 << endl;
  } else {
    cout << n << endl;
  }
  return 0;
}
