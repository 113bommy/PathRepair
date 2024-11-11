#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1}, dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
bool is_prime(long long x) {
  if (x == 1) return false;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return false;
  return true;
}
bool is_palindrome(string s1) {
  int l = s1.length();
  for (int i = 0; i < l / 2; i++)
    if (s1[i] != s1[l - i - 1]) return false;
  return true;
}
unsigned long long C(long long n, long long k) {
  if (k == 0) return 1;
  return (n * C(n - 1, k - 1)) / k;
}
long long modular_pow(long long base, long long exponent, int modulus) {
  long long result = 1;
  while (exponent > 0) {
    if (exponent % 2 == 1) result = (result * base) % modulus;
    exponent = exponent >> 1;
    base = (base * base) % modulus;
  }
  return result;
}
long long binaryToDec(string number) {
  long long result = 0, pow = 1;
  for (int i = number.length() - 1; i >= 0; --i, pow <<= 1)
    result = (result + (number[i] - '0') * pow) % 1000003;
  return result;
}
long long binaryToDec2(string number) {
  long long result = 0, pow = 1;
  int l = number.length();
  for (int i = 0; i < l; ++i, pow <<= 1)
    result = (result + (number[i] - '0') * pow) % 1000003;
  return result;
}
string decimalToBin(int number) {
  if (number == 0) return "0";
  if (number == 1) return "1";
  if (number % 2 == 0)
    return decimalToBin(number / 2) + "0";
  else
    return decimalToBin(number / 2) + "1";
}
unsigned long long GCD(unsigned long long a, unsigned long long b) {
  return b == 0 ? a : GCD(b, a % b);
}
int cntMask(int mask) {
  int ret = 0;
  while (mask) {
    if (mask % 2) ret++;
    mask /= 2;
  }
  return ret;
}
int getBit(int mask, int i) { return ((mask >> i) & 1) == 1; }
int setBit(int mask, int i, int value = 1) {
  return (value) ? mask | (1 << i) : (mask & ~(1 << i));
}
unsigned long long mystoi(string s) {
  unsigned long long ans = 0;
  unsigned long long po = 1;
  for (int i = s.length() - 1; i >= 0; i--) {
    ans += (s[i] - '0') * po;
    po *= 10;
  }
  return ans;
}
string conv(int i) {
  string t = "";
  while (i) {
    t += '0' + (i % 10);
    i /= 10;
  }
  return t;
}
bool hasZero(int i) {
  if (i == 0) return true;
  while (i) {
    if (i % 10 == 0) return true;
    i /= 10;
  }
  return false;
}
bool isSortedAc(int a[], int n) {
  for (int i = 0; i < int(n - 1); i++)
    if (a[i] > a[i + 1]) return false;
  return true;
}
bool isSortedDec(int a[], int n) {
  for (int i = 0; i < int(n - 1); i++)
    if (a[i] < a[i + 1]) return false;
  return true;
}
bool cmp(int i, int j) { return i > j; }
void solveB() {
  int n;
  vector<long long> a;
  int d;
  cin >> n >> d;
  int idx = 0;
  long long cntl = 0, cntr = 0;
  int t = n - 1;
  int total = 0;
  for (int i = 0; i < int(n); i++) {
    int x;
    cin >> x;
    a.push_back(x);
    if (x > d) {
      cntr++;
    } else if (x < d) {
      cntl++;
    } else
      total++;
  }
  sort(a.begin(), a.end());
  long long ans1 = abs(d - a[0]) * 2 + abs(d - a[a.size() - 2]);
  ans1 = min(ans1, abs(d - a[0]) + abs(d - a[a.size() - 2]) * 2);
  long long ans2 = abs(d - a[1]) * 2 + abs(d - a[a.size() - 1]);
  ans2 = min(ans2, abs(d - a[1]) + abs(d - a[a.size() - 1]) * 2);
  ans1 = min(ans1, ans2);
  cout << ans1 << endl;
  return;
}
void solveC() {
  string s;
  cin >> s;
  int len = s.length();
  int f = s.find('a');
  if (f == -1)
    for (int i = 0; i < int(len); i++) {
      cout << char((((s[i] - 'a' - 1) + 26) % 26) + 'a');
    }
  else {
    int i = 0;
    int i1, i2;
    while (i < len && s[i] == 'a') i++;
    if (i == len) {
      s[len - 1] = 'z';
      cout << s << endl;
    } else {
      i1 = i;
      while (i < len && s[i] != 'a') i++;
      for (int j = i1; j < i; j++)
        s[j] = char((((s[j] - 'a' - 1) + 26) % 26) + 'a');
      cout << s << endl;
    }
  }
}
bool check(int i, int j) {
  if (i < 0 || j < 0 || i > 7 || j > 7) return false;
  return true;
}
int main() {
  map<char, int> m;
  for (int i = 0; i < int(8); i++) m[char('a' + i)] = i;
  string s;
  cin >> s;
  int r = int(s[1] - '0');
  int c = m[s[0]];
  int ans = 0;
  for (int i = 0; i < int(8); i++) {
    int u = r + dx[i];
    int v = c + dy[i];
    ans += check(u, v);
  }
  cout << ans << endl;
}
