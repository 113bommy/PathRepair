#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e9 + 7;
int cal(int j) {
  int sum1 = ((j) * (j - 1)) / 2;
  return (sum1);
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int findGCD(int arr[], int n) {
  int result = arr[0];
  for (int i = 1; i < n; i++) {
    result = gcd(arr[i], result);
    if (result == 1) {
      return 1;
    }
  }
  return result;
}
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
bool isNumber(string s) {
  for (int i = 0; i < s.length(); i++)
    if (isdigit(s[i]) == false) return false;
  return true;
}
int maxi(int a, int b, int c) {
  int ma = max(a, b);
  return (max(ma, c));
}
int ldn(int n) {
  if (n % 2 == 0)
    return (2);
  else {
    int i;
    for (i = 3; i * i <= n; i++) {
      if (n % i == 0) return (i);
    }
    return (n);
  }
}
long long dig(long long n) {
  long long sum = 0;
  while (n > 0) {
    sum++;
    n = n / 10;
  }
  return (sum);
}
bool is_integer(float k) { return std::floor(k) == k; }
bool isy(long double x) {
  if (x >= 0) {
    long long sr = sqrt(x);
    return (sr * sr == x);
  }
  return false;
}
long long powert(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return (res - 1);
}
vector<long long> slicing(vector<long long>& arr, long long X, long long Y) {
  auto start = arr.begin() + X;
  auto end = arr.begin() + Y + 1;
  vector<long long> result(Y - X + 1);
  copy(start, end, result.begin());
  return result;
}
long long poww(long long k, long long i) {
  long long sum = 1;
  long long j;
  for (j = 0; j < i; j++) {
    sum *= k;
  }
  return (sum);
}
void mycode() {
  long long n = 0, li, m, k, ri, i, x = 0, j = -1, d = 0, count = 0, sum = 0;
  string s;
  cin >> s;
  vector<long long> a;
  a.push_back(0);
  j = 0;
  for (i = 0; i < s.length(); i++) {
    if (s[i] == 'a') {
      count++;
    } else {
      a.push_back(count + a[j]);
      j++;
      count = 0;
    }
  }
  for (i = 1; i < a.size(); i++) {
    sum = sum % MAX;
    sum += powert(2, a[i], MAX);
  }
  cout << sum % MAX << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t = 1;
  while (t--) {
    mycode();
  }
  return 0;
}
