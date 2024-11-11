#include <bits/stdc++.h>
using namespace std;
inline void ri(int &num) {
  num = 0;
  int f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') num = num * 10 + ch - '0', ch = getchar();
  num *= f;
}
const int N = 1e5 + 5;
int l[N], r[N], a[N];
int main() {
  int n;
  ri(n);
  for (int i = 1; i <= n; i++) ri(a[i]);
  for (int i = 1; i <= n; i++) l[i] = min(l[i - 1] + 1, a[i]);
  for (int i = n; i >= 1; i--) r[i] = min(r[i + 1] + 1, a[i]);
  int mx = -1;
  for (int i = 1; i <= n; i++) mx = max(mx, min(l[i], r[i]));
  printf("%d\n", mx);
  return 0;
}
