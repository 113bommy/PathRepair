#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = 2 * acos(0.0);
const string alphabetU = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string alphabetL = "abcdefghijklmnopqrstuvwxyz";
const long long infinite = 1000000000;
const long long maxn = 100010;
static const int m37pos[] = {32, 0, 1,  26, 2,  23, 27, 0,  3,  16, 24, 30, 28,
                             11, 0, 13, 4,  7,  17, 0,  25, 22, 31, 15, 29, 10,
                             12, 6, 0,  21, 14, 9,  5,  20, 8,  19, 18};
inline int nextInt() {
  int x = 0;
  register int c = getc(stdin);
  int sign = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getc(stdin))
    ;
  if (c == '-') {
    sign = 1;
    c = getc(stdin);
  }
  for (; c > 47 && c < 58; c = getc(stdin)) x = (x << 1) + (x << 3) + c - 48;
  if (sign) x = -x;
  return x;
}
inline long long nextLong() {
  long long x = 0;
  register int c = getc(stdin);
  int sign = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getc(stdin))
    ;
  if (c == '-') {
    sign = 1;
    c = getc(stdin);
  }
  for (; c > 47 && c < 58; c = getc(stdin)) x = (x << 1) + (x << 3) + c - 48;
  if (sign) x = -x;
  return x;
}
inline string nextLine() {
  string s;
  while (!feof(stdin)) {
    char c = fgetc(stdin);
    if (c == 13) continue;
    if (c == 10) return s;
    s += c;
  }
  return s;
}
void scan(int &x) { x = nextInt(); }
void scanl(long long &x) { x = nextLong(); }
void scans(string &s) { s = nextLine(); }
int k, flag[10000001], prime[10000001], primeOrder[10000001], t, d[1000000];
long long pp[1000000];
long long a[60], b[60];
void input() {
  scan(k);
  for (int i = 0, _b = k; i < _b; i++) scan(d[i]);
}
void seive() {
  memset(flag, 0, sizeof(flag));
  flag[1] = 1;
  for (int i = 2, _b = 3200; i < _b; i++)
    if (!flag[i]) {
      int j = i * i;
      while (j <= d[k - 1]) {
        flag[j] = i;
        j += i;
      }
    }
  t = 0;
  for (int i = 2, _b = d[k - 1]; i <= _b; i++)
    if (!flag[i]) {
      flag[i] = i;
      primeOrder[i] = t;
      prime[t] = i;
      t++;
    }
}
void process() {
  sort(&d[0], &d[k]);
  seive();
  memset(pp, 0, sizeof(pp));
  int tt = 0, y = k;
  for (int i = 2, _b = d[k - 1]; i <= _b; i++) {
    while (i > d[tt]) {
      tt++;
      y--;
    }
    long long x = (long long)i;
    while (x != 1) {
      pp[primeOrder[flag[x]]] += (long long)y;
      x /= (long long)flag[x];
    }
  }
  long long ans = 1, mx = 0x7fffffffffffffffLL;
  for (int i = 0, _b = t; i < _b; i++) {
    a[0] = prime[i];
    b[0] = 1;
    for (int j = 1, _b = 60; j < _b; j++) {
      tt = j;
      if (mx / (long long)prime[i] < a[j]) break;
      a[j] = a[j - 1] * (long long)prime[i];
      b[j] = b[j - 1] + a[j - 1];
    }
    long long xx = 0, yy = pp[i];
    while (yy) {
      k = lower_bound(&b[0], &b[tt], yy) - &b[0];
      if (yy < b[k]) k--;
      if (!k) {
        xx += a[k] * (yy - 1);
        yy = 0;
      } else {
        yy -= b[k];
        xx += a[k];
      }
    }
    ans = max(ans, xx);
  }
  cout << ans << endl;
}
void build_test() {
  freopen("test.in", "w", stdout);
  int n = 100000;
  cout << n << endl;
  for (int i = 1, _b = n; i <= _b; i++) printf("1000000 ");
}
int main() {
  int test = 1;
  for (int i = 1, _b = test; i <= _b; i++) {
    input();
    process();
  }
  return 0;
}
