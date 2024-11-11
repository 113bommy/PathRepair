#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int f = 1, ans = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return f * ans;
}
int Minn;
int main() {
  int N = read(), d = read(), e = read();
  Minn = N;
  for (int i = 0; i * d <= N; i++) {
    int res = (N - i * d) % (5 * e);
    Minn = min(Minn, res);
  }
  printf("%d\n", Minn);
}
