#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int base[35];
int a[100100], mk[100100];
int num[35];
int main() {
  int n;
  scanf("%d", &n);
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 30; j >= 0; j--) {
      if (a[i] >> j) {
        num[j]++;
        base[j] = i;
      }
    }
  }
  int fg = 0;
  for (int i = 30; i >= 0; i--) {
    if (num[i] == 1) {
      printf("%d", a[base[i]]);
      mk[base[i]] = 1;
      fg = 1;
      break;
    }
  }
  if (!fg) {
    mk[1] = 1;
    printf("%d", a[1]);
  }
  for (int i = 1; i <= n; i++) {
    if (!mk[i]) {
      printf(" %d", a[i]);
    }
  }
  printf("\n");
  return 0;
}
