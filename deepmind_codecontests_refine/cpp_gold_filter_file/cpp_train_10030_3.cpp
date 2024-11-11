#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, r, s, l;
  cin >> n >> m >> r;
  r *= 2;
  l = n / r;
  s = m / r;
  s = s * l;
  if (s == 0)
    printf("Second\n");
  else
    printf("First\n");
  return (0);
}
