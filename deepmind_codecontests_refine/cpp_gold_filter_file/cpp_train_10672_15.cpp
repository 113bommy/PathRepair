#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
double pp[N];
int main() {
  int n, p, l, r;
  double ans = 0;
  scanf("%d %d", &n, &p);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &l, &r);
    pp[i] = 1 - (double)(r / p - l / p + (l % p == 0)) / (double)(r - l + 1);
  }
  for (int i = 0; i < n; i++) {
    ans += (1 - pp[i] * pp[(i + 1) % n]);
  }
  printf("%.10lf", ans * 2000);
}
