#include <bits/stdc++.h>
using namespace std;
bool isprime(long long int n) {
  if (n < 2) return false;
  for (long long int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
long long int countDivisors(long long int n) {
  long long int cnt = 0;
  for (long long int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        cnt++;
      else
        cnt = cnt + 2;
    }
  }
  return cnt;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    cout << n - 1 << endl;
    ;
  }
  return 0;
}
