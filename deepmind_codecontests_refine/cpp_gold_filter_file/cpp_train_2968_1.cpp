#include <bits/stdc++.h>
using namespace std;
bool prime[10000000];
void seive() {
  for (int i = 3; i <= 10000000; i += 2) prime[i] = true;
  prime[2] = true;
  prime[1] = false;
  int k = sqrt(10000000);
  for (int i = 3; i <= k; i += 2) {
    if (prime[i] == true)
      for (int j = i * i; j <= 10000000; j += (2 * i)) prime[j] = false;
  }
}
bool ispalin(int n) {
  int temp = n;
  int m = 0;
  while (n > 0) {
    m = m * 10 + n % 10;
    n /= 10;
  }
  if (temp == m)
    return true;
  else
    return false;
}
int main() {
  seive();
  long long p, q, tot_prime = 0, tot_palin = 0, last;
  cin >> p >> q;
  for (int i = 1; i <= 10000000; i++) {
    if (prime[i]) tot_prime++;
    if (ispalin(i)) tot_palin++;
    if (q * tot_prime <= p * tot_palin) {
      last = i;
    }
  }
  cout << last << endl;
  return 0;
}
