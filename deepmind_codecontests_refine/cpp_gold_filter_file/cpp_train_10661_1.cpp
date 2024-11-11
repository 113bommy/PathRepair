#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  while (b) {
    b ^= a ^= b ^= a %= b;
  }
  return a;
}
int main() {
  int a[100002], n, k, i, j;
  cin >> n >> k;
  for (i = 1; i < n - k; i++) {
    a[i] = i + 1;
  }
  a[i] = 1;
  for (j = i + 1; j <= n; j++) {
    a[j] = j;
  }
  int ans = 0;
  for (i = 1; i <= n; i++) {
    if (gcd(i, a[i]) != 1) ans++;
  }
  if (ans == k) {
    for (i = 1; i <= n; i++) {
      cout << a[i] << " ";
    }
  } else
    cout << "-1";
  return 0;
}
