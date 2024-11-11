#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
bool prime[10000];
void sieve() {
  for (int p = 2; p * p <= 10000; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= 10000; i += p) prime[i] = false;
    }
  }
}
int main() {
  int n, k, cnt = 0;
  cin >> n >> k;
  int a[n + 5];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    if (abs(a[i] + a[i - 1]) < k) {
      cnt += k - (a[i] + a[i - 1]);
      a[i] = k - a[i - 1];
    }
  }
  cout << cnt << endl;
  for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
}
