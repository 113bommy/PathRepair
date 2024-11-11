#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
struct Point {
  int x, y;
} p[2010];
double tmp[2010];
int n;
int Calc(int x) { return x * (x - 1) / 2; }
int main(void) {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &p[i].x, &p[i].y);
  }
  long long Ans = 0;
  for (int i = 1; i <= n; i++) {
    swap(p[i], p[1]);
    for (int j = 2; j <= n; j++)
      tmp[j - 1] = atan2(p[j].y - p[1].y, p[j].x - p[1].x);
    sort(tmp + 1, tmp + n, [](double a, double b) { return a < b; });
    for (int j = n; j <= n + n - 2; j++) tmp[j] = tmp[j - n + 1] + 2 * pi;
    int now = 2;
    for (int j = 1; j < n; j++) {
      while (tmp[now] - tmp[j] < pi) now++;
      Ans += 2LL * Calc(now - j - 1) * Calc(n - now + j - 1);
    }
    swap(p[i], p[1]);
  }
  cout << (Ans >> 2) << endl;
  return 0;
}
