#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int res = 0;
  char c;
  int f = 1;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  while (c >= '0' && c <= '9') res = res * 10 + c - '0', c = getchar();
  return res * f;
}
const int N = 100010;
int a[N], b[N];
int main() {
  int n = in();
  for (int i = 1; i <= n; i++) {
    a[i] = in();
  }
  for (int i = 1; i <= n; i++) {
    b[i] = in();
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int t1 = a[i], t2 = b[i];
    ans = max(ans, t1 + t2);
    for (int j = i + 1; j <= n; j++) {
      t1 ^= a[j], t2 ^= b[j];
      ans = max(ans, t1 + t2);
    }
  }
  cout << ans << endl;
  return 0;
}
