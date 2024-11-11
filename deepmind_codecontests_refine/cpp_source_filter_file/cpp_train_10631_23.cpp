#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 5;
const int MOD = 1e9 + 7;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
int ddr[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int ddc[8] = {1, -1, 0, 0, 1, -1, -1, 1};
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
long long int power(long long int a, long long int b) {
  long long int ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % MOD;
    a = (a * a) % MOD;
    b /= 2;
  }
  return ans;
}
long long int nCr(long long int n, long long int r) {
  long long int ans = 1, i;
  if (r > n - r) r = n - r;
  for (i = 0; i < r; i++) {
    ans = (ans * (n - i)) % MOD;
    ans = (ans * power(i + 1, MOD - 2)) % MOD;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << n + 1 << "\n";
    cout << "2 " << n << " 1\n";
    cout << "1 " << n << " 2000\n";
    for (int i = 1; i < n; i++) {
      cout << "2 " << i << " " << 2000 - i + 1 << "\n";
    }
  }
  return 0;
}
