#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int n;
int ar[100005];
int main() {
  scanf("%d", &n);
  if (n == 2) {
    printf("2 1");
    return 0;
  }
  for (int i = 1; i <= n; i++) ar[i] = i;
  for (int i = 1; i <= n; i++) {
    for (int j = i + i; j <= n; j += i) {
      if (j % i == 0 && ar[j] % i == 0) swap(ar[i], ar[j]);
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", ar[i]);
  return 0;
}
