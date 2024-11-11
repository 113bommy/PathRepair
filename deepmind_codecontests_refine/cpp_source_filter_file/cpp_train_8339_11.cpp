#include <bits/stdc++.h>
using namespace std;
int a, b;
bool f(long long x) {
  if (x * (x + 1) / 2 > a + b) return 0;
  long long m = 1;
  for (; m <= x && m * (m + 1) / 2 <= a; ++m)
    ;
  long long s1 = m * (m - 1) / 2, s2 = x * (x + 1) / 2 - m * (m - 1) / 2;
  if (s1 <= a && s2 <= b) return 1;
  long long dif = a - s1;
  if (dif > x - 1) return 0;
  return s2 - dif <= b;
}
int main() {
  scanf("%d%d", &a, &b);
  int l = 0, h = a + b;
  while (l < h) {
    int m = l + (h - l) / 2;
    if (f(m))
      l = m + 1;
    else
      h = m;
  }
  vector<int> x, y;
  long long i = 1;
  for (i = 1; i < l && i * (i + 1) / 2 <= a; ++i) x.push_back(i);
  for (; i < l; ++i) y.push_back(i);
  long long dif = a - x.size() * (x.size() + 1) / 2;
  if (dif == 0) {
    printf("%d\n", x.size());
    for (int i : x) printf("%d ", i);
    printf("\n%d\n", y.size());
    for (int i : y) printf("%d ", i);
  } else if (x.empty() || y.empty()) {
    if (x.empty()) printf("0\n");
    printf("%d\n", max(x.size(), y.size()));
    for (int i : x.empty() ? y : x) printf("%d ", i);
    if (y.empty()) printf("\n0\n");
  } else if (dif > x.size()) {
    printf("%d\n", x.size());
    printf("%d ", dif + 1);
    for (int i = 1; i < x.size(); ++i) printf("%d ", x[i]);
    printf("\n%d\n", y.size());
    printf("1\n");
    for (int i : y)
      if (i != dif + 1) printf("%d ", i);
  } else {
    printf("%d\n", x.size());
    printf("%d ", x.size() + 1);
    for (int i : x)
      if (i != x.size() + 1 - dif) printf("%d ", i);
    printf("\n%d\n", y.size());
    printf("%d ", x.size() + 1 - dif);
    for (int i = 1; i < y.size(); ++i) printf("%d ", y[i]);
  }
  return 0;
}
