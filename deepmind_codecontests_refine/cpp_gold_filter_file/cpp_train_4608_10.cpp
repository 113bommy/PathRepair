#include <bits/stdc++.h>
using namespace std;
long long mod = pow(10, 9) + 7;
int gcdExtended(int a, int b, int *x, int *y);
long long modInverse(int b, int m) {
  int x, y;
  int g = gcdExtended(b, m, &x, &y);
  if (g != 1) return -1;
  return (x % m + m) % m;
}
int gcdExtended(int a, int b, int *x, int *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  int x1, y1;
  int gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
string decimalToBinary(long long n) {
  string s = bitset<64>(n).to_string();
  const auto loc1 = s.find('1');
  if (loc1 != string::npos) return s.substr(loc1);
  return "0";
}
int binaryToDecimal(int n) {
  int num = n;
  int dec_value = 0;
  int base = 1;
  int temp = num;
  while (temp) {
    int last_digit = temp % 10;
    temp = temp / 10;
    dec_value += last_digit * base;
    base = base * 2;
  }
  return dec_value;
}
int factorial(int n);
int factorial(int n) {
  unsigned long long ans = 1;
  while (n != 1) {
    ans = ((ans % mod) * (n % mod)) % mod;
    n--;
  }
  return ans;
}
unsigned long long sumbincoef(int N, int k) {
  unsigned long long bincoef = 1, sum = 1;
  int i;
  for (i = 1; i < k; ++i) {
    bincoef = (bincoef * (N - i + 1) / i);
    sum += bincoef;
  }
  return sum;
}
bool is_prime(long long n) {
  if (n == 1) {
    return false;
  }
  long long i = 2;
  while (i * i <= n) {
    if (n % i == 0) {
      return false;
    }
    i += 1;
  }
  return true;
}
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int check(int x, vector<int> a, int n) {
  int county = 0;
  map<int, int> mapa;
  for (int i = 0; i < n; i++) {
    mapa.insert(pair<int, int>(a[i], 0));
  }
  for (int i = 0; i < n; i++) {
    mapa[a[i]]++;
  }
  for (int i = 0; i < a.size(); i++) {
    mapa[a[i]]--;
    if (mapa[abs(a[i] - x)] > 0) {
      county++;
      mapa[abs(a[i] - x)]--;
    }
  }
  return county;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t > 0) {
    long long a, b, n, m;
    cin >> a >> b >> n >> m;
    if (min(a, b) < m || a + b < n + m) {
      cout << "NO" << endl;
    } else {
      cout << "yEs" << endl;
    }
    t--;
  }
}
