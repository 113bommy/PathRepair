#include <bits/stdc++.h>
using namespace std;
struct point {
  long long x, y;
};
int N;
point P[100010];
long long area(point &P, point &Q) { return P.x * Q.y - P.y * Q.x; }
bool smaller(point &P, point &Q) {
  if (P.x < Q.x) return true;
  if (P.x == Q.x && P.y < Q.y) return true;
  return false;
}
long long low[2000010], high[2000010];
void lower(point P, point Q) {
  if (P.x == Q.x) return;
  for (int i = P.x; i <= Q.x; i++) {
    double y = P.y + (double)(Q.y - P.y) / (Q.x - P.x) * (i - P.x);
    low[i] = max(low[i], (long long)(y - 1.0E-7) + 1);
  }
}
void upper(point P, point Q) {
  if (P.x == Q.x) return;
  for (int i = P.x; i <= Q.x; i++) {
    double y = P.y + (double)(Q.y - P.y) / (Q.x - P.x) * (i - P.x);
    high[i] = min(high[i], (long long)(y + 1.0E-7));
  }
}
double func(void) {
  int i;
  long long s = 0;
  for ((i) = 0; (i) < (int)(N); (i)++) s += area(P[i], P[(i + 1) % N]);
  if (s < 0) reverse(P, P + N);
  int L = 0, R = 0;
  for ((i) = 0; (i) < (int)(N); (i)++) {
    if (smaller(P[i], P[L])) L = i;
    if (smaller(P[R], P[i])) R = i;
  }
  int X1 = P[L].x;
  int X2 = P[R].x;
  for (i = X1; i <= X2; i++) low[i] = -(1 << 29);
  for (i = X1; i <= X2; i++) high[i] = (1 << 29);
  for (i = 0;; i++) {
    int a = (L + i) % N, b = (L + i + 1) % N;
    lower(P[a], P[b]);
    if (b == R) break;
  }
  for (i = 0;; i++) {
    int a = (R + i + 1) % N, b = (R + i) % N;
    upper(P[a], P[b]);
    if (a == L) break;
  }
  double cnt = 0.0;
  double xsum = 0.0;
  double x2sum = 0.0;
  int sy = X2 - X1;
  for (i = 0; i <= sy; i++) {
    double tmp = high[i + X1] - low[i + X1] + 1;
    cnt += tmp;
    xsum += tmp * (double)i;
    x2sum += tmp * (double)i * (double)i;
  }
  double ans = 2.0 * cnt * x2sum - 2.0 * xsum * xsum;
  return ans / cnt / (cnt - 1.0);
}
int main(void) {
  int i;
  cin >> N;
  for ((i) = 0; (i) < (int)(N); (i)++) {
    int x, y;
    scanf("%d%d", &x, &y);
    P[i].x = x + 1000000;
    P[i].y = y + 1000000;
  }
  double ans1 = func();
  for ((i) = 0; (i) < (int)(N); (i)++) swap(P[i].x, P[i].y);
  double ans2 = func();
  printf("%.9f\n", (ans1 + ans2) / 2.0);
  return 0;
}
