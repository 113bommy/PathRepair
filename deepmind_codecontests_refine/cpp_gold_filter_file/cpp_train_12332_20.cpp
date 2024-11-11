#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-6;
int ROUND(double x) { return (int)(x + 0.5); }
bool ISINT(double x) { return fabs(ROUND(x) - x) <= EPS; }
bool ISEQUAL(double x, double y) {
  return fabs(x - y) <= EPS * max(1.0, max(fabs(x), fabs(y)));
}
double SQSUM(double x, double y) { return x * x + y * y; }
template <class T>
bool INRANGE(T x, T a, T b) {
  return a <= x && x <= b;
}
int main() {
  int a[5];
  scanf("%d %d %d %d %d ", &a[4], &a[3], &a[2], &a[1], &a[0]);
  int K;
  scanf("%d ", &K);
  const char* sz[] = {
      "XXL", "XL", "L", "M", "S",
  };
  const int choose[5][5] = {
      {0, 1, 2, 3, 4}, {1, 0, 2, 3, 4}, {2, 1, 3, 0, 4},
      {3, 2, 4, 1, 0}, {4, 3, 2, 1, 0},
  };
  for (int i = 0; i < K; i++) {
    char str[256];
    scanf("%s ", str);
    int n;
    for (n = 0; n < 5; n++) {
      if (strcmp(sz[n], str) == 0) {
        break;
      }
    }
    for (int k = 0; k < 5; k++) {
      if (a[choose[n][k]] > 0) {
        a[choose[n][k]]--;
        printf("%s\n", sz[choose[n][k]]);
        break;
      }
    }
  }
}
