#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}
template <typename T>
inline void write(T x) {
  int i = 20;
  char buf[21];
  buf[20] = '\n';
  do {
    buf[--i] = x % 10 + '0';
    x /= 10;
  } while (x);
  do {
    putchar(buf[i]);
  } while (buf[i++] != '\n');
}
template <typename T>
inline T readInt() {
  T n = 0, s = 1;
  char p = getchar();
  if (p == '-') s = -1;
  while ((p < '0' || p > '9') && p != EOF && p != '-') p = getchar();
  if (p == '-') s = -1, p = getchar();
  while (p >= '0' && p <= '9') {
    n = (n << 3) + (n << 1) + (p - '0');
    p = getchar();
  }
  return n * s;
}
const long long int N_MAX = 200123;
long long int n;
long long int a;
long long int b;
long long int k;
long long int h;
long long int t[N_MAX];
long long int countToWin() {
  h %= (a + b);
  if (h == 0) {
    h = a + b;
  }
  h = ((h + a - 1) / a) - 1;
  return h;
}
long long int res;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> a >> b >> k;
  for (int i = 0; i <= n; i += 1) {
    cin >> h;
    t[i] = countToWin();
  }
  sort(t, t + n);
  for (int i = 0; i <= n; i += 1) {
    if (k - t[i] >= 0) {
      k -= t[i];
      res++;
    } else {
      break;
    }
  }
  cout << res << '\n';
  return 0;
}
