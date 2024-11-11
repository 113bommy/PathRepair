#include <bits/stdc++.h>
using namespace std;
template <typename Tp>
void read(Tp &x) {
  x = 0;
  char ch = 1;
  int fh = 1;
  while (ch != '-' && (ch > '9' || ch < '0')) ch = getchar();
  if (ch == '-') fh = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= fh;
}
const int maxa = 1000007;
const int maxn = 1000007;
int n;
int opt[maxa], pos[maxa];
bool exist[maxa];
int a[maxn], b[maxn];
int mx;
void Init(void) {
  read(n);
  for (int i = 1; i <= n; i++) {
    read(a[i]);
    read(b[a[i]]);
  }
}
void Work(void) {
  if (b[0] > 0) opt[0] = 1;
  for (int i = 1; i < maxn; i++) {
    if (b[i] == 0)
      opt[i] = opt[i - 1];
    else if (b[i] >= i)
      opt[i] = 1;
    else
      opt[i] = opt[i - b[i] - 1] + 1;
    mx = max(mx, opt[i]);
  }
  printf("%d\n", n - mx);
}
int main() {
  Init();
  Work();
  return 0;
}
