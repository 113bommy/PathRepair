#include <bits/stdc++.h>
using namespace std;
int main() {
  for (int i = 25; i <= 50; i++)
    printf("%d\n", ((min(i, 25) + i) % (2 + i % 3) > 0) ? 1 : 0);
  return 0;
}
