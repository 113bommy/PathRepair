#include <bits/stdc++.h>
using namespace std;
unsigned long long int n, k;
unsigned long long int pw(unsigned long long int base,
                          unsigned long long int p) {
  unsigned long long int ans = 1;
  for (unsigned long long int i = 1; i <= p; i++) ans *= base;
  return ans;
}
unsigned long long int calc(unsigned long long int n) {
  unsigned long long int c2 = 0, c5 = 0, temp = n, m2 = 1, m5 = 1;
  if (temp % 2 == 0)
    while (temp % 2 == 0) c2++, temp /= 2;
  temp = n;
  if (temp % 5 == 0)
    while (temp % 5 == 0) c5++, temp /= 5;
  if (c2 < k) m2 = pw(2, k - c2);
  if (c2 < k) m5 = pw(5, k - c5);
  return n * m2 * m5;
}
int main() {
  cin >> n >> k;
  cout << calc(n) << endl;
}
