#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n <= 1) return false;
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
long long factorial(long long n) {
  if (n == 0)
    return 1;
  else
    return n * factorial(n - 1);
}
bool primeFactors(int n, int l, int r, bool notFound) {
  for (int i = l; i <= r; i++) {
    if (i == 1) i++;
    if (n % i == 0) {
      cout << i << " ";
      notFound = false;
    }
    while (n % i == 0) {
      n = n / i;
    }
  }
  return notFound;
}
bool IsInBinarySequence(long long number) {
  long long numbertocheck = 1;
  do {
    if (number == numbertocheck) return true;
    numbertocheck *= 2;
  } while (numbertocheck <= number);
  return false;
}
long long nextPowerOf2(long long n) {
  if (n && !(n & (n - 1))) return n;
  long long cnt = 0;
  while (n != 0) {
    n >>= 1;
    cnt++;
  }
  long long x = 1;
  x = x << cnt;
  return x;
}
long long highestPowerof2(long long n) {
  long long res = 0;
  for (long long i = n; i >= 1; i--) {
    if ((i & (i - 1)) == 0) {
      res = i;
      break;
    }
  }
  return res;
}
long long fib(long long n) {
  if (n <= 1) return 1;
  return fib(n - 1) + fib(n - 2);
}
long long binets_formula(long long n) {
  double sqrt5 = sqrt(5);
  int F_n = (pow((1 + sqrt5), n) - pow((1 - sqrt5), n)) / (pow(2, n) * sqrt5);
  return F_n;
}
void first50fib() {
  long long arr[] = {
      1,          1,           2,          3,          5,          8,
      13,         21,          34,         55,         89,         144,
      233,        377,         610,        987,        1597,       2584,
      4181,       6765,        10946,      17711,      28657,      46368,
      75025,      121393,      196418,     317811,     514229,     832040,
      1346269,    2178309,     3524578,    5702887,    9227465,    14930352,
      24157817,   39088169,    63245986,   102334155,  165580141,  267914296,
      433494437,  701408733,   1134903170, 1836311903, 2971215073, 4807526976,
      7778742049, 12586269025, 20365011074};
}
int binarySearch(int a[], int first, int last, int search_num) {
  int middle;
  if (last >= first) {
    middle = (first + last) / 2;
    if (a[middle] == search_num) {
      return middle + 1;
    } else if (a[middle] < search_num) {
      return binarySearch(a, middle + 1, last, search_num);
    } else {
      return binarySearch(a, first, middle - 1, search_num);
    }
  }
  return -1;
}
void factorize(long long n) {
  int count = 0;
  while (!(n % 2)) {
    n /= 2;
    count++;
  }
  if (count) cout << 2 << "^" << count << endl;
  for (long long i = 3; i <= sqrt(n); i += 2) {
    count = 0;
    while (n % i == 0) {
      count++;
      n = n / i;
    }
    if (count) cout << i << "^" << count << endl;
  }
  if (n > 2) cout << n << "^" << 1 << endl;
}
void primeFactors(long long num) {
  long long fac = 2;
  while (num > 1) {
    if (num % fac == 0) {
      cout << fac << "^";
      num /= fac;
      long long pow = 1;
      while (num % fac == 0) {
        num /= fac;
        pow++;
      }
      cout << pow;
      if (num != 1) cout << endl;
    } else {
      fac++;
    }
  }
}
bool onePrimeFactor(long long num) {
  long long fac = 2;
  int cnt = 0;
  while (num > 1) {
    if (num % fac == 0) {
      cnt++;
      while (num % fac == 0) num /= fac;
    } else {
      fac++;
    }
    if (cnt >= 2) {
      return false;
    }
  }
  return true;
}
bool isPerfect(long long d) {
  double temp = d;
  d = sqrt(d);
  temp = sqrt(temp);
  if (temp == d) return true;
  return false;
}
const long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, m;
  char arr[101][101];
  bool check[101][101];
  memset(check, true, sizeof(check));
  memset(arr, 0, sizeof(arr));
  cin >> n >> m;
  for (long long i = 0; i < (n); i++) {
    for (long long j = 0; j < (m); j++) {
      cin >> arr[i][j];
    }
  }
  for (long long i = 0; i < (n); i++) {
    for (long long j = 0; j < (m); j++) {
      for (long long q = 0; q < (m); q++) {
        if (j == q) continue;
        if (arr[i][j] == arr[i][q]) {
          check[i][j] = false;
          check[i][q] = false;
          break;
        }
      }
    }
  }
  for (long long j = 0; j < (m); j++) {
    for (long long i = 0; i < (n); i++) {
      for (long long q = 0; q < (n); q++) {
        if (i == q) continue;
        if (arr[i][j] == arr[q][j]) {
          check[i][j] = false;
          check[q][j] = false;
          break;
        }
      }
    }
  }
  for (long long i = 0; i < (n); i++) {
    for (long long j = 0; j < (n); j++) {
      if (check[i][j]) cout << arr[i][j];
    }
  }
}
