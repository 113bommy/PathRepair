#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long x) {
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return false;
  return true;
}
int main() {
  long long n, N, cnt = 0, first = 0;
  cin >> n;
  N = n;
  while (n % 2 == 0) cnt++, n /= 2;
  for (int i = 3; i <= sqrt(n); i += 2)
    while (n % i == 0) cnt++, n /= i;
  if (!cnt || isPrime(N)) return cout << 1 << '\n' << (long long)0, 0;
  if (n != 1) cnt++;
  if (cnt == 2) return cout << 2, 0;
  for (long long i = 2; i * i <= N; i++)
    if (N % i == 0 && !first) {
      first = i;
      N /= i;
      if (N % i == 0) return cout << "1\n" << first * i, 0;
    } else if (N % i == 0)
      return cout << "1\n" << first * i, 0;
}
