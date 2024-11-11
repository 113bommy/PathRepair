#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline string tostring(T a) {
  ostringstream os("");
  os << a;
  return os.str();
}
template <typename T>
inline long long tolong(T a) {
  long long res;
  istringstream os(a);
  os >> res;
  return res;
}
template <typename T>
inline vector<int> parse(T str) {
  vector<int> res;
  int s;
  istringstream os(str);
  while (os >> s) res.push_back(s);
  return res;
}
template <class T>
inline T _sqrt(T x) {
  return (T)sqrt((double)x);
}
template <class T>
inline T _bigmod(T n, T m) {
  T ans = 1, mult = n % 1000000007;
  while (m) {
    if (m & 1) ans = (ans * mult) % 1000000007;
    m >>= 1;
    mult = (mult * mult) % 1000000007;
  }
  ans %= 1000000007;
  return ans;
}
template <class T>
inline T _modinv(T x) {
  return _bigmod(x, (T)1000000007 - 2) % 1000000007;
}
inline int len(string a) { return a.length(); }
inline int len(char a[]) { return strlen(a); }
template <class T>
inline T _gcd(T a, T b) {
  return (b == 0) ? a : _gcd(b, a % b);
}
template <class T>
inline T _lcm(T x, T y) {
  return x * y / _gcd(x, y);
}
int main() {
  map<string, int> mp;
  int p = 0;
  int pp = 0;
  for (int i = 0; i < 6; i++) {
    cout << i << endl;
    cout.flush();
    string s;
    getline(cin, s);
    mp[s]++;
    if (s == "great!") p++;
    if (s == "don't think so") p++;
    if (s == "don't touch me!") p++;
    if (s == "not bad") p++;
    if (s == "cool") p++;
    if (s == "don't even") pp++;
    if (s == "are you serious?") pp++;
    if (s == "no way") pp++;
    if (s == "go die in a hole") pp++;
    if (s == "worse") pp++;
    if (s == "terrible") pp++;
  }
  p += mp["no"];
  pp += mp["no"];
  if (p == pp && mp["no"] > 3)
    cout << "normal\n";
  else if (p == pp && mp["no"] <= 3)
    cout << "grumpy\n";
  else if (p > pp)
    cout << "normal\n";
  else
    cout << "grumpy\n";
}
