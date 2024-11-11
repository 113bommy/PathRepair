#include <bits/stdc++.h>
using namespace std;
int a[105];
int n;
int Sum;
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n + 1; ++i) scanf("%d", &a[i]);
  std::sort(a, a + n);
  for (int i = 0; i <= n; ++i) {
    if (a[i] != a[i - 1]) Sum++;
  }
  printf("%d", Sum);
}
