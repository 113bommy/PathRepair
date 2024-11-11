#include <bits/stdc++.h>
using namespace std;
int a[100001] = {0}, b[100001] = {0};
int i, k, l, m, n, o, p;
int main() {
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d ", &a[i]);
  }
  b[n] = a[n - 1] - 1;
  for (int i = n - 1; i > -1; i--) {
    b[i] = max(b[i + 1], a[i + 1]);
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", max(0, b[i] - a[i] + 1));
  }
  exit(0);
}
