#include <bits/stdc++.h>
const int N = 1000000000;
const int INF = 1000000000;
const long double EPS = 1E-10;
using namespace std;
int phi(int n) {
  int result = 1;
  int i = 2;
  while (i * i <= n) {
    int d = 0;
    int m = 1;
    while (n % i == 0) {
      d++;
      n /= i;
      m *= i;
    }
    if (d > 1) result *= m - m / i;
    i++;
  }
  if (n > 1) result *= n - 1;
  return result;
}
int main(int argc, char* argv[]) {
  int n;
  cin >> n;
  cout << phi(phi(n));
  return 0;
}
