#include <bits/stdc++.h>
using namespace std;
long long hcf(long long a, long long b) {
  if (b == 0) return a;
  return hcf(b, a % b);
}
long long stringtoll(string s) {
  long long ans = 0;
  for (int i = 0; i < s.length(); i++) ans = ans * 10 + (s[i] - '0');
  return ans;
}
vector<long long> allroot(long long n) {
  vector<long long> ans;
  for (long long i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      ans.push_back(i);
      if (i != n / i) ans.push_back(n / i);
    }
  }
  return ans;
}
bool prime(long long n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long logi(long long n, long long base) { return (log(n) / log(base)); }
long long mulmod(long long a, long long b, long long c) {
  if (b == 0) return 0;
  long long s = mulmod(a, b / 2, c);
  if (b % 2 == 1)
    return (a % c + 2 * (s % c)) % c;
  else
    return (2 * (s % c)) % c;
}
long long factorial(long long n) {
  if (n == 0) return 1;
  return (n * factorial(n - 1)) % 1000000007;
}
bool right(long long val, long long l, long long r) {
  if (val >= l && val <= r) return true;
  return false;
}
bool comp(double a, double b) { return ((double)a < (double)b); }
bool comp2(double a, double b) { return (double(a) > (double)b); }
int sum(int i) {
  int sum = 0;
  while (i > 0) {
    sum = sum + (i % 10);
    i = i / 10;
  }
  return sum;
}
long long gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int main() {
  long long n, m;
  cin >> n >> m;
  long long a[n];
  long long temp = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (temp < a[i]) {
      temp = a[i];
    }
  }
  long long b[100000];
  for (long long i = 0; i < 100000; i++) {
    b[i] = 0;
  }
  for (long long i = 0; i < n; i++) {
    if (a[i] <= 100000) b[a[i]] = 1;
  }
  vector<long long> v;
  long long ans = 0;
  long long sum = 0;
  long long y = 0;
  for (long long i = 1; i <= m; i++) {
    if (b[i] != 1) {
      sum = sum + i;
      if (sum > m) {
        y = 1;
        break;
      }
      ans++;
      v.push_back(i);
    }
    if (y == 1) {
      break;
    }
  }
  cout << ans << endl;
  for (long long i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
}
