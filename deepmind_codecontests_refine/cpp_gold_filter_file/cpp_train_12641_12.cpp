#include <bits/stdc++.h>
using namespace std;
void readi(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void readll(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void readc(char &x) {
  char c;
  while ((c = getchar()) == ' ')
    ;
  x = c;
}
void writes(string s) { puts(s.c_str()); }
void writeln() { writes(""); }
void writei(int x) {
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
void writell(long long x) {
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
inline long long inc(int &x) { return ++x; }
inline long long inc(long long &x) { return ++x; }
inline long long inc(int &x, long long y) { return x += y; }
inline long long inc(long long &x, long long y) { return x += y; }
inline double inc(double &x, double y) { return x += y; }
inline long long dec(int &x) { return --x; }
inline long long dec(long long &x) { return --x; }
inline long long dec(int &x, long long y) { return x -= y; }
inline long long dec(long long &x, long long y) { return x -= y; }
inline double dec(double &x, double y) { return x -= y; }
inline long long mul(int &x) { return x = ((long long)x) * x; }
inline long long mul(long long &x) { return x = x * x; }
inline long long mul(int &x, long long y) { return x *= y; }
inline long long mul(long long &x, long long y) { return x *= y; }
inline double mul(double &x, double y) { return x *= y; }
inline long long divi(int &x) { return x = sqrt(x); }
inline long long divi(long long &x) { return x = sqrt(x); }
inline long long divi(int &x, long long y) { return x /= y; }
inline long long divi(long long &x, long long y) { return x /= y; }
inline double divi(double &x, double y) { return x /= y; }
inline long long mod(int &x, long long y) { return x %= y; }
inline long long mod(long long &x, long long y) { return x %= y; }
int n, m, i, j, p, x, y, z, px[171121], py[171121];
int main() {
  ios_base::sync_with_stdio(false);
  ;
  cin >> n >> m >> x >> y >> z >> p;
  for (i = 1; i <= p; i++) cin >> px[i] >> py[i];
  x %= 4;
  y %= 2;
  z %= 4;
  while (x--) {
    swap(n, m);
    for (i = 1; i <= p; i++) {
      swap(px[i], py[i]);
      py[i] = m - py[i] + 1;
    }
  }
  while (y--) {
    for (i = 1; i <= p; i++) {
      py[i] = m - py[i] + 1;
    }
  }
  while (z--) {
    swap(n, m);
    for (i = 1; i <= p; i++) {
      swap(px[i], py[i]);
      px[i] = n - px[i] + 1;
    }
  }
  for (i = 1; i <= p; i++) cout << px[i] << ' ' << py[i] << endl;
  return 0;
}
