#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, x, y, sum, min = 1000, p;
  cin >> n;
  int a[n];
  for (i = 0; i < n; cin >> a[i], i++)
    ;
  for (i = 0; i < n; i++) {
    sum = 0;
    p = a[i];
    while (a[i]--) {
      cin >> x;
      sum += x * 5;
    }
    sum += p * 15;
    if (sum < min) {
      min = sum;
    }
  }
  cout << min;
}
