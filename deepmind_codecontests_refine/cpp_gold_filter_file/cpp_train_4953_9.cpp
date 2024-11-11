#include <bits/stdc++.h>
using namespace std;
int mult(int x, int y) {
  long long int ans, x1 = (long long int)x, y1 = (long long int)y;
  ans = (x1 * y1) % 1000000007;
  return (int)ans;
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
long long int pow1(long long int a, long long int b) {
  long long int ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % 1000000007;
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return ans;
}
int mina(int arr[], int n) {
  int x = arr[0], i, pos = 0;
  for (i = 1; i < n; i++) {
    if (arr[i] < x) {
      x = arr[i];
      pos = i;
    }
  }
  return x;
}
int maxa(int arr[], int n) {
  int x = arr[0], i, pos = 0;
  for (i = 1; i < n; i++) {
    if (arr[i] > x) {
      x = arr[i];
      pos = i;
    }
  }
  return x;
}
int main() {
  int n, k, i, j;
  scanf("%d", &n);
  scanf("%d", &k);
  if (k == 1 || k > 3) {
    cout << -1 << endl;
    return 0;
  }
  if (k > n - 1) {
    cout << -1 << endl;
    return 0;
  }
  if (n <= 3) {
    cout << -1 << endl;
    return 0;
  }
  if (n == 4) {
    if (k == 2) {
      cout << -1 << endl;
      return 0;
    }
    if (k == 3) {
      cout << 3 << endl;
      cout << 1 << " " << 2 << endl
           << 2 << " " << 3 << endl
           << 3 << " " << 4 << endl;
      return 0;
    }
  }
  if (k == 2) {
    cout << n - 1 << endl;
    for (i = 1; i < n; i++) cout << i << " " << i + 1 << endl;
    return 0;
  }
  cout << 3 + (n - 5 + 1) * 3 << endl;
  for (i = 1; i < 4; i++) cout << i << " " << i + 1 << endl;
  for (i = 5; i < n + 1; i++) cout << 1 << " " << i << endl;
  for (i = 5; i < n + 1; i++) cout << 2 << " " << i << endl;
  for (i = 5; i < n + 1; i++) cout << 3 << " " << i << endl;
  return 0;
}
