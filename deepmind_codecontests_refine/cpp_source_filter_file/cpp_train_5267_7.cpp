#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T mod_v(T num) {
  if (num >= 0)
    return num % 1000000007;
  else
    return (num % 1000000007 + 1000000007) % 1000000007;
}
template <class T>
inline T gcd(T a, T b) {
  a = abs(a);
  b = abs(b);
  while (b) b ^= a ^= b ^= a %= b;
  return a;
}
template <class T>
T fast_pow(T n, T p) {
  if (p == 0) return 1;
  if (p % 2) {
    T g = mod_v(mod_v(n) * mod_v(fast_pow(n, p - 1)));
    return g;
  } else {
    T g = fast_pow(n, p / 2);
    g = mod_v(mod_v(g) * mod_v(g));
    return g;
  }
}
template <class T>
inline T modInverse(T n) {
  return fast_pow(n, 1000000007 - 2);
}
bool equalTo(double a, double b) {
  if (fabs(a - b) <= 1e-9)
    return true;
  else
    return false;
}
bool notEqual(double a, double b) {
  if (fabs(a - b) > 1e-9)
    return true;
  else
    return false;
}
bool lessThan(double a, double b) {
  if (a + 1e-9 < b)
    return true;
  else
    return false;
}
bool lessThanEqual(double a, double b) {
  if (a < b + 1e-9)
    return true;
  else
    return false;
}
bool greaterThan(double a, double b) {
  if (a > b + 1e-9)
    return true;
  else
    return false;
}
bool greaterThanEqual(double a, double b) {
  if (a + 1e-9 > b)
    return true;
  else
    return false;
}
template <class T>
inline int in(register T& num) {
  register char c = 0;
  num = 0;
  bool n = false;
  while (c < 33) c = getchar();
  while (c > 33) {
    if (c == '-')
      n = true;
    else
      num = num * 10 + c - '0';
    c = getchar();
  }
  num = n ? -num : num;
  return 1;
}
int n, k;
int a[2222];
int b[2222];
string names[2222];
int nid;
void colorid(int u) {
  string v = "";
  int tmp = nid;
  for (int i = 0; i < 3; i++) {
    if (i)
      v += (char)(tmp % 26 + 'a');
    else
      v += (char)(tmp % 26 + 'A');
    tmp /= 26;
  }
  names[u] = v;
}
void solve(int u) {
  for (int i = u; i < u + k; i++) {
    if (b[i]) continue;
    colorid(i);
    b[i] = 1;
    nid++;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  nid = 0;
  string s;
  for (int i = 0; i < n; i++) names[i] = "ppp";
  for (int i = 0; i <= n - k; i++) {
    cin >> s;
    if (s == "YES") {
      a[i] = 1;
      solve(i);
    } else {
      a[i] = 0;
      int u = i + k - 1;
      if (b[i] == 0) {
        colorid(i);
        nid++;
        b[i] = 1;
      }
      names[u] = names[i];
      b[u] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << names[i];
  }
  cout << "\n";
  return 0;
}
