#include <bits/stdc++.h>
using namespace std;
const int iINF = 0x3f3f3f3f;
const long long lINF = 0x3f3f3f3f3f3f3f3f;
inline void read(long long& x) {
  int f = 1;
  char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-')
    ;
  c == '-' ? (f = -1, x = 0) : (x = c - '0');
  while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= f;
}
inline void read(int& x) {
  long long t;
  read(t);
  x = t;
}
const int MAXN = 1e5 + 10;
int n, k, m, t;
int main() {
  cin >> n >> k >> m >> t;
  while (t--) {
    int opt, pos;
    cin >> opt >> pos;
    if (opt) {
      if (pos <= k) k++;
      n++;
    } else {
      if (pos <= k) {
        k -= pos;
        n -= pos;
      } else {
        n -= n - pos;
      }
    }
    cout << n << ' ' << k << endl;
  }
  return 0;
}
