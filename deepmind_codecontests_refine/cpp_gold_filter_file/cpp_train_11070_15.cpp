#include <bits/stdc++.h>
using namespace std;
struct grad {
  long long a, b;
};
int n, c;
long long lowerx, upperx;
grad g[10000 + 1];
bool inf = true;
int calc(long long x) {
  long long ret = 0;
  long long pom;
  for (int i = 1; i <= n; i++) {
    double kurcina = (1000000000000000000LL * 1.0) / (x * 1.0);
    if (kurcina < g[i].a) {
      return c + 1;
    }
    pom = x * g[i].a;
    pom /= g[i].b;
    ret += pom;
  }
  ret += n;
  if (ret > c) return c + 1;
  if (ret < c) return c - 1;
  return c;
}
long long binarylower() {
  int sum;
  long long upper = 1000000000000000000LL;
  long long lower = 1;
  long long pivot;
  while (lower < upper) {
    pivot = (lower + upper) / 2;
    sum = calc(pivot);
    if (sum == c + 1) upper = pivot - 1;
    if (sum == c) upper = pivot;
    if (sum == c - 1) lower = pivot + 1;
  }
  sum = calc(upper);
  if (lower == upper && sum == c) return upper;
  return -1;
}
long long binaryupper() {
  int sum;
  long long upper = 1000000000000000000LL;
  long long lower = 1;
  long long pivot;
  while (lower < upper) {
    pivot = (lower + upper) / 2;
    if (upper - lower == 1) pivot++;
    sum = calc(pivot);
    if (sum == c + 1) upper = pivot - 1;
    if (sum == c) lower = pivot;
    if (sum == c - 1) lower = pivot + 1;
  }
  sum = calc(upper);
  if (lower == upper && sum == c) return upper;
  return -1;
}
int main() {
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &g[i].a, &g[i].b);
    if (g[i].a > 0) inf = false;
  }
  if (c != n) inf = false;
  if (inf) {
    printf("-1\n");
    return 0;
  }
  if (n > c) {
    printf("0\n");
    return 0;
  }
  lowerx = binarylower();
  upperx = binaryupper();
  if (lowerx == -1 || upperx == -1) {
    printf("0\n");
    return 0;
  }
  cout << upperx - lowerx + 1 << endl;
  return 0;
}
