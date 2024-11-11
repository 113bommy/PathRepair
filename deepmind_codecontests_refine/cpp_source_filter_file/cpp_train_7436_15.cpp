#include <bits/stdc++.h>
using namespace std;
bool greater(long long a, long long b) { return (a > b); }
bool is_prime(long long x) {
  if (x < 2) return 0;
  for (long long i = 2; i <= (int)sqrtl((x + 1) * 1.0); i++) {
    if (x % i == 0) return 0;
  }
  return true;
}
vector<long long> a;
vector<bool> b(1000000, 0);
vector<bool> mat(1000000, 0);
void generate_primes(long long n) {
  a.clear();
  b[2] = true;
  for (int i = 3; i * i <= n; i += 2) {
    if (mat[i] == 0) {
      for (int j = i * i; j < n; j += 2 * i) mat[j] = 1;
    }
  }
  for (int i = 3; i <= n; i += 2)
    if (!mat[i]) b[i] = 1;
}
bool yesOrNot(long long x) {
  if (x <= 3) return 0;
  if (x == 4) return 1;
  long long res = 0;
  for (int i = 0; i < a.size(); i++) {
    if (x % a[i] == 0) res += x / a[i];
    if (res > 2) return 0;
    if (a[i] > (x / 2)) break;
  }
  if (res == 2) return 1;
  return 0;
}
int main() {
  int n, k, f;
  string s;
  cin >> n >> k;
  cin >> s;
  if (k > n - k) {
    for (int i = 0; i < n - k; i++) {
      cout << "RIGHT\n";
    }
    for (int i = s.length() - 1; i >= 1; i--) {
      cout << "PRINT " << s[i] << "\nLEFT\n";
    }
    cout << "PRINT " << s[0];
  } else {
    for (int i = 0; i < k; i++) {
      cout << "LEFT\n";
    }
    for (int i = 0; i < s.length() - 1; i++) {
      cout << "PRINT " << s[i] << "\nRIGHT\n";
    }
    cout << "PRINT " << s[n - 1];
  }
  return 0;
}
