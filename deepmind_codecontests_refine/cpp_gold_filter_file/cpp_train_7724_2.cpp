#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
pair<int, int> a[N];
int b[N][N];
bool cmp(const pair<int, int> &A, const pair<int, int> &B) { return A > B; }
int main() {
  int n = read();
  for (int i = 1; i <= n; ++i) {
    a[i].first = read();
    a[i].second = i;
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; ++i) {
    int now = n + 2 - i;
    for (int j = 1; j <= a[i].first; ++j) {
      b[now--][a[i].second] = 1;
      if (!now) now = n + 1;
    }
  }
  printf("%d\n", n + 1);
  for (int i = 1; i <= n + 1; ++i) {
    for (int j = 1; j <= n; ++j) printf("%d", b[i][j]);
    puts("");
  }
  return 0;
}
