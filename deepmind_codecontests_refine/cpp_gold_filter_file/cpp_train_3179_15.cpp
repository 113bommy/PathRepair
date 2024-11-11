#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, k;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 1; i < (n); i += 2) {
    if (a[i] < a[i - 1]) {
      k = a[i];
      a[i] = a[i - 1];
      a[i - 1] = k;
    }
  }
  for (i = 2; i < (n); i += 2) {
    if (a[i] > a[i - 1]) {
      k = a[i];
      a[i] = a[i - 1];
      a[i - 1] = k;
    }
  }
  for (i = 0; i < n; i++) cout << a[i] << " ";
}
