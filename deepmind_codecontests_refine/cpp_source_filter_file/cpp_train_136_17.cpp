#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
int main() {
  int a, b, c;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  a *= c;
  int l = 1, r = 1000, mid;
  while (l < r) {
    mid = l + (r - l) / 2;
    if (mid * b + b * c >= a)
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d", r);
  return 0;
}
