#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n, m, q;
int da[maxn], db[maxn];
inline int read() {
  int X = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) w |= ch == '-', ch = getchar();
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return w ? -X : X;
}
int main() {
  int t = read();
  while (t--) {
    int n = read();
    for (int i = 0; i < n; i++) da[i] = read();
    for (int i = 0; i < n; i++) db[i] = read();
    int now = 0;
    int ms = 0;
    int mr = 1e9 + 10;
    for (int i = 0; i < n; i++) {
      if (now > da[i]) now = da[i];
      mr = min(mr, da[i] - now);
      now = now + db[i] - da[i];
      if (now < 0) {
        if (i) ms = max(ms, -now);
        now = 0;
      }
    }
    mr = ms = 0;
    for (int i = 0; i < n; i++) {
      if (now > da[i]) now = da[i];
      mr = min(mr, da[i] - now);
      now = now + db[i] - da[i];
      if (now < 0) {
        ms = max(ms, -now);
        now = 0;
      }
    }
    if (ms == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
