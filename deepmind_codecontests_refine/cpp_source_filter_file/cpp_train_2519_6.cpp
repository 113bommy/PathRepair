#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int a, b, n, s;
    scanf("%d%d%d%d", &a, &b, &n, &s);
    if (s % n <= b && a * n + b >= s)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
