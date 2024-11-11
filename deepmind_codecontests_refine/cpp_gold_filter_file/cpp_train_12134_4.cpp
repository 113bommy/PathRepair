#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[200001], i, cnt = 1, max1 = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n - 1; i++) {
    if (a[i + 1] > a[i]) {
      ++cnt;
    } else {
      if (cnt > max1) {
        max1 = cnt;
      }
      cnt = 1;
    }
  }
  if (cnt > max1) {
    max1 = cnt;
  }
  cout << max1 << endl;
}
