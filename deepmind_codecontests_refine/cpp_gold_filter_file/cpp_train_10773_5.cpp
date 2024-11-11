#include <bits/stdc++.h>
using namespace std;
char IO;
int rd() {
  int s = 0, f = 0;
  while (!isdigit(IO = getchar()))
    if (IO == '-') f = 1;
  do s = (s << 1) + (s << 3) + (IO ^ '0');
  while (isdigit(IO = getchar()));
  return f ? -s : s;
}
const int N = 5011, INF = 1e9 + 10;
int n;
char s[N];
struct Node {
  int opt;
  long long x;
} a[N], b[N];
long long Solve(Node *s, int l, int r) {
  long long t = s[l].x, res = 0;
  for (int i = l + 1, iend = r; i <= iend; ++i) {
    if (s[i].opt == 1)
      t *= s[i].x;
    else
      res += t, t = s[i].x;
  }
  return res + t;
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i += 2)
    a[i / 2 + 1].opt = (s[i - 1] != '+'), a[i / 2 + 1].x = s[i] - '0';
  n = n / 2 + 1;
  long long ans = Solve(a, 1, n);
  for (int i = 1, iend = n; i <= iend; ++i)
    if (a[i].opt)
      for (int j = i + 1, jend = n + 1; j <= jend; ++j)
        if (a[j].opt || j == n + 1) {
          long long t = Solve(a, i, j - 1);
          int c = 0;
          for (int k = 1, kend = i - 1; k <= kend; ++k) b[++c] = a[k];
          b[++c] = (Node){1, t};
          for (int k = j, kend = n; k <= kend; ++k) b[++c] = a[k];
          ans = max(ans, Solve(b, 1, c));
        }
  printf("%lld\n", ans);
}
