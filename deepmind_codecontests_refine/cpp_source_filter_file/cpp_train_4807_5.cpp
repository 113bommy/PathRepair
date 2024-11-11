#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, d[N];
inline int read() {
  int x = 0, p = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') p = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * p;
}
void init() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    d[i] = read();
  }
}
void solve() {
  sort(d + 1, d + n + 1);
  if (d[n] < d[1] + d[n + 1]) return;
  if (n != 3 && d[n] < d[n - 1] + d[n - 2]) {
    for (int i = n - 2; i > 1; --i) {
      swap(d[i], d[i - 1]);
    }
    return;
  }
  puts("NO");
  exit(0);
}
void putout() {
  puts("YES");
  for (int i = 1; i <= n; ++i) {
    cout << d[i] << ' ';
  }
  puts("");
}
int main() {
  init();
  solve();
  putout();
  return 0;
}
