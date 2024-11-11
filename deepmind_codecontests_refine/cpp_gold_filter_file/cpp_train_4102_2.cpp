#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
int f[1000005];
int main() {
  int n = read(), cnt1 = 0;
  for (int i = 1; i <= n; i++) {
    cnt1 += !(read() - 1);
  }
  f[0] = f[1] = 1;
  f[2] = 2;
  for (int i = 3; i <= cnt1; i++) {
    f[i] = (f[i - 1] + f[i - 2] * 1ll * (i - 1) % 1000000007) % 1000000007;
  }
  int s = f[cnt1];
  for (int i = cnt1 + 1; i <= n; i++) {
    s = s * 1ll * i % 1000000007;
  }
  cout << s << endl;
  return 0;
}
