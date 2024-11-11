#include <bits/stdc++.h>
using namespace std;
long long LL_INF = 1LL << 60;
vector<int> isPrime((long long)1e5 + 1, true);
void findPrime(long long n) {
  for (int i = 2; i * i <= n; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= n; j += i) isPrime[j] = false;
    }
  }
  return;
}
set<long long> prime_square;
void precompute_prime_squares() {
  vector<int> is_prime(1000000 + 1, true);
  for (int i = 2; i <= 1e6; i++) {
    if (is_prime[i]) {
      prime_square.insert(i * 1LL * i);
      for (int multiple = 2 * i; multiple <= 1e6; multiple += i)
        is_prime[multiple] = false;
    }
  }
}
void printV(vector<long long> &v) {
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
  return;
}
void inputV(vector<long long> &v) {
  for (int i = 0; i < v.size(); i++) {
    cin >> v[i];
  }
}
bool isPrimeINT(int n) {
  if (n <= 1) return false;
  if (n == 2) {
    return true;
  }
  for (int i = 3; i < n / 2 + 1; i = i + 2)
    if (n % i == 0) return false;
  return true;
}
int interact(int i, int j) {
  cout << "? " << i + 1 << " " << j + 1 << "\n";
  int x;
  cin >> x;
  return x;
}
vector<int> factors(int n) {
  vector<int> v;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      v.push_back(i);
      if (i != n / i) v.push_back(n / i);
    }
  }
  return v;
}
vector<long long> fact(1e6, 1);
void factorial(long long n) {
  for (long long i = 1; i <= n; i++) {
    fact[i] =
        (fact[i - 1] % (long long)1000000007 * i % (long long)1000000007) %
        (long long)1000000007;
  }
}
void check() { cout << "Check\n"; }
long long cost(char &ch1, char &ch2) {
  return min(abs(ch1 - ch2), 26 - abs(ch1 - ch2));
}
void test_case() {
  long long n, m, k = 0, i, j, res = 0, q = 0;
  string s, ans = "";
  cin >> s;
  n = s.size();
  if (n < 3) {
    cout << s;
    return;
  }
  ans += s[0];
  ans += s[1];
  for (i = 2; i < n; i++) {
    if (s[i] == s[i - 1] && s[i] == s[i - 2])
      continue;
    else if (i > 2 && s[i] == s[i - 1]) {
      q = ans.size();
      if (ans[q - 2] == ans[q - 3])
        continue;
      else
        ans += s[i];
    } else
      ans += s[i];
  }
  cout << ans;
  return;
}
int main() {
  long long TT = 1;
  for (long long i = 0; i < TT; i++) {
    test_case();
  }
  return 0;
}
