#include <bits/stdc++.h>
const double EPS = 1e-9;
const long long MOD = 1000000007;
const int INF = 2000 * 1000 * 1000 + 5;
const int MAX = 1005;
using namespace std;
int popcount(int n) {
  bitset<32> b(n);
  return b.count();
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) {
  long long temp = gcd(a, b);
  return temp ? (a / temp * b) : 0;
}
template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}
inline bool isInteger(const std::string& s) {
  if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
    return false;
  char* p;
  strtol(s.c_str(), &p, 10);
  return (*p == 0);
}
int main() {
  int n;
  cin >> n;
  vector<string> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  string s;
  cin >> s;
  string slower = s;
  for (int i = 0; i < slower.length(); i++) slower[i] = tolower(s[i]);
  vector<bool> b(s.length());
  char letter;
  cin >> letter;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < v[i].length(); j++) v[i][j] = tolower(v[i][j]);
    int pos = slower.find(v[i]);
    while (pos != -1) {
      for (int j = 0; j < v[i].length(); j++) b[pos + j] = 1;
      pos = s.find(v[i], pos + 1);
    }
  }
  for (int i = 0; i < s.length(); i++) {
    if (b[i]) {
      if (tolower(s[i]) != tolower(letter))
        if (islower(s[i]))
          s[i] = tolower(letter);
        else
          s[i] = toupper(letter);
      else if (tolower(s[i]) == tolower(letter) && tolower(letter) != 'a')
        if (islower(s[i]))
          s[i] = 'a';
        else
          s[i] = 'A';
      else if (islower(s[i]))
        s[i] = 'b';
      else
        s[i] = 'B';
    }
  }
  cout << s << endl;
  return 0;
}
