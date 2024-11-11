#include <bits/stdc++.h>
using namespace std;
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
long long int mod = 1000000007;
long long int po(long long int x, long long int n) {
  long long int res = 1;
  while (n > 0) {
    if (n % 2 == 1) res = ((res) * (x));
    x = (x * x);
    n = n / 2;
  }
  return res;
}
long long int ceil(long long int x, long long int y) {
  if (x % y == 0)
    return x / y;
  else
    return (x / y) + 1;
}
long long int binomialCoeff(int n, int k) {
  long long int res = 1;
  if (k > n - k) k = n - k;
  for (int i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
vector<long long int> d;
void primeFactors(int n) {
  while (n % 2 == 0) {
    d.push_back(2);
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      d.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) d.push_back(n);
}
bool prime(long long int n) {
  if (n == 1 || n == 0) return 0;
  for (long long int i = 2; i * i <= n; i++)
    if (n % i == 0) return 0;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  if (n == 3 || n == 5) {
    cout << 1;
    cout << "\n";
    cout << n;
  } else {
    cout << 3;
    cout << "\n";
    cout << 3 << " ";
    n = n - 3;
    for (long long int i = n; i >= 0; i--) {
      if (prime(i) && prime(n - i)) {
        cout << i << " " << n - i;
        break;
      }
    }
  }
  return 0;
}
