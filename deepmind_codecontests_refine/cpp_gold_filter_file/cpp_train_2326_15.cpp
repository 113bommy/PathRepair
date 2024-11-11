#include <bits/stdc++.h>
using namespace std;
int main() {
  int m[20000];
  int d, n, s;
  scanf("%d", &d);
  scanf("%d", &n);
  s = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &m[i]);
  }
  for (int i = 1; i < n; i++) {
    s = s + (d - m[i]);
  }
  printf("%d", s);
  return 0;
}
