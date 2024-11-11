#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
bool prime(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int arr[10001], n;
int main() {
  ios_base::sync_with_stdio(NULL), cout.tie(NULL), cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  long long mx = 0;
  for (int i = 0; i < n; i++) {
    long long ans = 0;
    ans++;
    for (int r = i + 1; r < n; r++) {
      if (arr[r] < arr[r - 1]) break;
      ans++;
    }
    for (int l = i - 1; l >= 0; l--) {
      if (arr[l] > arr[l + 1]) break;
      ans++;
    }
    mx = max(mx, ans);
  }
  cout << mx << endl;
  return 0;
}
