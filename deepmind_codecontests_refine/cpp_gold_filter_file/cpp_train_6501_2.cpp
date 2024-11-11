#include <bits/stdc++.h>
using namespace std;
void RD(int &x) { scanf("%d", &x); }
void RD(unsigned int &x) { scanf("%u", &x); }
void RD(double &x) { scanf("%lf", &x); }
void RD(int &x, int &y) { scanf("%d%d", &x, &y); }
void RD(unsigned int &x, unsigned int &y) { scanf("%u%u", &x, &y); }
void RD(double &x, double &y) { scanf("%lf%lf", &x, &y); }
void RD(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void RD(unsigned int &x, unsigned int &y, unsigned int &z) {
  scanf("%u%u%u", &x, &y, &z);
}
void RD(double &x, double &y, double &z) { scanf("%lf%lf%lf", &x, &y, &z); }
void RD(char &x) { x = getchar(); }
void RD(char *s) { scanf("%s", s); }
void RD(string &s) { cin >> s; }
void PR(int x) { printf("%d\n", x); }
void PR(int x, int y) { printf("%d %d\n", x, y); }
void PR(unsigned int x) { printf("%u\n", x); }
void PR(unsigned long long x) { cout << x << endl; }
void PR(double x) { printf("%.4lf\n", x); }
void PR(char x) { printf("%c\n", x); }
void PR(char *x) { printf("%s\n", x); }
void PR(string x) { cout << x << endl; }
void PR(long long x) { cout << x << endl; }
void upMin(int &x, int y) {
  if (x > y) x = y;
}
void upMin(long long &x, long long y) {
  if (x > y) x = y;
}
void upMin(double &x, double y) {
  if (x > y) x = y;
}
void upMax(int &x, int y) {
  if (x < y) x = y;
}
void upMax(long long &x, long long y) {
  if (x < y) x = y;
}
void upMax(double &x, double y) {
  if (x < y) x = y;
}
int sgn(double x) {
  if (x > 1e-10) return 1;
  if (x < -1e-10) return -1;
  return 0;
}
long long Gcd(long long x, long long y) {
  if (x < 0) x = -x;
  if (y < 0) y = -y;
  if (y == 0) return x;
  return Gcd(y, x % y);
}
long long Lcm(long long x, long long y) { return x / Gcd(x, y) * y; }
long long eular(long long n) {
  long long ans = n, i;
  for (i = 2; i * i <= n; i++)
    if (n % i == 0) {
      ans -= ans / i;
      while (n % i == 0) n /= i;
    }
  if (n > 1) ans -= ans / n;
  return ans;
}
long long exGcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long temp = exGcd(b, a % b, x, y);
  long long t = x;
  x = y;
  y = t - a / b * y;
  return temp;
}
long long gcdReverse(long long a, long long b) {
  long long x, y;
  long long g = exGcd(a, b, x, y);
  if (g != 1) return 0;
  x %= b;
  if (x < 0) x += b;
  return x;
}
long long myPow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}
long long myPow(long long a, long long b, long long mod) {
  a %= mod;
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
long long getInt() {
  long long x = 0, flag = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') {
    flag = -1, c = getchar();
    while (!isdigit(c)) c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * flag;
}
long long getSqrt(long long t) {
  long long p = sqrt(1.0 * t);
  while (p * p > t) p--;
  while ((p + 1) <= t / (p + 1)) p++;
  return p;
}
struct point {
  double x, y;
  point() {}
  point(double _x, double _y) {
    x = _x;
    y = _y;
  }
  void get() { scanf("%lf%lf", &x, &y); }
  point operator+(point a) { return point(x + a.x, y + a.y); }
  point operator-(point a) { return point(x - a.x, y - a.y); }
  point operator*(double t) { return point(x * t, y * t); }
  double operator*(point a) { return x * a.y - y * a.x; }
  double operator^(point a) { return x * a.x + y * a.y; }
  double Len() { return sqrt(x * x + y * y); }
  point adjustTo(double L) {
    L /= Len();
    return point(x * L, y * L);
  }
  point operator/(double t) { return point(x / t, y / t); }
  double rotateAngle(point a) {
    point p = *this;
    return atan2(p * a, p ^ a);
  }
  int operator==(point a) { return sgn(x - a.x) == 0 && sgn(y - a.y) == 0; }
  point zhuanNi(double ang) {
    return point(x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang));
  }
  point zhuanShun(double ang) {
    return point(x * cos(ang) + y * sin(ang), -x * sin(ang) + y * cos(ang));
  }
  void print() { printf("%.4lf %.4lf\n", x, y); }
};
double calPloyArea(point a[], int n) {
  double ans = 0;
  int i;
  for (i = 0; i < n; i++) ans += a[i] * a[(i + 1) % n];
  return ans;
}
int changeToClockwise(point a[], int n) {
  double s = calPloyArea(a, n);
  if (sgn(s) >= 0) return 0;
  int L = 0, R = n - 1;
  while (L < R) swap(a[L++], a[R--]);
  return 1;
}
int pointOnSeg(point p, point a, point b) {
  if (sgn((p - a) * (p - b))) return 0;
  int x = sgn((p.x - a.x) * (p.x - b.x));
  int y = sgn((p.y - a.y) * (p.y - b.y));
  return x <= 0 && y <= 0;
}
int pointOnRightOfLine(point p, point a, point b) {
  return sgn((p - a) * (b - a)) > 0;
}
int pointOnLine(point p, point a, point b) {
  return sgn((p - a) * (b - a)) == 0;
}
int pointOnLeftOfLine(point p, point a, point b) {
  return sgn((b - a) * (p - a)) > 0;
}
int getRelationOfPointAndPloy(point a[], int n, point p) {
  a[n] = a[0];
  int i;
  double sum = 0;
  for (i = 0; i < n; i++) {
    if (pointOnSeg(p, a[i], a[i + 1])) return 0;
    point aa = a[i] - p;
    point bb = a[i + 1] - p;
    sum += aa.rotateAngle(bb);
  }
  if (fabs(sum - 2 * acos(-1.0)) < 1e-2) return -1;
  return 1;
}
int isParal(point a, point b, point p, point q) {
  double aa = (b.x - a.x) * (p.y - q.y);
  double bb = (b.y - a.y) * (p.x - q.x);
  return sgn(aa - bb) == 0;
}
int lineCrossLine(point a, point b, point p, point q, point &ans) {
  if (isParal(a, b, p, q)) {
    if (!pointOnLine(p, a, b)) return 0;
    return 2;
  }
  double s1 = (p - a) * (q - a);
  double s2 = (q - b) * (p - b);
  ans = (a * s2 + b * s1) / (s1 + s2);
  return 1;
}
int segCrossSeg(point a, point b, point p, point q, point &ans) {
  if (isParal(a, b, p, q)) {
    if (!pointOnLine(p, a, b)) return 0;
    if (sgn(a.x - b.x) == 0) {
      if (p.y > q.y) swap(p, q);
      if (a.y > b.y) swap(a, b);
      if (sgn(q.y - a.y) == -1 || sgn(b.y - p.y) == -1) return 0;
      if (q == a || p == b) {
        if (q == a) ans = q;
        if (p == b) ans = p;
        return 1;
      }
      return 2;
    }
    if (p.x > q.x) swap(p, q);
    if (a.x > b.x) swap(a, b);
    if (sgn(q.x - a.x) == -1 || sgn(b.x - p.x) == -1) return 0;
    if (q == a || p == b) {
      if (q == a) ans = q;
      if (p == b) ans = p;
      return 1;
    }
    return 2;
  }
  lineCrossLine(a, b, p, q, ans);
  if (pointOnSeg(ans, a, b) && pointOnSeg(ans, p, q)) return 1;
  return 0;
}
const int SIZE = 700;
const int MM = 1000000000;
struct BigNum {
  long long a[SIZE];
  int len;
  BigNum() { memset(a, 0, sizeof(a)); }
  BigNum(char *s, int n) {
    memset(a, 0, sizeof(a));
    int p = 0;
    int i;
    for (i = n - 1; i >= 0; i -= 9) {
      int j = max(0, i - 8);
      a[p] = 0;
      int k;
      for (k = j; k <= i; k++) a[p] = a[p] * 10 + s[k] - '0';
      p++;
    }
    adjust();
  }
  BigNum(long long n) {
    memset(a, 0, sizeof(a));
    a[0] = n;
    adjust();
  }
  BigNum adjust() {
    int i;
    for (i = 0; i < SIZE; i++) {
      if (a[i] >= MM) {
        a[i + 1] += a[i] / MM;
        a[i] %= MM;
      } else if (a[i] < 0) {
        a[i + 1]--;
        a[i] += MM;
      }
    }
    for (i = SIZE - 1; i >= 0; i--)
      if (a[i]) break;
    len = i + 1;
    if (len == 0) len = 1;
  }
  BigNum operator*(const BigNum &p) {
    BigNum c;
    int i, j;
    for (i = 0; i < len; i++)
      for (j = 0; j < p.len; j++) {
        c.a[i + j] += a[i] * p.a[j];
      }
    c.adjust();
    return c;
  }
  BigNum operator/(const int x) {
    long long tmp = 0;
    BigNum c;
    memcpy(c.a, a, sizeof(a));
    int i;
    for (i = len - 1; i >= 0; i--) {
      long long p = (tmp * MM + c.a[i]) % x;
      c.a[i] = (tmp * MM + c.a[i]) / x;
      tmp = p;
    }
    c.adjust();
    return c;
  }
  BigNum operator+(BigNum &p) {
    BigNum c;
    int i;
    int t = max(len, p.len);
    for (i = 0; i < t; i++) c.a[i] = a[i] + p.a[i];
    c.adjust();
    return c;
  }
  BigNum operator-(const BigNum &p) const {
    BigNum c;
    int i;
    for (i = 0; i < len; i++) c.a[i] = a[i] - p.a[i];
    c.adjust();
    return c;
  }
  int operator==(const BigNum &p) const {
    if (len != p.len) return 0;
    int i;
    for (i = 0; i < SIZE; i++)
      if (a[i] != p.a[i]) return 0;
    return 1;
  }
  int operator<(const BigNum &p) const {
    if (len < p.len) return 1;
    if (len > p.len) return 0;
    int i;
    for (i = len - 1; i >= 0; i--) {
      if (a[i] < p.a[i]) return 1;
      if (a[i] > p.a[i]) return 0;
    }
    return 0;
  }
  int operator>(const BigNum &p) const {
    if (len > p.len) return 1;
    if (len < p.len) return 0;
    int i;
    for (i = len - 1; i >= 0; i--) {
      if (a[i] > p.a[i]) return 1;
      if (a[i] < p.a[i]) return 0;
    }
    return 0;
  }
  void output() {
    int i;
    printf("%d", (int)a[len - 1]);
    for (i = len - 2; i >= 0; i--) printf("%09d", (int)a[i]);
    puts("");
  }
};
const long long inf = (((long long)1) << 61) + 5;
const double dinf = 1e20;
const int INF = 1000000005;
const int N = 100005;
int d[N], a[N], n;
void deal(int L, int R) {
  if (L == R) return;
  int x = d[R];
  memmove(d + L + 1, d + L, (R - L) * sizeof(int));
  d[L] = x;
}
int query(int L, int R, int k) {
  if (R - L < n / 2) {
    int ans = 0;
    int i;
    for (i = L; i <= R; i++) ans += d[i] == k;
    return ans;
  }
  int ans = a[k];
  int i;
  for (i = 1; i < L; i++) ans -= d[i] == k;
  for (i = R + 1; i <= n; i++) ans -= d[i] == k;
  return ans;
}
int main() {
  RD(n);
  int i;
  for (i = 1; i <= n; i++) RD(d[i]), a[d[i]]++;
  int ans = 0;
  int Q;
  RD(Q);
  while (Q--) {
    int op;
    RD(op);
    if (op == 1) {
      int L;
      int R;
      RD(L, R);
      L = (L + ans - 1) % n + 1;
      R = (R + ans - 1) % n + 1;
      if (L > R) swap(L, R);
      deal(L, R);
    } else {
      int L, R, k;
      RD(L, R);
      RD(k);
      L = (L + ans - 1) % n + 1;
      R = (R + ans - 1) % n + 1;
      k = (k + ans - 1) % n + 1;
      if (L > R) swap(L, R);
      ans = query(L, R, k);
      PR(ans);
    }
  }
}
