#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int nsd(int a, int b) {
  if (a < b) return nsd(b, a);
  if (b == 0) return a;
  return nsd(b, a % b);
}
int main() {
  scanf("%d", &n);
  int d;
  scanf("%d", &d);
  for (int i = 0; i < n - 1; i++) {
    int x;
    scanf("%d", &x);
    d = nsd(d, x);
    m = max(m, x);
  }
  int s = m / d - n;
  if (s % 2)
    printf("Alice\n");
  else
    printf("Bob\n");
  return 0;
}
