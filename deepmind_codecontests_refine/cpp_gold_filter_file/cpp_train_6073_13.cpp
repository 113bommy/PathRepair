#include <bits/stdc++.h>
using namespace std;
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
inline T sqr(T x) {
  return x * x;
}
template <class T>
T power(T N, T P) {
  return (P == 0) ? 1 : N * power(N, P - 1);
}
template <class T>
bool inside(T a, T b, T c) {
  return (b >= a && b <= c);
}
const long long INF64 = (long long)1E16;
int distsq2d(int x1, int y1, int x2, int y2) {
  return sqr(x1 - x2) + sqr(y1 - y2);
}
double dist2d(double x1, double y1, double x2, double y2) {
  return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}
double dist3d(double x1, double y1, double z1, double x2, double y2,
              double z2) {
  return sqrt(sqr(x1 - x2) + sqr(y1 - y2) + sqr(z1 - z2));
}
long long toInt64(string s) {
  long long r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
double LOG(long long N, long long B) { return (log10l(N)) / (log10l(B)); }
string itoa(long long a) {
  if (a == 0) return "0";
  string ret;
  for (long long i = a; i > 0; i = i / 10) ret.push_back((i % 10) + 48);
  reverse(ret.begin(), ret.end());
  return ret;
}
vector<string> token(string a, string b) {
  const char *q = a.c_str();
  while (count(b.begin(), b.end(), *q)) q++;
  vector<string> oot;
  while (*q) {
    const char *e = q;
    while (*e && !count(b.begin(), b.end(), *e)) e++;
    oot.push_back(string(q, e));
    q = e;
    while (count(b.begin(), b.end(), *q)) q++;
  }
  return oot;
}
int isvowel(char s) {
  s = tolower(s);
  if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') return 1;
  return 0;
}
int isupper(char s) {
  if (s >= 'A' and s <= 'Z') return 1;
  return 0;
}
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
int check(int N, int pos) { return (N & (1 << pos)); }
int toggle(int N, int pos) {
  if (check(N, pos)) return N = reset(N, pos);
  return N = Set(N, pos);
}
void pbit(int N) {
  printf("(");
  for (int i = 10; i >= 0; i--) {
    bool x = check(N, i);
    cout << x;
  }
  puts(")");
}
int fx[] = {0, 0, 1, -1};
int fy[] = {1, -1, 0, 0};
bool status[30000002];
vector<int> v;
void siv() {
  int N = 20000002;
  int sq = sqrt(N);
  for (int i = 3; i <= sq; i += 2) {
    if (status[i] == 0) {
      for (int j = i * i; j <= N; j += i) status[j] = 1;
    }
  }
  int c = 1;
  for (int i = 3; i <= 1100000; i += 2) {
    if (status[i] == 0) {
      char s[20];
      sprintf(s, "%d", i);
      reverse(s, s + strlen(s));
      int r = atoi(s);
      if (i != r) {
        if (r == 2 or (r % 2 == 1 and status[r] == 0)) {
          ++c;
          v.push_back(i);
        }
      }
    }
  }
}
int main() {
  siv();
  int n;
  cin >> n;
  cout << v[n - 1] << endl;
}
