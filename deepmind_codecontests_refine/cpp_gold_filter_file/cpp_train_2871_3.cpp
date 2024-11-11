#include <bits/stdc++.h>
using namespace std;
long long int md = 1e9 + 7;
long long int __gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return __gcd(b, a % b);
}
long long int poww(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) {
      res *= a;
      res %= md;
    }
    a *= a;
    a %= md;
    b >>= 1;
  }
  return res;
}
void ainp(int arr[], int n) {
  for (int i = 0; i < n; i++) cin >> arr[i];
}
const long long int N = 3e5 + 5;
void fun() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
signed main() {
  fun();
  int n;
  cin >> n;
  int a[n];
  ainp(a, n);
  for (int i = 0; i < (n) / 2; i++)
    if (i % 2 == 0) swap(a[i], a[n - i - 1]);
  for (int i = 0; i < n; i++) cout << a[i] << " ";
}
