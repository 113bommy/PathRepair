#include <bits/stdc++.h>
using namespace std;
bool isUpper(char c) { return (c >= 'A' && c <= 'Z'); }
bool isLower(char c) { return (c >= 'a' && c <= 'z'); }
bool iplpha(char c) { return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'); }
bool isnum(char c) { return (c >= '0' and c <= '9'); }
bool isalnum(char c) {
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
         (c >= '0' && c <= '9');
}
char toUpper(char c) { return isUpper(c) ? c : c - 'a' + 'A'; }
char toLower(char c) { return isLower(c) ? c : c + 'a' - 'A'; }
bool isvowel(char c) {
  c = toLower(c);
  return (c == 'a' or c == 'e' or c == 'i' or c == 'i' or c == 'o' or c == 'u');
}
template <typename t>
t gcd(t a, t b) {
  a = abs(a), b = abs(b);
  return ((b == 0) ? a : gcd(b, a % b));
}
template <typename t>
t lcm(t a, t b) {
  return (a * (b / gcd(a, b)));
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
string toLowerCase(string s) {
  for (int i = 0; i < s.size(); i++) {
    if (!isLower(s[i])) {
      s[i] = toLower(s[i]);
    }
  }
  return s;
}
string toUpperCase(string s) {
  for (int i = 0; i < s.size(); i++) {
    s[i] = toUpper(s[i]);
  }
  return s;
}
template <typename T>
void cumulative(T *a, T *b, T n) {
  for (int i = 0; i < n; i++) {
    i ? b[i] = b[i - 1] + a[i] : b[i] = a[i];
  }
}
bool ispal(string s) {
  long long lo, hi;
  lo = 0;
  hi = s.length() - 1;
  while (lo <= hi) {
    if (s[lo] != s[hi]) {
      return 0;
    }
    lo++;
    --hi;
  }
  return 1;
}
template <class T>
string toString(T n) {
  string v = "";
  while (n) {
    v.push_back(n % 10 + '0');
    n /= 10;
  }
  reverse(v.begin(), v.end());
  return v;
}
template <class T>
void fs(T &number) {
  bool negative = false;
  register int c;
  number = 0;
  c = getchar();
  if (c == '-') {
    negative = true;
    c = getchar();
  }
  for (; (c > 47 && c < 58); c = getchar()) number = number * 10 + c - 48;
  if (negative) number *= -1;
}
double areaOfTriangle(double ax, double ay, double bx, double by, double cx,
                      double cy) {
  double ans =
      1.00 * fabs(ax * (by - cy) + bx * (cy - ay) + cx * (ay - by)) / 2.00;
  return ans;
}
int solution() {
  int k;
  cin >> k;
  if (k > 36) {
    cout << -1;
    return 0;
  } else {
    while (k) {
      if (k == 1) {
        cout << 4;
        k -= 1;
      } else {
        cout << 8;
        k -= 2;
      }
    }
  }
  return 0;
}
int main(int argc, char const *argv[]) {
  solution();
  return 0;
}
