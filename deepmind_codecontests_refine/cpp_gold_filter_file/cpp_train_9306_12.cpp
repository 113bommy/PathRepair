#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, i, j, cnt = 0;
  cin >> n >> d;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (abs(a[i] - a[j]) <= d) {
        cnt += 2;
      }
    }
  }
  cout << cnt;
  return 0;
}
