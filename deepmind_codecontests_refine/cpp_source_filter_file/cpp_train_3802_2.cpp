#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000 + 7;
const double esp = 1e-13;
const long double PI = acos(-1.0);
long long nhan(long long x, long long y, long long m) {
  long long ans = 0;
  while (y) {
    if (y % 2) ans = (ans + x) % m;
    x = x * 2 % m;
    y /= 2;
  }
  return ans;
}
long long power(long long a, long long n, long long m) {
  unsigned long long ans = 1;
  while (n) {
    if (n % 2) ans = ans * a % m;
    a = a * a % m;
    n /= 2;
  }
  return ans;
}
bool isPrime(long long n) {
  if (n == 2) return true;
  if (n < 2 || n % 2 == 0) return false;
  long long p[3] = {3, 5, 7};
  long long a, d;
  int r, s;
  d = n - 1;
  s = 0;
  while (d % 2 == 0) {
    d /= 2;
    s++;
  }
  for (int i = 0; i <= 2; i++) {
    if (n == p[i]) return true;
    if (n % p[i] == 0) return false;
    a = power(p[i], d, n);
    if (a != 1) {
      for (r = 0; r < s && a != n - 1; r++) a = a * a % n;
      if (r == s) return false;
    }
  }
  return true;
}
long long phi(long long n) {
  long long ans = n;
  long long n2 = (long long)sqrt(n);
  for (int i = 2; i <= n2; i++)
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      ans -= ans / i;
    }
  if (n > 1) ans -= ans / n;
  return ans;
}
vector<int> readData(string str) {
  vector<int> vec;
  stringstream ss;
  int num;
  ss << str;
  while (ss >> num) vec.push_back(num);
  return vec;
}
string convert(string n, int sink, int des) {
  long long so = 0;
  string ans = "";
  for (long long i = 0; i < n.length(); i++) {
    long long vt;
    if (n[i] <= '9')
      vt = n[i] - '0';
    else
      vt = n[i] + 10 - 'A';
    so = so * sink + vt;
  }
  while (so > 0) {
    long long vt = so % des;
    if (vt < 10)
      ans = (char)(vt + 48) + ans;
    else
      ans = char(vt + 'A' - 10) + ans;
    so /= des;
  }
  return ans;
}
void makeTest() { srand(time(0)); }
map<int, int> f;
int dem, n, cur;
int a[300000 + 10], x[300000 + 10], y[300000 + 10];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cur = 1;
  for (int i = 1; i <= n; i++) {
    f[a[i]]++;
    if (f[a[i]] == 2) {
      x[++dem] = cur;
      y[dem] = i;
      cur = i + 1;
      f.clear();
    }
  }
  if (f.size())
    cout << -1;
  else {
    cout << dem << "\n";
    y[dem] = n;
    for (int i = 1; i <= dem; i++) cout << x[i] << " " << y[i] << "\n";
  }
}
