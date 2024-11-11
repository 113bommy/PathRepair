#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int i, n, flag1 = 1, flag2;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  int max = a[0];
  int min = a[n - 1];
  flag2 = n - 1;
  for (i = 0; i < n; i++) {
    if (a[i] > max) {
      max = a[i];
      flag1 = i;
    }
  }
  for (i = n - 1; i >= 0; i--) {
    if (a[i] < min) {
      min = a[i];
      flag2 = i;
    }
  }
  if (flag1 > flag2)
    cout << (n - 1 - flag2) + flag1 - 1;
  else
    cout << (n - 1 - flag2) + flag1;
  return 0;
}
