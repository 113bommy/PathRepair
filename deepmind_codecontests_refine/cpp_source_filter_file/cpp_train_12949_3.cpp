#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  for (int i = 1; i < n; i++) {
    if (a[i] % a[0] != 0) {
      printf("0");
      return 0;
    }
  }
  printf("%d", a[0]);
  return 0;
}
