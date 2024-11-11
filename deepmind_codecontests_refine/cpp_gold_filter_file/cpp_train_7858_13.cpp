#include <bits/stdc++.h>
using namespace std;
int f(int a[], int n);
int main() {
  int n, i;
  int *a;
  cin >> n;
  a = new int[n];
  for (i = 0; i < n; i++) cin >> a[i];
  cout << f(a, n);
  return 0;
}
int f(int a[], int n) {
  int m = 1, len = 1, i;
  for (i = 1; i < n; i++) {
    if (a[i] >= a[i - 1])
      len++;
    else {
      if (m < len) m = len;
      len = 1;
    }
  }
  if (m < len) m = len;
  return m;
}
