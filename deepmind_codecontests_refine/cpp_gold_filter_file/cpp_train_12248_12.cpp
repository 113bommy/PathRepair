#include <bits/stdc++.h>
using namespace std;
int n, a, b;
void solve(int k) {
  int num = 0;
  for (; k; --k) {
    int st = ++num;
    for (int i = 1; i < a; ++i) printf("%d ", ++num);
    printf("%d ", st);
  }
  while (num < n) {
    int st = ++num;
    for (int i = 1; i < b; ++i) printf("%d ", ++num);
    printf("%d ", st);
  }
}
int main() {
  scanf("%d%d%d", &n, &a, &b);
  if (a < b) swap(a, b);
  for (int k = 0; a * k <= n; ++k)
    if ((n - a * k) % b == 0) {
      solve(k);
      return 0;
    }
  printf("-1");
  return 0;
}
