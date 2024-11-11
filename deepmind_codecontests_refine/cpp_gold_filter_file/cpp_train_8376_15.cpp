#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000000,102400000000")
const long long MOD = 1000000007;
const int N = 10000 + 5;
const int maxn = 1e5 + 15;
const int letter = 130;
const int INF = 1e8;
const double pi = acos(-1.0);
const double eps = 1e-10;
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int b[N], n, a[N], len;
void add(int sum) {
  for (int i = 1; sum; i++) {
    while (a[i] < 9 && sum) a[i]++, sum--;
    len = max(i, len);
  }
}
void output() {
  for (int i = len; i > 0; i--) printf("%d", a[i]);
  puts("");
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", b + i);
  add(b[1]), output();
  for (int i = 2; i <= n; i++) {
    int vs = b[i] - b[i - 1];
    if (vs > 0)
      add(vs), output();
    else {
      int k = 1;
      while (1) {
        if (k > len) len = k;
        if (a[k] < 9 && vs > 0) {
          a[k]++;
          vs--;
          add(vs);
          output();
          break;
        }
        vs += a[k];
        a[k++] = 0;
      }
    }
  }
  return 0;
}
