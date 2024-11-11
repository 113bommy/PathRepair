#include <bits/stdc++.h>
using namespace std;
struct vec {
  long double x, y;
  bool operator==(const vec &a) const { return x == a.x && y == a.y; }
  bool operator<(const vec &a) const {
    if (a.x != x) return x < a.x;
    return y < a.y;
  }
  vec operator+(const vec &a) const { return {x + a.x, y + a.y}; }
  vec operator*(const long double &a) const { return {x * a, y * a}; }
  vec operator-(const vec &a) const { return {x - a.x, y - a.y}; }
  vec operator/(const long double &a) const { return {x / a, y / a}; }
  long double len() const { return (x * x + y * y); }
  long double dot(const vec &a) const { return x * a.x + y * a.y; }
  long double crs(const vec &a) const { return x * a.y - y * a.x; }
  vec proj(const vec &a) const {
    return (a / a.len()) * (*this).dot(a) / a.len();
  }
};
struct P {
  int x, y;
  bool operator<(const P &a) const { return x > a.x; }
};
long long x, y, z, mod = 1000000007;
vector<int> v[111111], v1[111111];
int i, n, m, k, a, d, b, c, h, dx[10] = {1, 0, -1, 0}, dy[10] = {0, 1, 0, -1};
int e;
int l[111111];
char o[111111];
int j[111112];
stack<int> s;
queue<int> q, q1;
P u[1], u1[3];
char r[1], r1[3];
map<int, int> p;
bool as(P a, P b) { return a.y < b.y; }
int g(int n, int a, int b) {
  for (int t = 1; t < n; t++) printf("%c", o[t]);
  for (int t = 1; t <= a; t++) printf("a");
  for (int t = 1; t <= b; t++) printf("b");
  puts("");
  fflush(stdout);
  int k = 0;
  scanf("%d", &k);
  if (k == 0) exit(0);
  return k;
}
void f(int n, int a, int b, int d) {
  if (a == 0) {
    g(n, a, b);
    return;
  }
  if (b == 0) {
    g(n, a, b);
    return;
  }
  o[n] = 'a';
  o[n + 1] = 'b';
  int p = g(n + 2, k - 1 - n, 0);
  o[n] = 'b';
  o[n + 1] = 'a';
  int q = g(n + 2, k - 1 - n, 0), e = d;
  o[n] = o[n + 1] = 'a';
  if (p < d)
    o[n + 1] = 'b', b--, e--;
  else
    a--;
  if (q < d)
    o[n] = 'b', b--, e--;
  else
    a--;
  f(n + 2, a, b, e);
}
int main() {
  for (int t = 1; t <= 300; t++) printf("a");
  puts("");
  fflush(stdout);
  scanf("%d", &a);
  if (a == 0) return 0;
  a = 300 - a;
  for (int t = 1; t <= 300; t++) printf("b");
  puts("");
  fflush(stdout);
  scanf("%d", &b);
  if (b == 0) return 0;
  b = 300 - b;
  k = a + b;
  f(1, a, b, b);
}
