#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int a[2000];
int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int parity = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] > a[j]) parity ^= 1;
    }
  }
  scanf("%d", &m);
  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    int num = r - l + 1;
    num = num * (num - 1) / 2;
    if (num & 1) parity ^= 1;
    if (parity)
      puts("odd");
    else
      puts("even");
  }
  return 0;
}
