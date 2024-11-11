#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
inline int getint() {
  int w = 0, q = 0;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') q = 1, c = getchar();
  while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
  return q ? -w : w;
}
long long h, w;
int main() {
  cin >> h >> w;
  long long t = 1;
  long long a = 0, b = 0, p;
  for (int i = 0; i < 31; i++) {
    if (t <= h && 4 * t < 5 * w) {
      if (t <= h && 4 * t <= 5 * w) {
        p = min(w, 5 * t / 4);
        if ((a < t && p * t == a * b) || a * b < p * t) {
          a = t, b = p;
        }
      }
      if (t <= w && 4 * t <= 5 * h) {
        p = min(h, 5 * t / 4);
        if ((a < p && p * t == a * b) || a * b < p * t) {
          a = p, b = t;
        }
      }
    }
    t *= 2;
  }
  cout << a << " " << b << endl;
  return 0;
}
