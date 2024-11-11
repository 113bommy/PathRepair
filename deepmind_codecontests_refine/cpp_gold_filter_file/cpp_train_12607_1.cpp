#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const int N = 2e5 + 100;
long long int mx[N], d[N], b[N], a[N], x[N];
int main() {
  long long int n, t;
  scanf("%lld%lld", &n, &t);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &x[i]);
    x[i]--;
  }
  for (int i = 1; i < n; i++) {
    if (x[i] < i || x[i] < x[i - 1]) {
      printf("No");
      return 0;
    }
  }
  for (int i = 0, c = 0; i < n; i++) {
    d[x[i]]++;
    c = c + 1 - d[i];
    b[i] = a[i];
    if (c) b[i] = max(b[i], a[i + 1]);
  }
  for (int i = 1; i < n; i++) {
    b[i] = max(b[i], b[i - 1] + 1);
  }
  for (int i = 0; i < n; i++) {
    if (x[i] < n - 1 && b[x[i]] >= a[x[i] + 1]) {
      printf("No");
      return 0;
    }
  }
  printf("Yes\n");
  for (int i = 0; i < n; i++) {
    printf("%lld ", b[i] + t);
  }
  return 0;
}
