#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, *a;
  cin >> n;
  a = new int[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int t = 0;
  while (true) {
    int p = pow(2, t);
    if (p > n) {
      t--;
      break;
    }
    t++;
  }
  int counter = 0;
  pow(2, t);
  for (int i = 0; i < n - 1; i++) {
    int p = pow(2, t);
    counter += a[i];
    a[i + p] += a[i];
    if (i + 1 + p >= n && t != 0) t--;
    cout << counter << " ";
  }
  return 0;
}
