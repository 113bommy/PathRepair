#include <bits/stdc++.h>
using namespace std;
const int P = 1000 * 1000 * 1000 + 7;
const int MAX_N = 2000 + 10;
int arr[MAX_N] = {1}, a[MAX_N];
int fact[MAX_N] = {1};
int power(int n, int k) {
  int ans = 1;
  for (int i = 30; ~i; i--) {
    ans = 1LL * ans * ans % P;
    if (k & (1 << i)) ans = 1LL * ans * n % P;
  }
  return ans;
}
int C(int n, int k) {
  if (n - k < k) return C(n, n - k);
  if (k < 0 || n < k) return 0;
  int ans = power(fact[k], P - 2);
  for (int i = 0; i < k; i++) ans = 1LL * ans * (n - i) % P;
  return ans;
}
int main() {
  ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) fact[i] = 1LL * fact[i - 1] * i % P;
  for (int i = 0; i < n; i++) arr[i] = C(k + i - 1, i);
  arr[0] = 1;
  for (int i = 0; i < n; i++) {
    int num = 0;
    for (int j = 0; j <= i; j++) (num += 1LL * arr[i - j] * a[j] % P) %= P;
    cout << num << ' ';
  }
  return 0;
}
