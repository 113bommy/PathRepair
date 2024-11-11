#include <bits/stdc++.h>
using namespace std;
int n, m;
int gg(int asd) {
  int res = 0;
  while (asd) {
    res++;
    asd /= 2;
  }
  return res;
}
int main() {
  scanf("%d %d", &n, &m);
  if (gg(m) < n)
    printf("%d", &m);
  else
    printf("%d", m % ((1 << n)));
  return 0;
}
