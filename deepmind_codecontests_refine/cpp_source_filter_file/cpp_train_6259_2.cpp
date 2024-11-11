#include <bits/stdc++.h>
using namespace std;
char uc[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
               'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char lc[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
               'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
bool is_prime(unsigned long long n) {
  if (n == 1) {
    return false;
  }
  unsigned long long i = 2;
  while (i * i <= n) {
    if (n % i == 0) {
      return false;
    }
    i += 1;
  }
  return true;
}
unsigned long long countDivisors(unsigned long long n) {
  unsigned long long cnt = 0;
  for (unsigned long long i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        cnt++;
      else
        cnt = cnt + 2;
    }
  }
  return cnt - 1;
}
unsigned long long divisor(unsigned long long number) {
  for (unsigned long long i = 2; i <= sqrt(number); i++) {
    if (number % i == 0) {
      return number / i;
    }
  }
  return 1;
}
unsigned long long getSum(unsigned long long n) {
  unsigned long long sum = 0;
  while (n != 0) {
    sum = sum + n % 10;
    n = n / 10;
  }
  return sum;
}
vector<unsigned long long> primeFactors(unsigned long long n) {
  set<unsigned long long> s;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      s.insert(i);
      n /= i;
    }
  }
  if (n > 1) s.insert(n);
  vector<unsigned long long> v(s.begin(), s.end());
  return v;
}
long double distance(int x1, int y1, int x2, int y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int a[n], fl = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (long long int i = 0; i < n - 1; i++) {
    if (a[i] != a[n - 1] && a[i] * 2 > a[n - 1]) {
      fl = 1;
      break;
    }
  }
  if (fl == 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
