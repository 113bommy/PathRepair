#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
int in() {
  int a;
  scanf("%d", &a);
  return a;
}
double din() {
  double a;
  scanf("%lf", &a);
  return a;
}
int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
long long d[30];
int main() {
  int n = in();
  scanf("\n");
  string a, b;
  cin >> a >> b;
  double res, k;
  res = k = 0;
  for (int i = 1; i <= n; ++i) {
    d[a[i - 1] - 'A'] += i;
    res += d[b[i - 1] - 'A'] * (double)(n - i + 1);
  }
  memset(d, 0, 30 * sizeof(long long));
  for (int i = 1; i <= n; ++i) {
    res += (double)(n - i + 1) * d[a[i - 1] - 'A'];
    d[b[i - 1] - 'A'] += i;
  }
  for (int i = 1; i <= n; ++i) {
    k += (double)(n - i + 1) * (n - i + 1);
  }
  printf("%.9lf", (double)res / k);
  return 0;
}
