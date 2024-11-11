#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  int a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int k, p;
  for (int i = 0; i < n; ++i) {
    if (i - x < 0) {
      k = 0;
    } else {
      k = i - x;
    }
    if (i + y > n - 1) {
      p = n - 1;
    } else {
      p = i + y;
    }
    int flag = 0;
    for (int j = k; j <= p; ++j) {
      if (a[j] < a[i]) {
        flag = 1;
      }
    }
    if (flag == 0) {
      cout << i << endl;
      return 0;
    }
  }
}
