#include <bits/stdc++.h>
using namespace std;
bool isSubSequence(string str1, string str2, int m, int n);
int CEIL(int a, int b);
bool isPrime(int x);
int mod_exp(long long x, unsigned int y, int p);
int gcd(int a, int b);
vector<int> Divisors(int n);
int getMSB(int n);
void sayyes() { cout << "YES" << '\n'; }
void sayno() { cout << "NO" << '\n'; }
void solve() {
  long long int p;
  cin >> p;
  cout << 2 << " " << p - 1 << '\n';
}
int main() {
  auto start = std::chrono::system_clock::now();
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  return 0;
}
bool isSubSequence(string str1, string str2, int m, int n) {
  int j = 0;
  for (int i = 0; i < n && j < m; i++) {
    if (str1[j] == str2[i]) j++;
  }
  return (j == m);
}
int CEIL(int a, int b) {
  if (a % b == 0)
    return a / b;
  else
    return (a / b) + 1;
}
bool isPrime(int x) {
  if (x <= 1) return false;
  for (int i = 2, sqroot = sqrt(x); i <= sqroot; i++)
    if (x % i == 0) return false;
  return true;
}
int mod_exp(long long x, unsigned int y, int p) {
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
vector<int> Divisors(int n) {
  vector<int> div;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        div.push_back(i);
      else {
        div.push_back(i);
        div.push_back(n / i);
      }
    }
  }
  return div;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int getMSB(int n) {
  if (n == 0) return 0;
  int msb = 0;
  n = n / 2;
  while (n != 0) {
    n = n / 2;
    msb++;
  }
  return msb;
}
