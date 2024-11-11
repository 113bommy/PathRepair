#include <bits/stdc++.h>
using namespace std;
long long int solve(long long int n) {
  long long int r = n;
  if (n == 1) return 1;
  long long int ans = 0;
  long long int pr = 0;
  while (n % 2 == 0) {
    n = n / 2;
    ans = 1;
    pr = 2;
  }
  for (int i = 3; i <= sqrt(n); i++)
    if (n % i == 0) {
      ans++;
      pr = i;
      while (n % i == 0) n = n / i;
    }
  if (r == n) return n;
  if (ans >= 2) return 1;
  long long int rr = pr;
  while (pr < n) pr = pr * rr;
  if (pr == n) return rr;
  return 1;
}
int main() {
  long long int n;
  cin >> n;
  cout << solve(n) << endl;
}
