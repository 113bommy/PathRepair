#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
void swap(long long *a, long long *b) {
  long long c = *a;
  *a = *b;
  *b = c;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  bool codechef = 0, codeforces = 0;
  long long t = 1;
  if (codechef) cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n], i, j;
    vector<long long> v;
    vector<long long>::iterator it;
    long long ct1 = 0, ct2 = 0, ans = 0;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 1)
        ct1++;
      else
        ct2++;
    }
    if (ct1 >= ct2) {
      ans += ct2;
      ct1 -= ct2;
      ans += ct1 / 3;
    } else {
      ans += ct1 / 3;
    }
    cout << ans << endl;
  }
  return 0;
}
