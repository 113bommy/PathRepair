#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a1 = 1, a2 = 1, c;
  cin >> n;
  char a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n % 2 == 0) {
    b[n - 1] = a[n - 1];
    b[(n - 1) / 2] = a[0];
    for (int i = 1; i < n - 1; i++) {
      if (i % 2 != 0) {
        b[((n - 1) / 2) + a2] = a[i];
        a2++;
      } else {
        b[((n - 1) / 2) - a1] = a[i];
        a1++;
      }
    }
  } else {
    b[n / 2] = a[0];
    for (int i = 1; i < n; i++) {
      if (i % 2 == 0) {
        b[(n / 2) + a2] = a[i];
        a2++;
      } else {
        b[(n / 2) - a1] = a[i];
        a1++;
      }
    }
  }
  for (int i = 0; i < n; i++) cout << b[i];
}
