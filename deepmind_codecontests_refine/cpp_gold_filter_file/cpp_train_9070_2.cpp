#include <bits/stdc++.h>
using namespace std;
int main() {
  int w1, h1, w2, h2;
  scanf("%d %d %d %d", &w1, &h1, &w2, &h2);
  int x = w1 + h1 + w2 + h2;
  printf("%d", x * 2 - 2 * w2 + 4);
  return 0;
}
