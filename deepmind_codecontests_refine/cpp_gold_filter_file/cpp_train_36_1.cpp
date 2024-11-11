#include <bits/stdc++.h>
using namespace std;
long long MD = 1000000007;
long long md = 998244353;
const long long INF = 1e18L + 5;
long long exp(long long a, long long b) {
  long long r = 1ll;
  while (b > 0) {
    if (b & 1) {
      r = r * (a % md);
      r = (r + md) % md;
    }
    b /= 2;
    a = (a % md) * (a % md);
    a = (a + md) % md;
  }
  return (r + md) % md;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long pow_2(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a);
    a = (a * a);
    b >>= 1;
  }
  return res;
}
bool isPrime(long long a) {
  for (long long i = 3; (i * i) <= a; i += 2) {
    if ((a % i) == 0) return false;
  }
  if ((a != 2) && ((a % 2) == 0)) return false;
  if (a == 1) return false;
  return true;
}
string decToBinary(int n) {
  string s = "";
  for (int i = 31; i >= 0; i--) {
    int k = n >> i;
    if (k & 1)
      s = s + "1";
    else
      s = s + "0";
  }
  return s;
}
int decimalToBinary(int N) {
  unsigned long long int B_Number = 0;
  int cnt = 0;
  while (N != 0) {
    int rem = N % 2;
    unsigned long long int c = pow(10, cnt);
    B_Number += rem * c;
    N /= 2;
    cnt++;
  }
  return B_Number;
}
string toString(unsigned long long int num) {
  std::string number;
  std::stringstream strstream;
  strstream << num;
  strstream >> number;
  return number;
}
const double PI = acos(-1);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int a = 0, j = 0, f = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A')
      a++;
    else if (s[i] == 'I')
      j++;
    else
      f++;
  }
  if (j >= 2)
    cout << "0" << endl;
  else {
    if (j == 1)
      cout << "1" << endl;
    else {
      cout << a << endl;
    }
  }
  return 0;
}
