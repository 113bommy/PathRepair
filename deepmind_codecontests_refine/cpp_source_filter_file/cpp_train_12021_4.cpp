#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9;
const int maxc = 77;
struct thang {
  int X, B;
};
thang A[1010];
double f[1010];
int trace[1010], st[1010];
int N, L;
void nhap() {
  scanf("%d%d", &N, &L);
  for (int i = 1; i <= N; i++) scanf("%d%d", &A[i].X, &A[i].B);
  A[0].X = 0;
}
void solve(double mid) {
  for (int i = 1; i <= N; i++) f[i] = oo;
  f[0] = 0;
  for (int i = 1; i <= N; i++) {
    int vt = 0;
    double t = oo;
    for (int j = i - 1; j >= 0; j--)
      if (f[j] + sqrt(abs((A[i].X - A[j].X) - L * 1.0)) - mid * 1.0 * A[i].B <
          t) {
        vt = j;
        t = f[j] + sqrt(abs(A[i].X - A[j].X) - L * 1.0) - mid * A[i].B;
      }
    f[i] = t;
    trace[i] = vt;
  }
}
void chat() {
  double l = 0, r = oo;
  for (int i = 1; i <= maxc; i++) {
    double mid = (l + r) / 2;
    solve(mid);
    if (f[N] <= 0)
      r = mid;
    else
      l = mid;
  }
  int top = 0, i = N;
  while (i != 0) {
    st[++top] = i;
    i = trace[i];
  }
  while (top > 0) printf("%d ", st[top--]);
}
int main() {
  nhap();
  chat();
  return 0;
}
