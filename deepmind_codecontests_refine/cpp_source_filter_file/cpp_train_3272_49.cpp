#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int i, a[n], k;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (a[i] > a[j]) {
        k = a[j];
        a[j] = a[i];
        a[i] = k;
      }
    }
  }
  for (i = 0; i < n; i++) cout << a[i];
  return 0;
}
