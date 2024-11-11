#include <bits/stdc++.h>
using namespace std;
int n, A[300010], L[300010], R[300010];
double sum;
int q[300010];
int cmp(int a, int b) { return A[a] < A[b]; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &A[i]), q[i] = i, L[i] = i - 1, R[i] = i + 1;
  sort(q + 1, q + n + 1, cmp);
  for (int cas = 1; cas <= n; ++cas) {
    int i = q[cas];
    double l = 0, r = 0, z = 0.5;
    int x = i, y = i;
    for (int c = 0; c < 60; ++c, z /= 2) {
      if (x) l += (x - L[x]) * z, x = L[x];
      if (y <= n) r += (R[y] - y) * z, y = R[y];
    }
    sum += l * r * A[i] * 2;
    L[R[i]] = L[i], R[L[i]] = R[i];
  }
  printf("%.12lf\n", sum / n / n);
  return 0;
}
