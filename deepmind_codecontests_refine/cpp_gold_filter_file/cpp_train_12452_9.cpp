#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 0;
  char ch = 0;
  while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
  while (isdigit(ch)) (x *= 10) += (ch ^ 48), ch = getchar();
  return f ? -x : x;
}
void Ot(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) Ot(x / 10);
  putchar(x % 10 + 48);
}
void Print(int x, char til = '\n') {
  Ot(x);
  putchar(til);
}
int Max(int x, int y) { return x > y ? x : y; }
int Min(int x, int y) { return x < y ? x : y; }
int Abs(int x) { return x < 0 ? -x : x; }
vector<int> G, P;
int n, ans;
char Getch() {
  char c = getchar();
  while (c != '.' && c != '*' && c != 'P') c = getchar();
  return c;
}
bool check(int x) {
  int t = 1, pos = G[t - 1];
  for (register int i = 0; i < P.size(); i++) {
    int way = P[i] - pos;
    if (way > 0 && way > x) return 0;
    while (1) {
      int len = P[i] - pos;
      if (1ll * way * len < 0) {
        if (Abs(len) < Abs(way))
          len = Abs(len) * 2 + Abs(way);
        else
          len = Abs(len) + Abs(way) * 2;
      } else
        len = Abs(len);
      if (len <= x)
        t++, pos = G[t - 1];
      else
        break;
      if (t > G.size()) return 1;
    }
  }
  return 0;
}
signed main() {
  n = read();
  for (register int i = 1; i <= n; i++) {
    char ch = Getch();
    if (ch == 'P')
      P.push_back(i);
    else if (ch == '*')
      G.push_back(i);
  }
  if (!G.size()) return Print(0), 0;
  int L = 0, R = 2 * n;
  while (L <= R) {
    register int mid = (L + R) >> 1;
    if (check(mid))
      ans = mid, R = mid - 1;
    else
      L = mid + 1;
  }
  Print(ans);
  return 0;
}
