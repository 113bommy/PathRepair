#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, s, t, ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    s ^= (x & 1);
  }
  if (s) {
    puts("First");
  } else {
    puts("Second");
  }
  return 0;
}
