#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
vector<long long> primes;
bool prime[10005];
void seive() {
  memset(prime, 1, sizeof(prime));
  prime[0] = 0;
  prime[1] = 0;
  for (long long i = 2; i <= 10000; i++) {
    if (prime[i] == 1) {
      for (long long j = i * i; j <= 10000; j += i) prime[j] = 0;
    }
  }
}
long long power(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b % 2 == 1) ans = (ans % 1000000007 * a % 1000000007) % 1000000007;
    a = (a * a) % 1000000007;
    b = b / 2;
  }
  return ans;
}
template <typename T>
std::string NumberToString(T Number) {
  std::ostringstream ss;
  ss << Number;
  return ss.str();
}
string no_to_bits(long long n) {
  string temp = "";
  while (n) {
    temp += (n % 2) + '0';
    n /= 2;
  }
  reverse(temp.begin(), temp.end());
  return temp;
}
long long bits_to_no(string s) {
  long long ans = 0, var = 0;
  for (int i = s.size() - 1; i >= 0; i--) {
    ans += pow(2, var++) * (s[i] - '0');
  }
  return ans;
}
void solve() {
  double x;
  cin >> x;
  long long i, j, k;
  for (i = 1; i <= int(x); i++) {
    for (j = 1; j <= int(x); j++) {
      if (i % j == 0) {
        double a = i;
        double b = j;
        if ((a * b) > x && (a / b) < x) {
          cout << a << " " << b;
          return;
        }
      }
    }
  }
  cout << "-1";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  bool codechef = 0;
  long long t = 1;
  if (codechef) cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
