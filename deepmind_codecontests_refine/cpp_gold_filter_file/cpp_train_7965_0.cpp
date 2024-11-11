#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int power(long long int x, long long int n) {
  if (n == 0) return 1;
  if (n % 2) return x * power(x * x, (n - 1) / 2);
  return power(x * x, n / 2);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int A[n + 1];
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  long long int PA[n], PB[n];
  string s;
  cin >> s;
  if (s[0] == 'A') {
    PA[0] = A[0];
    PB[0] = 0;
  } else {
    PA[0] = 0;
    PB[0] = A[0];
  }
  for (int i = 1; i < n; i++) {
    PA[i] = PA[i - 1];
    PB[i] = PB[i - 1];
    if (s[i] == 'A') {
      PA[i] += A[i];
    } else {
      PB[i] += A[i];
    }
  }
  long long int ans = PB[n - 1];
  long long int B = ans, D = PA[n - 1];
  for (int i = 0; i < n; i++) {
    ans = max(ans, (B - PB[i] + PA[i]));
  }
  for (int i = n - 1; i >= 0; i--) {
    ans = max(ans, (B - (B - (PB[i])) + (D - PA[i])));
  }
  cout << ans;
  return 0;
}
