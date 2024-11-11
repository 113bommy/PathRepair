#include <bits/stdc++.h>
using namespace std;
bool sortbyfir(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.second == b.second) return a.first < b.first;
  return (a.second < b.second);
}
bool sr(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first == b.first)
    return a.second > b.second;
  else
    return a.first < b.first;
}
bool compmx(int a, int b) { return (a < b); }
long long int binaryToDecimal(string n) {
  string num = n;
  long long int dec_value = 0;
  long long int base = 1;
  for (int i = num.length() - 1; i >= 0; i--) {
    if (num[i] == '1') dec_value += base;
    base = base * 2;
  }
  return dec_value;
}
string decimalToBinary(long long int n) {
  string s = bitset<64>(n).to_string();
  const auto loc1 = s.find('1');
  if (loc1 != string::npos) return s.substr(loc1);
  return "0";
}
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b)) * b;
}
bool is_prime(long long int x) {
  if (x == 1) return false;
  if (x == 2 || x == 3) return true;
  for (long long int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}
bool isp(string str) {
  int l = 0, h = str.length() - 1;
  while (h > l)
    if (str[l++] != str[h--]) return false;
  return true;
}
long long int power(long long int a, long long int b) {
  long long int res = 1ll;
  while (b > 0) {
    if (b % 2ll) res = (res * a) % 1000000007;
    ;
    a = (a * a) % 1000000007;
    ;
    b /= 2ll;
  }
  return res;
}
long long int interact(long long int i) {
  cout << i << "\n";
  cout.flush();
  long long int ret;
  cin >> ret;
  cout.flush();
  return ret;
}
vector<long long int> primes;
void getPrimes() {
  vector<bool> p(1001, true);
  for (long long int i = 2; i * i <= 1000; i++) {
    if (p[i]) {
      for (long long int j = i * i; j <= 1000; j += i) {
        p[j] = false;
      }
    }
  }
  for (long long int i = 2; i <= 1000; i++) {
    if (p[i]) {
      primes.push_back(i);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string t, s;
  cin >> t >> s;
  long long int nt = t.length();
  long long int ns = s.length();
  vector<long long int> a(10, 0), b(10, 0);
  for (long long int i = 0; i < ns; i++) {
    if (s[i] == '5')
      a[2]++;
    else if (s[i] == '9')
      a[6]++;
    else
      a[s[i] - '0']++;
  }
  for (long long int i = 0; i < nt; i++) {
    if (t[i] == '5')
      b[2]++;
    else if (t[i] == '9')
      b[6]++;
    else
      b[t[i] - '0']++;
  }
  long long int ans = INT_MAX;
  for (long long int i = 0; i < 10; i++) {
    if (b[i]) {
      ans = min(ans, a[i] / b[i]);
    }
  }
  cout << ans << endl;
  return 0;
}
