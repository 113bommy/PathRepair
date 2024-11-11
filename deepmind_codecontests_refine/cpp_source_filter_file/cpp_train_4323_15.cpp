#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 20; i; i--) {
    if ((1 << i) & n) printf("%d ", i);
  }
}
