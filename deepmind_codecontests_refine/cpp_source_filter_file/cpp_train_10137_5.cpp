#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const int INF = 1000000007;
vector<long long> fact;
vector<int> binaryRepresentation(long long x) {
  vector<int> a(64);
  int i = 0;
  while (x > 0) {
    if (x % 2 == 0)
      a[i] = 0;
    else
      a[i] = 1;
    i++;
    x = x / 2;
  }
  return a;
}
long long fastPow(int x, int y) {
  vector<int> a = binaryRepresentation(y);
  int s = floor(log2(y)) + 1;
  cout << s << endl;
  vector<long long> pows(s);
  pows[0] = x;
  for (int i = 1; i < s; i++) {
    pows[i] = (pows[i - 1] * pows[i - 1]) % MOD;
  }
  for (int i = 0; i < (pows).size(); ++i) cout << pows[i] << " ";
  cout << endl;
  ;
  for (int i = 0; i < (a).size(); ++i) cout << a[i] << " ";
  cout << endl;
  ;
  long long res = 1;
  for (int i = 0; i < s; i++) {
    if (a[i]) res = (res * pows[i]) % MOD;
  }
  return res;
}
int gcd(int a, int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a == b) return a;
  if (a > b) return gcd(a - b, b);
  return gcd(a, b - a);
}
long long comb0(int n) { return fact[n]; }
long long comb1(int n, int k) {
  swap(n, k);
  long long answer = fact[n] / fact[n - k];
  return answer;
}
long long comb2(int n, int k) {
  long long answer = fact[n] / ((fact[n - k] * fact[k]) % MOD);
  return answer;
}
void combInit() {
  fact[0] = 1;
  for (int i = 1; i < fact.size(); i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
}
vector<pair<char, int>> changeFormat(string a) {
  vector<pair<char, int>> s = {{a[0], 1}};
  int k = 1;
  int j = 0;
  for (int i = 1; i < a.size(); i++) {
    if (a[i] == a[i - 1]) {
      s[j].second++;
    } else {
      s.push_back({a[i], 1});
      j++;
    }
  }
  return s;
}
vector<long long> div(long long a) {
  vector<long long> d;
  for (long long i = 1; i <= sqrt(a); i++) {
    if (a % i == 0) {
      d.push_back(i);
      a = a / i;
    }
  }
  if (a != 1) d.push_back(a);
  return d;
}
bool isPalindrom(string s) {
  int n = s.length();
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - i - 1]) return false;
  }
  return true;
}
long long sum(long long k) {
  long long s = (0 + (k) * (k + 1)) / 2;
  return s;
}
int sumOfDigits(long long s) {
  int res = 0;
  while (s > 0) {
    res += s % 10;
    s = s / 10;
  }
  return res;
}
int main() {
  int n;
  string s;
  cin >> n >> s;
  int i = 0;
  while (n > 0) {
    if (n % 2 == 0) {
      cout << s[i] << s[i + 1];
      i += 2;
      n -= 2;
    } else {
      cout << s[i] << s[i + 1] << s[i + 2];
      i += 3;
      n -= 3;
    }
    cout << "-";
  }
}
