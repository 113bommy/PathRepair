#include <bits/stdc++.h>
using namespace std;
const int N = 501;
const int M = 1e6 + 10;
const long long mod = 1e9 + 7;
const int INF = 2e9 + 1;
inline void rd(long long &x) {
  x = 0;
  char ch = getchar();
  bool flag = 0;
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') flag = 1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10ll + ch - '0', ch = getchar();
  if (flag) x = -x;
  return;
}
inline void rd(int &x) {
  x = 0;
  char ch = getchar();
  bool flag = 0;
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') flag = 1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  if (flag) x = -x;
  return;
}
inline char rch() {
  char c;
  while ((c = getchar()) != '<' && c != '=')
    ;
  return c;
}
int n, a[N], ans;
inline int work(int now) {
  int num = 0;
  for (int j = 1; j <= n; ++j) {
    int x = now / a[j];
    num += x;
    now -= a[j] * x;
  }
  return num;
}
int main() {
  ans = 2e9;
  rd(n);
  for (int i = 1; i <= n; ++i) rd(a[i]);
  for (int i = 2; i <= n; ++i) {
    int top = a[i - 1] - 1;
    int now = top;
    int num = 0;
    for (int j = i; j <= n; ++j) {
      int x = now / a[j];
      num += x;
      now -= a[j] * x;
      if (num + 1 < work(top - now + a[j])) {
        ans = min(ans, top - now + a[j]);
      }
    }
  }
  if (ans >= 2e9) {
    puts("-1");
  } else {
    cout << ans << endl;
  }
  return 0;
}
