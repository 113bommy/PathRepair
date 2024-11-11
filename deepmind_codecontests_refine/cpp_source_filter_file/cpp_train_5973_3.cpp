#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1E9 + 5;
const long long LINF = (long long)4E18 + 5;
const long double PI = acos(-1.0);
const long double E = 2.718281828459045L;
const double EPS = 1.0e-9;
void debugarr(int* arr, int n) {
  cout << "[";
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << "]" << endl;
}
template <typename T>
T gcd(T a, T b) {
  return (b == 0) ? abs(a) : gcd(b, a % b);
}
template <typename T>
inline T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <typename T>
inline T mod(T a, T b) {
  return (a % b + b) % b;
}
template <typename T>
inline T sqr(T x) {
  return x * x;
}
template <typename T>
inline string tostring(const T& x) {
  ostringstream os;
  os << x;
  return os.str();
}
inline int toint(const string& s) {
  istringstream is(s);
  int x;
  is >> x;
  return x;
}
inline long double todouble(const string& s) {
  istringstream is(s);
  long double x;
  is >> x;
  return x;
}
inline string tolower(string s) {
  for (typeof((s).begin()) it = (s).begin(); it != (s).end(); ++it)
    *it = tolower(*it);
  return s;
}
inline string toupper(string s) {
  for (typeof((s).begin()) it = (s).begin(); it != (s).end(); ++it)
    *it = toupper(*it);
  return s;
}
inline int todecimal(string s) {
  int a = 0;
  for (int i = 0; i < (s.size()); i++) a = 2 * a + (s[i] - '0');
  return a;
}
inline string tobinary(int a) {
  string s;
  while (a != 0) {
    s = (char)(a % 2 + '0') + s;
    a >>= 1;
  }
  return s;
}
inline int isvowel(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
  return 0;
}
inline int isprime(int a) {
  for (int i = 2; i * i <= a; i++)
    if (!(a % i)) return 0;
  return 1;
}
struct st {
  int a;
  int b;
  int c;
};
bool compare(const st& x, const st& y) { return x.a > y.a; }
int n;
string s[101];
string convert(string a) {
  vector<string> v;
  string x1, x2, y, ans;
  int ac = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] != ':') {
      y += a[i];
    } else if (i < n - 1 && a[i] == ':' && a[i + 1] == ':') {
      if (y != "\0") {
        while (y.size() != 4) y = "0" + y;
        y += ':';
      }
      x1 += y;
      i++;
      ac = 1;
      y = "\0";
    } else {
      if (y != "\0") {
        while (y.size() != 4) y = "0" + y;
        y += ':';
      }
      if (!ac)
        x1 += y;
      else
        x2 += y;
      y = "\0";
    }
  }
  if (y != "\0") {
    while (y.size() != 4) y = "0" + y;
    y += ':';
  }
  x2 += y;
  int l = x1.size() + x2.size();
  for (int i = 0; i < (40 - l) / 5; i++) {
    x1 += "0000:";
  }
  ans = ans + x1;
  ans += x2;
  ans.erase(39, 1);
  return ans;
}
void solve() {
  string ans[101];
  for (int i = 0; i < (n); i++) ans[i] = convert(s[i]);
  for (int i = 0; i < (n); i++) cout << ans[i] << endl;
}
void input() {
  cin >> n;
  for (int i = 0; i < (n); i++) cin >> s[i];
}
int main() {
  int t = 1;
  for (int i = 1; i <= t; i++) {
    input();
    solve();
  }
  return 0;
}
