#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
int isPali(string str) {
  string u;
  for (int i = str.length() - 1; i >= 0; i--) {
    u += str[i];
  }
  if (u == str) {
    return 1;
  }
  return 0;
}
long long int power(long long int a, long long int n) {
  long long int res = 1;
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    res = ((1 << (n / 2)) % mod);
    return res * res;
  } else {
    res = ((1 << (n / 2)) % mod);
    return ((res % mod) * (res % mod) * (a % mod)) % mod;
  }
}
long long int gcd(long long int a, long long int b) {
  if (b != 0) {
    return gcd(b, a % b);
  } else {
    return a;
  }
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
bool checkPrimeNumber(int n) {
  bool isPrime = true;
  if (n == 0 || n == 1) {
    isPrime = false;
  } else {
    for (int i = 2; i <= n / 2; ++i) {
      if (n % i == 0) {
        isPrime = false;
        break;
      }
    }
  }
  return isPrime;
}
bool isPerfectSquare(long double x) {
  if (x >= 0) {
    long long sr = sqrt(x);
    return (sr * sr == x);
  }
  return false;
}
long long int cel(long long int a, long long int b) { return (a + b - 1) / b; }
long long int fib(long long int n) {
  if (n <= 1) return n;
  return fib(n - 1) + fib(n - 2);
}
long long int modFact(long long int n, long long int p) {
  if (n >= p) return 0;
  long long int result = 1;
  for (long long int i = 1; i <= n; i++) result = (result * i) % p;
  return result;
}
long long int digSum(long long int n) {
  long long int sum = 0;
  while (n != 0) {
    sum += n % 10;
    n = n / 10;
  }
  return sum;
}
bool CompFloat(float a, float b) {
  if (abs(a - b) < 1e-9) {
    return true;
  }
  return false;
}
bool isPowerOfTwo(int n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
long long int smallest_divisor(long long int n) {
  long long int i;
  for (i = 2; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      return i;
    }
  }
  return n;
}
long long int powe(long long int x, long long int y, long long int p) {
  int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void solve() {
  long long int n, c = 0;
  cin >> n;
  long long int x = log10(n) + 1;
  long long int t = n;
  long long int p = n;
  while (n) {
    if (n % 10 != 0) {
      c++;
    }
    n = n / 10;
  }
  if (c == 1) {
    cout << (int)pow(10, x - 1);
  } else {
    t = t / pow(10, x - 1);
    t++;
    cout << t * pow(10, x - 1) - p;
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
}
