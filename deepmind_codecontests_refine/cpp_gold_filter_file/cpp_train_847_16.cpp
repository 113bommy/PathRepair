#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, m;
  while (scanf("%d%d%d", &a, &b, &m) == 3) {
    set<int> rems;
    int r = 1000000000 % m;
    int rem = (r + b) % m;
    int i = 1;
    if (r)
      while (rem <= b && i <= a) {
        int k = (b - rem + r) / r;
        i += k;
        rem += k * r;
        while (rem >= m) rem -= m;
        if (rems.insert(rem).second == false) i = a + 1;
      }
    if (rem > b && i <= a) {
      printf("1 %09d\n", i);
      break;
    } else
      printf("2\n");
  }
  return 0;
}
