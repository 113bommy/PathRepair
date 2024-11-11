#include <bits/stdc++.h>
using namespace std;
long long w1, h1, w2, h2, cd, mj1, mj2, mj3;
int main() {
  scanf("%I64d%I64d%I64d%I64d", &w1, &h1, &w2, &h2);
  mj1 = (w1 + 2) * (h1 + 1) - w1 * h1;
  mj2 = (w2 + 2) * (h2 + 1) - w2 * h2;
  mj3 = w1 - w2;
  printf("%I64d", mj1 + mj2 + mj3);
  return 0;
}
