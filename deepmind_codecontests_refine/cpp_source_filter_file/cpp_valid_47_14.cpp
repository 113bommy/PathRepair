#include <bits/stdc++.h>
using namespace std;
int cs = 1;
void file();
int dx[] = {+0, +0, -1, +1};
int dy[] = {+1, -1, +0, +0};
int X[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int Y[] = {-1, +1, +0, +0, +1, +1, -1, -1};
int kx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int ky[] = {-1, 1, -2, 2, -2, 2, -1, 1};
bool valid(int r, int c, int n, int m) {
  return (r >= 0 && r < n && c >= 0 && c < m);
}
template <class mpX>
mpX GCD(mpX a, mpX b) {
  return b == 0 ? a : GCD(b, a % b);
}
template <class mpX>
mpX LCM(mpX a, mpX b) {
  return a * (b / GCD(a, b));
}
vector<long long> findPrimeFactors(long long n) {
  vector<long long> primeFactors;
  while (n % 2 == 0) primeFactors.push_back(2), n = n / 2;
  for (long long i = 3; i * i <= n; i = i + 2) {
    while (n % i == 0) {
      primeFactors.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) primeFactors.push_back(n);
  return primeFactors;
}
vector<long long> allDivisiors(long long n) {
  vector<long long> divisors;
  long long limit = sqrt(n + 1);
  for (long long i = 1; i <= limit; i++) {
    if (n % i == 0) {
      if (n / i == i)
        divisors.push_back(i);
      else
        divisors.push_back(i), divisors.push_back(n / i);
    }
  }
  return divisors;
}
bool isPrime(long long n) {
  if (n == 2 or n == 3) return true;
  if (n % 2 == 0) return false;
  for (long long i = 3; i * i <= n; i += 2)
    if (n % i == 0) return false;
  return true;
}
long long nsum(long long n) { return (n * (n + 1)) / 2; }
long long power(long long n, long long p) {
  if (p == 0) return 1;
  if (p == 1) return n;
  long long ans = 1;
  while (p) {
    if (p & 1) ans = ans * n;
    n = n * n;
    p = p / 2;
  }
  return ans;
}
bool isPalindrome(string s) {
  int N = s.size();
  for (int i = 0; i < N / 2; i++) {
    if (s[i] != s[N - 1 - i]) return 0;
  }
  return 1;
}
const int inf = 2000000000;
const long long infLL = 9000000000000000000;
const int lim = 25000;
string to_binary(long long n) {
  string str = "";
  while (n) {
    int d = n % 2;
    str += (d + '0');
    n /= 2;
  }
  while (str.size() < 32) str += '0';
  reverse(str.begin(), str.end());
  return str;
}
long long to_dec(string str) {
  reverse(str.begin(), str.end());
  long long rem = 0;
  for (int i = 0; str[i]; i++) {
    if (str[i] == '1') {
      rem += (pow(2, i));
    }
  }
  return rem;
}
void solve() {
  long long n, k, x;
  string a, b;
  cin >> n >> k;
  vector<string> v;
  cout << "and"
       << " " << 1 << " " << 2 << "\n";
  fflush(stdout);
  cin >> x;
  a = to_binary(x);
  cout << "or"
       << " " << 1 << " " << 2 << "\n";
  fflush(stdout);
  cin >> x;
  b = to_binary(x);
  v.push_back(a), v.push_back(b);
  cout << "and"
       << " " << 1 << " " << 3 << "\n";
  fflush(stdout);
  cin >> x;
  a = to_binary(x);
  cout << "or"
       << " " << 1 << " " << 3 << "\n";
  fflush(stdout);
  cin >> x;
  b = to_binary(x);
  v.push_back(b);
  for (int i = 0; a[i]; i++) {
    if (a[i] == '1') {
      if (v[0][i] == '0') {
        v[0][i] = '1', v[1][i] = '0';
      }
    }
  }
  cout << "and"
       << " " << 2 << " " << 3 << "\n";
  fflush(stdout);
  cin >> x;
  a = to_binary(x);
  cout << "or"
       << " " << 2 << " " << 3 << "\n";
  fflush(stdout);
  cin >> x;
  b = to_binary(x);
  for (int i = 0; a[i]; i++) {
    if (a[i] == '0' && b[i] == '0') {
      if (v[1][i] == '1') v[0][i] = '1', v[1][i] = '0';
      if (v[2][i] == '1') v[0][i] = '1', v[2][i] = '0';
    } else if (a[i] == '0') {
      if (v[1][i] == '1')
        v[2][i] = '0';
      else
        v[2][i] = '1';
    } else if (a[i] == '1') {
      v[1][i] = '1';
      v[2][i] = '1';
    }
  }
  vector<long long> ans;
  for (int i = 4; i <= n; i++) {
    cout << "and"
         << " " << 1 << " " << i << "\n";
    fflush(stdout);
    cin >> x;
    a = to_binary(x);
    cout << "or"
         << " " << 1 << " " << i << "\n";
    fflush(stdout);
    cin >> x;
    b = to_binary(x);
    string tem = "";
    for (int j = 0; j < a[i]; j++) {
      if (a[j] == '1')
        tem += '1';
      else if (a[j] == '0' && b[j] == '0')
        tem += '0';
      else if (b[j] == '1') {
        if (v[0][j] == '1')
          tem += '0';
        else
          tem += '1';
      }
    }
    v.push_back(tem);
  }
  for (auto it : v) {
    ans.push_back(to_dec(it));
  }
  sort(ans.begin(), ans.end());
  cout << "finish " << ans[k - 1] << "\n";
  fflush(stdout);
}
int main() {
  file();
  int t;
  solve();
  return 0;
}
void file() {}
