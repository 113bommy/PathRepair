#include <bits/stdc++.h>
int take() {
  int n;
  scanf("%d", &n);
  return n;
}
long long takes() {
  long long n;
  scanf("%lld", &n);
  return n;
}
int cas;
using namespace std;
int main() {
  int n = take();
  int a[n + 1], b[n + 1];
  long long f = 0, s = 0;
  for (int i = 1; i <= n; i++) f += take();
  for (int i = 1; i <= n; i++) b[i] = take();
  sort(b + 1, b + 1 + n);
  if (f <= (b[n] + b[n - 1]))
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
