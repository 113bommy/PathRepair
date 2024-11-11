#include <bits/stdc++.h>
using namespace std;
int main() {
  for (register int k = 21; k <= 50; ++k) {
    printf("%d\n", ((min(k, 25) + k) % (2 + k % 3) > 0) ? 1 : 0);
  }
  return 0;
}
