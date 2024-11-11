#include <bits/stdc++.h>
using namespace std;
vector<long long> o;
void primeFactors(long long n) {
  while (n % 2 == 0) {
    o.push_back(2);
    n = n / 2;
  }
  for (long long i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      o.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) o.push_back(n);
}
int main() {
  long long n, x, y;
  cin >> n >> x >> y;
  long long ar[n];
  for (int i = 0; i < n; i++) ar[i] = 1;
  primeFactors(y);
  long long j = 1;
  for (int i = 0; i < o.size(); i++) j *= o[i];
  if (j < n) {
    cout << -1;
    return 0;
  }
  j -= n;
  ar[0] += j;
  if (pow(ar[0], 2) + n - 1 < x) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < n; i++) cout << ar[i] << "\n";
  return 0;
}
