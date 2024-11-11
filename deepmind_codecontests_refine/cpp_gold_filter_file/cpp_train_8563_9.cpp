#include <bits/stdc++.h>
using namespace std;
long wei(long a, long i) {
  long sum = 0;
  while (a) {
    sum += a % i;
    a /= i;
  }
  return sum;
}
long long gcc(long long sum, long long i) {
  if (sum % i == 0) return i;
  return gcc(i, sum % i);
}
int main() {
  long long a, m, i, sum = 0;
  cin >> a;
  m = a - 2;
  for (i = 2; i < a; i++) sum += wei(a, i);
  i = gcc(sum, a - 2);
  cout << sum / i << "/" << (a - 2) / i;
  return 0;
}
