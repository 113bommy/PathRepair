#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 7;
int a[maxn];
int main() {
  int n, k;
  cin >> n >> k;
  int sum = 0;
  for (int i = 0; i < k; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  if (n % 2 != 0) {
    if (sum % 2 != 0) {
      printf("odd\n");
    } else {
      printf("even\n");
    }
  } else {
    if (a[k - 1] % 2 == 0) {
      printf("even\n");
    } else {
      printf("odd\n");
    }
  }
  return 0;
}
