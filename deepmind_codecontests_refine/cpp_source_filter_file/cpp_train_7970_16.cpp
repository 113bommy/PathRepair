#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
long long a, b, c, k, sum, sum2, sum3, sum4, i, j, n;
template <typename T>
T Abs(T a) {
  if (a < 0)
    return -a;
  else
    return a;
}
template <typename T>
T BigMod(T b, T p, T m) {
  if (p == 0) return 1;
  if (p % 2 == 0) {
    T s = BigMod(b, p / 2, m);
    return ((s % m) * (s % m)) % m;
  }
  return ((b % m) * (BigMod(b, p - 1, m) % m)) % m;
}
template <typename T>
T Pow(T B, T P) {
  if (P == 0) return 1;
  if (P & 1)
    return B * Pow(B, P - 1);
  else
    return (Pow(B, P / 2) * Pow(B, P / 2));
}
template <typename T>
T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <typename T>
T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / gcd(a, b));
}
template <typename T>
T exgcd(T a, T b, T &x, T &y) {
  if (a < 0) {
    T d = exgcd(-a, b, x, y);
    x = -x;
    return d;
  }
  if (b < 0) {
    T d = exgcd(a, -b, x, y);
    y = -y;
    return d;
  }
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    T d = exgcd(b, a % b, x, y);
    T t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
  }
}
char uplowch(char ch) {
  if (ch >= 'A' && ch <= 'Z') ch += 32;
  return ch;
}
char lowupch(char ch) {
  if (ch >= 'a' && ch <= 'z') ch -= 32;
  return ch;
}
bool isalpha(char ch) {
  if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) return true;
  return false;
}
int strtoint(string str) {
  stringstream ss(str);
  int x = 0;
  ss >> x;
  return x;
}
string intostr(int x) {
  stringstream ss;
  ss << x;
  string str = ss.str();
  return str;
}
vector<string> linetostr(string str) {
  string s;
  vector<string> v;
  istringstream is(str);
  while (is >> s) v.push_back(s);
  return v;
}
void sf(int &x) { scanf("%d", &x); }
void sf(long long &x) { scanf("%lld", &x); }
void sf(long long &x, long long &y) { scanf("%lld%lld", &x, &y); }
void sf(float &x) { scanf("%f", &x); }
void sf(double &x) { scanf("%lf", &x); }
void sf(int &x, int &y) { scanf("%d%d", &x, &y); }
void sf(float &x, float &y) { scanf("%f%f", &x, &y); }
void sf(double &x, double &y) { scanf("%lf%lf", &x, &y); }
void sf(double &x, double &y, double &z) { scanf("%lf%lf%lf", &x, &y, &z); }
void sf(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void sf(long long &x, long long &y, long long &z) {
  scanf("%lld%lld%lld", &x, &y, &z);
}
void sf(float &x, float &y, float &z) { scanf("%f%f%f", &x, &y, &z); }
void sf(char &x) { x = getchar(); }
void sf(char *s) { scanf("%s", s); }
void sf(string &s) { cin >> s; }
void pf(int x) { printf("%d\n", x); }
void pf(int x, int y) { printf("%d %d\n", x, y); }
void pf(int x, int y, int z) { printf("%d %d %d\n", x, y, z); }
void pf(long long x) { printf("%lld\n", x); }
void pf(long long x, long long y) { printf("%lld %lld\n", x, y); }
void pf(long long x, long long y, long long z) {
  printf("%lld %lld %lld\n", x, y, z);
}
void pf(float x) { printf("%f\n", x); }
void pf(double x) { printf("%.9lf\n", x); }
void pf(double x, double y) { printf("%.5lf %.5lf\n", x, y); }
void pf(char x) { printf("%c\n", x); }
void pf(char *x) { printf("%s\n", x); }
void pf(string x) { cout << x << endl; }
int main() {
  sf(n, k);
  a = 240 - k;
  sum = 0;
  for (i = 1; i <= n; i++) {
    sum += (n * i);
    if (sum > a) break;
  }
  pf(i - 1);
  return 0;
}
