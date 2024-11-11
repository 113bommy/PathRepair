#include <bits/stdc++.h>
using namespace std;
const int inf = ~0U >> 1;
int n;
void setIO(string name) {}
int gI() {
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  int p = 0, flag = 1;
  if (c == '-') flag = -1, c = getchar();
  while (c >= '0' && c <= '9') p = p * 10 + c - '0', c = getchar();
  return p * flag;
}
int main() {
  setIO("test");
  scanf("%d", &n);
  long long X1 = inf, Y1 = inf, X2 = -inf, Y2 = -inf;
  long long cnt;
  for (int i = 0; i < n; ++i) {
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cnt += (x2 - x1) * (y2 - y1);
    X1 = min(X1, x1);
    X2 = max(X2, x2);
    Y1 = min(Y1, y1);
    Y2 = max(Y2, y2);
  }
  if ((Y2 - Y1) * (X2 - X1) == cnt && Y2 - Y1 == X2 - X2)
    puts("YES");
  else
    puts("NO");
  return 0;
}
