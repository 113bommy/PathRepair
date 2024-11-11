#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
template <class T>
void out(const vector<T> &a) {
  cout << "array: ";
  for (int i = 0; i < (int)a.size(); i++) cout << a[i] << " ";
  cout << endl;
  cout.flush();
}
void binprint(int mask, int n) {
  int i;
  string s = "";
  do {
    s += (mask % 2 + '0');
    mask /= 2;
  } while (mask);
  reverse(s.begin(), s.end());
  s = string((n - (int)s.size() > 0 ? n - (int)s.size() : 0), '0') + s;
  for (i = (int)s.size() - n; i < (int)s.size(); i++) printf("%c", s[i]);
  printf("\n");
}
void ASCII_Chart() {
  int i, j, k;
  printf("ASCII Chart:(30-129)\n");
  for (i = 30; i <= 50; i++) {
    for (j = 0; j < 5; j++) {
      k = i + j * 20;
      printf("%3d---> '%c'   ", k, k);
    }
    printf("\n");
  }
}
template <class T>
inline T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / gcd(a, b));
}
template <class T>
T Abs(T x) {
  return x > 0 ? x : -x;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline T Mod(T n, T m) {
  return (n % m + m) % m;
}
int BigMod(long long B, long long P, long long M) {
  long long R = 1;
  while (P > 0) {
    if (P % 2 == 1) {
      R = (R * B) % M;
    }
    P /= 2;
    B = (B * B) % M;
  }
  return (int)R;
}
long long mulmod(long long a, long long b, long long c) {
  long long x = 0, y = a % c;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x + y) % c;
    }
    y = (y * 2) % c;
    b /= 2;
  }
  return x % c;
}
long long mpow(long long x, long long k) {
  if (k == 0) return 1;
  long long r = mpow(x, k / 2);
  return k % 2 ? (r * r * x) : (r * r);
}
template <class T>
inline vector<pair<T, int> > factorize(T n) {
  vector<pair<T, int> > R;
  for (T i = 2; n > 1;) {
    if (n % i == 0) {
      int C = 0;
      for (; n % i == 0; C++, n /= i)
        ;
      R.push_back(make_pair(i, C));
    }
    i++;
    if (i > n / i) i = n;
  }
  if (n > 1) R.push_back(make_pair(n, 1));
  return R;
}
vector<string> SubstringGenerate(string str) {
  int i, j, len;
  vector<string> store;
  len = (int)str.size();
  for (i = 0; i < len; i++)
    for (j = i; j <= len; j++) store.push_back(str.substr(i, j - i + 1));
  return store;
}
template <class T>
inline bool isPrime(T n) {
  if (n <= 1) return false;
  for (T i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
bool IsVowel(char ch) {
  ch = tolower(ch);
  if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    return true;
  return false;
}
bool isUpperCase(char c) { return c >= 'A' && c <= 'Z'; }
bool isLowerCase(char c) { return c >= 'a' && c <= 'z'; }
bool isLetter(char c) { return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'; }
bool isDigit(char c) { return c >= '0' && c <= '9'; }
double deg2rad(double x) { return (PI * x) / 180.0; }
double rad2deg(double x) { return (180.0 * x) / PI; }
template <class T>
string toString(T n) {
  ostringstream oss;
  oss << n;
  oss.flush();
  return oss.str();
}
int toInt(string s) {
  int r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
long long toLl(string s) {
  long long r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
double toDouble(string s) {
  double r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
template <typename T>
static void splitstr(const string &s, vector<T> &out) {
  istringstream in(s);
  out.clear();
  copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}
template <class T>
void debug(T e) {
  cout << e << endl;
}
template <class T1, class T2>
void debug(T1 e1, T2 e2) {
  cout << e1 << "\t" << e2 << endl;
}
template <class T1, class T2, class T3>
void debug(T1 e1, T2 e2, T3 e3) {
  cout << e1 << "\t" << e2 << "\t" << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void debug(T1 e1, T2 e2, T3 e3, T4 e4) {
  cout << e1 << "\t" << e2 << "\t" << e3 << "\t" << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void debug(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cout << e1 << "\t" << e2 << "\t" << e3 << "\t" << e4 << "\t" << e5 << endl;
}
template <class T>
void debug(vector<T> e) {
  int i;
  for (i = 0; i < (int)e.size(); i++) cout << e[i] << " ";
  cout << endl;
}
template <class T>
void debug(vector<T> e, int n) {
  int i;
  for (i = 0; i < n; i++) cout << e[i] << " ";
  cout << endl;
}
template <class T>
void debug(vector<basic_string<T> > e) {
  int i, j;
  for (i = 0; i < (int)e.size(); i++) {
    for (j = 0; j < (int)e[i].size(); j++) cout << e[i][j];
    cout << endl;
  }
  cout << endl;
}
template <class T>
void debug(vector<basic_string<T> > e, int row, int col) {
  int i, j;
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) cout << e[i][j];
    cout << endl;
  }
  cout << endl;
}
template <class T>
void debug(vector<vector<T> > e, int row, int col) {
  int i, j;
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) cout << e[i][j] << "\t";
    cout << endl;
  }
  cout << endl;
}
template <class T>
void debug(T e[1000000][1000000], int row, int col) {
  int i, j;
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) cout << e[i][j] << " ";
    cout << endl;
  }
}
template <class T>
void debug(T e[], int row) {
  int i;
  for (i = 0; i < row; i++) cout << e[i] << " ";
  cout << endl;
}
vector<vector<int> > v;
int binS(int in, int r) {
  int l, h, m;
  l = 0;
  h = (int)v[in].size();
  if (h == 0) return -1;
  m = (l + h) / 2;
  while (h > l) {
    m = (l + h) / 2;
    if (v[in][m] > r)
      h = m - 1;
    else
      l = m + 1;
  }
  return m;
}
int main() {
  string s1, s2;
  int l1, l2, i, j, cnt, in, c, rp, rr;
  bool f, ch;
  vector<int> v1;
  v1.clear();
  cin >> s1 >> s2;
  l1 = (int)s1.size();
  l2 = (int)s2.size();
  for (i = 0; i < 27; i++) v.push_back(v1);
  for (i = 0; i < l1; i++) {
    v[s1[i] - 'a'].push_back(i);
  }
  rp = 0;
  rr = 0;
  cnt = 1;
  f = 1;
  for (i = 0; i < l2; i++) {
    c = s2[i] - 'a';
    in = binS(s2[i] - 'a', rp);
    if (in == -1) {
      f = 0;
      break;
    }
    if (in > 0) in -= 1;
    if (in > 0) in -= 1;
    ch = false;
    for (j = in; j <= (int)v[c].size() - 1; j++) {
      if (v[c][j] > rp) {
        rr = v[c][j];
        ch = true;
        break;
      }
    }
    if (!ch) rr = v[c][0];
    if (i != 0) {
      if (rr <= rp) cnt++;
    }
    rp = rr;
  }
  if (!f)
    cout << "-1" << endl;
  else
    cout << cnt << endl;
  return 0;
}
