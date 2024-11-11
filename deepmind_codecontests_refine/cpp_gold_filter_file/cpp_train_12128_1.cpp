#include <bits/stdc++.h>
using namespace std;
int n, m, k;
bool debug = false;
long long x[100005], y[100005], px, py, tt;
long long cc(int i, int j) {
  return (px - x[i]) * (y[j] - y[i]) - (x[j] - x[i]) * (py - y[i]);
}
bool cic() {
  if (n < 3) return false;
  if (cc(0, 1) < 0) return false;
  if (cc(0, n - 1) > 0) return false;
  int i = 2, j = n - 1;
  int line = -1;
  while (i <= j) {
    int mid = (i + j) >> 1;
    if (cc(0, mid) < 0) {
      line = mid;
      j = mid - 1;
    } else
      i = mid + 1;
  }
  return cc(line - 1, line) > 0;
}
void deal() {
  int j = 2;
  long long x1, x2, y1, y2;
  long long ans = 0;
  for (int i = 0; i < n;) {
    x1 = x[j] - x[i];
    x2 = px - x[i];
    y1 = y[j] - y[i];
    y2 = py - y[i];
    if (x1 * y2 - x2 * y1 < 0) {
      j = (j + 1) % n;
    } else {
      long long xxx = j - 1 > i ? (j - 1) - i : (j - 1) - i + n;
      if (xxx >= 2) ans += xxx * (xxx - 1) / 2;
      i++;
    }
  }
  printf("%I64d\n", tt - ans);
}
int main() {
  scanf("%d", &n);
  tt = (long long)n * (n - 1) * (n - 2) / 6;
  for (int i = 0; i < n; i++) scanf("%I64d%I64d", x + i, y + i);
  scanf("%d", &k);
  while (k--) {
    scanf("%I64d%I64d", &px, &py);
    if (cic())
      deal();
    else
      puts("0");
  }
  return 0;
}
