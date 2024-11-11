#include <bits/stdc++.h>
using namespace std;
unsigned int a[111111];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    unsigned int x, y, z, t;
    scanf("\n%d.%d.%d.%d", &x, &y, &z, &t);
    a[i] = (x << 24) + (y << 16) + (z << 8) + t;
  }
  for (int i = 31; i >= 0; i--) {
    unsigned int mask = (1LL << 32) - (1LL << i);
    set<unsigned int> s;
    for (int j = 0; j < n; j++) {
      s.insert(a[j] & mask);
    }
    if (s.size() == k) {
      unsigned int x[4];
      for (int j = 3; j >= 0; j--) {
        x[j] = mask & 0xFF;
        mask >>= 8;
      }
      printf("%d.%d.%d.%d", x[0], x[1], x[2], x[3]);
      return 0;
    }
  }
  cout << -1;
  return 0;
}
