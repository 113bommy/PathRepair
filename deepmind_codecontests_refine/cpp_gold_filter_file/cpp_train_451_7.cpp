#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned int m, n, l = 0, r = 0;
  scanf("%d", &n);
  m = n;
  while (m) {
    unsigned int s, t;
    scanf("%d %d", &s, &t);
    if (s == 1) l++;
    if (t == 1) r++;
    m--;
  }
  if (n % 2 == 0)
    m = n / 2;
  else
    m = (n + 1) / 2;
  if (r >= m) r = n - r;
  if (l >= m) l = n - l;
  printf("%d", r + l);
  return 0;
}
