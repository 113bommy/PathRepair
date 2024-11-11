#include <bits/stdc++.h>
using namespace std;
int main() {
  int count = 0;
  double l, r;
  scanf("%lf %lf", &l, &r);
  int x, y;
  for (x = 0; x < ceil(log2(r)); x++) {
    for (y = 0; y < ceil(log2(r) / log2(3)); y++) {
      if (pow(2, x) * pow(3, y) >= l && pow(2, x) * pow(3, y) <= r) count++;
    }
  }
  printf("%d\n", count);
}
