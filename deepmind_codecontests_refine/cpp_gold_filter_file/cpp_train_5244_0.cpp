#include <bits/stdc++.h>
using namespace std;
int n;
long long rq;
int ax[100111], ay[100111];
int x[200111], y[200111];
int main() {
  scanf("%d %I64d", &n, &rq);
  rq %= n + n;
  scanf("%d %d", x, y);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", ax + i, ay + i);
  }
  for (int i = 0; i < rq; i++) {
    x[i + 1] = 2 * ax[i % n] - x[i];
    y[i + 1] = 2 * ay[i % n] - y[i];
  }
  printf("%d %d", x[rq], y[rq]);
}
