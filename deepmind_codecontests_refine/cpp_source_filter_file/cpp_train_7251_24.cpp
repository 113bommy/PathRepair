#include <bits/stdc++.h>
using namespace std;
int read() {
  char c;
  while (c = getchar(), c < '0' || c > '9')
    ;
  int x = c - '0';
  while (c = getchar(), c >= '0' && c <= '9') x = x * 10 + c - '0';
  return x;
}
const int Maxn = 105;
int N, S, t[Maxn], Ans;
int main() {
  N = read(), S = read();
  for (int i = 1; i <= N; i++) {
    int x = read(), y = read();
    t[i] = x * 60 + y;
  }
  t[0] = -S - 1, t[N + 1] = 2e9;
  for (int i = 1; i <= N + 1; i++) {
    if (t[i] > t[i - 1] + S * 2 + 1) {
      Ans = t[i - 1] + S + i;
      break;
    }
  }
  printf("%d %d", Ans / 60, Ans - (Ans / 60 * 60));
  return 0;
}
