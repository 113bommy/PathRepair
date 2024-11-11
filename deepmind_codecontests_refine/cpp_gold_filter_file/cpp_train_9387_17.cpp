#include <bits/stdc++.h>
using namespace std;
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
T ModInv(T b, T m) {
  return BigMod(b, m - 2, m);
}
template <typename T>
T in() {
  char ch;
  T n = 0;
  bool ng = false;
  while (1) {
    ch = getchar();
    if (ch == '-') {
      ng = true;
      ch = getchar();
      break;
    }
    if (ch >= '0' && ch <= '9') break;
  }
  while (1) {
    n = n * 10 + (ch - '0');
    ch = getchar();
    if (ch < '0' || ch > '9') break;
  }
  return (ng ? -n : n);
}
template <typename T>
T POW(T B, T printf) {
  if (printf == 0) return 1;
  if (printf & 1)
    return B * POW(B, printf - 1);
  else
    return (POW(B, printf / 2) * POW(B, printf / 2));
}
template <typename T>
T Bigmod(T b, T p, T m) {
  if (p == 0)
    return 1;
  else if (!(p & 1))
    return (Bigmod(b, p / 2, m) * Bigmod(b, p / 2, m)) % m;
  else
    return ((b % m) * Bigmod(b, p - 1, m)) % m;
}
template <typename T>
T Dis(T x1, T y1, T x2, T y2) {
  return sqrt((x1 - x2 * x1 - x2) + (y1 - y2 * y1 - y2));
}
template <typename T>
T Angle(T x1, T y1, T x2, T y2) {
  return atan(double(y1 - y2) / double(x1 - x2));
}
template <typename T>
T DIFF(T a, T b) {
  T d = a - b;
  if (d < 0)
    return -d;
  else
    return d;
}
template <typename T>
T ABS(T a) {
  if (a < 0)
    return -a;
  else
    return a;
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
T euclide(T a, T b, T &x, T &y) {
  if (a < 0) {
    T d = euclide(-a, b, x, y);
    x = -x;
    return d;
  }
  if (b < 0) {
    T d = euclide(a, -b, x, y);
    y = -y;
    return d;
  }
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    T d = euclide(b, a % b, x, y);
    T t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
  }
}
template <typename T>
void ia(T a[], int n) {
  for (int i = 0; i < n; i++) cin >> a[i];
}
template <typename T>
void pa(T a[], int n) {
  for (int i = 0; i < n - 1; i++) cout << a[i] << " ";
  cout << a[n - 1] << endl;
}
template <typename T>
long long int isLeft(T a, T b, T c) {
  return (a.x - b.x) * (b.y - c.y) - (b.x - c.x) * (a.y - b.y);
}
int Set(int N, int pos) { return N = N | (1 << pos); }
int Reset(int N, int pos) { return N = N & ~(1 << pos); }
bool Check(int N, int pos) { return (bool)(N & (1 << pos)); }
template <class T, class first>
inline T togglebit(T a, first i) {
  T t = 1;
  return (a ^ (t << i));
}
double DEG(double x) { return (180.0 * x) / (2.0 * acos(0.0)); }
double RAD(double x) { return (x * (double)2.0 * acos(0.0)) / (180.0); }
char a[2000007], b[2000007];
int shft[2000007];
string p;
pair<long long int, long long int> h1[2000007 >> 1], h2[2000007 >> 1];
long long int b1[2000007 >> 1], b2[2000007 >> 1];
void Init() {
  b1[0] = b2[0] = 1;
  for (int i = 1; i < 2000007 / 2; i++) {
    b1[i] = (b1[i - 1] * 10000019LL) % 1000000007LL;
    b2[i] = (b2[i - 1] * 10000079LL) % 1000000009LL;
  }
}
void Failure() {
  int j = 0, i = 1;
  shft[0] = 0;
  while (i < p.length()) {
    if (p[i] == p[j]) {
      j++;
      shft[i] = j;
      i++;
    } else if (j)
      j = shft[j - 1];
    else
      shft[i] = 0, i++;
  }
}
pair<long long int, long long int> SubStr(pair<long long int, long long int> *h,
                                          int x, int y) {
  pair<long long int, long long int> ans(0, 0);
  if (x <= y) {
    int len = y - x + 1;
    ans.first =
        (h[y].first - (h[x - 1].first * b1[len]) % 1000000007LL) % 1000000007LL;
    ans.second = (h[y].second - (h[x - 1].second * b2[len]) % 1000000009LL) %
                 1000000009LL;
    ans.first += 1000000007LL;
    ans.first %= 1000000007LL;
    ans.second += 1000000009LL;
    ans.second %= 1000000009LL;
  }
  return ans;
}
int main() {
  Init();
  gets(a);
  gets(b);
  int l1 = strlen(a);
  int l2 = strlen(b);
  if (l1 != l2) {
    cout << -1 << " " << -1 << endl;
    return 0;
  }
  p = a;
  reverse(p.begin(), p.end());
  p += (char)2;
  p += b;
  Failure();
  h1[0] = make_pair(0, 0);
  for (int i = 0; i < l1; i++) {
    int x = a[i] - 'a' + 1;
    h1[i + 1].first = (h1[i].first * 10000019LL + x) % 1000000007LL;
    h1[i + 1].second = (h1[i].second * 10000079LL + x) % 1000000009LL;
  }
  h2[0] = make_pair(0, 0);
  for (int i = 0; i < l2; i++) {
    int x = b[i] - 'a' + 1;
    h2[i + 1].first = (h2[i].first * 10000019LL + x) % 1000000007LL;
    h2[i + 1].second = (h2[i].second * 10000079LL + x) % 1000000009LL;
  }
  int x = -1, y = -1;
  for (int i = 0, j = l1 - 1; i < l1 - 1; i++, j--) {
    if (a[i] != b[j]) break;
    int id = l1 + 1 + j - 1;
    int len = shft[id];
    int stb = 0, edb = j - len - 1;
    int sta = i + 1, eda = i + edb + 1;
    if (SubStr(h1, sta + 1, eda + 1) == SubStr(h2, stb + 1, edb + 1)) {
      x = sta - 1;
      y = eda + 1;
    }
  }
  cout << x << " " << y << endl;
  return 0;
}
