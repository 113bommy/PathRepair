#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int i, j, k, l, m, n, t;
  int arr[110];
  scanf("%d", &n);
  int mx = -1;
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  sort(arr, arr + n);
  mx = arr[n - 1];
  int diff = arr[1] - arr[0];
  bool flag = true;
  int g = 0;
  for (i = 0; i < n; i++) {
    g = gcd(arr[i], g);
  }
  int lft = mx / g - n;
  if (lft % 2)
    printf("ALICE");
  else
    printf("BOB");
  return 0;
}
