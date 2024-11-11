#include <bits/stdc++.h>
const long long d = 1000000007;
using namespace std;
long long binarysearch(long long v[], long long first, long long last,
                       long long k) {
  while (1) {
    long long mid = (first + last) / 2;
    if (v[mid] <= k && v[mid + 1] > k)
      return mid + 1;
    else if (v[mid] <= k)
      first = mid;
    else
      last = mid;
  }
}
unsigned long long fast_pow(long long b, long long p) {
  if (p == 0) return 1;
  if (p == 1) return b;
  unsigned long long t = fast_pow(b, p / 2);
  t *= t;
  if (p & 1) t = t * b;
  return t;
}
bool isPrime(unsigned long long num) {
  bool flag = true;
  if (num == 0 || num == 1) return false;
  for (unsigned long long i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      flag = false;
      break;
    }
  }
  return flag;
}
long long GCD(long long a, long long b) {
  if (a < b) swap(a, b);
  while (1) {
    long long c = a % b;
    if (c != 0) {
      a = b;
      b = c;
    } else
      break;
  }
  return b;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  std::cout.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cout << i * n << " ";
    }
    cout << '\n';
  }
  return 0;
}
