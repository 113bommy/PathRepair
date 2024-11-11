#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int modInverse(int n, long long int p) { return power(n, p - 2, p); }
bool calc(int sum, int a, int b) {
  int f = 1;
  while (sum != 0) {
    int d = sum % 10;
    if (d != a && d != b) {
      f = 0;
      break;
    }
    sum /= 10;
  }
  return f;
}
int main() {
  int n, k, x;
  cin >> n >> k >> x;
  long long int arr[n];
  long long int ans = 1;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long int por[n];
  for (int i = 0; i < k; i++) ans *= x;
  long long preSum[n + 1], suffSum[n + 1];
  preSum[0] = 0;
  for (int i = 0; i < n; i++) preSum[i + 1] = preSum[i] | arr[i];
  suffSum[n] = 0;
  for (int i = n - 1; i >= 0; i--) suffSum[i] = suffSum[i + 1] | arr[i];
  for (int i = 0; i < n; i++) {
    por[i] = preSum[i] | (ans * arr[i]) | suffSum[i + 1];
  }
  sort(por, por + n);
  cout << por[n - 1] << endl;
}
