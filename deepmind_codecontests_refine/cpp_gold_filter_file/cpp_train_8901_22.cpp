#include <bits/stdc++.h>
using namespace std;
int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int getForNum(int num) {
  int res = 0;
  while (num) {
    res += a[num % 10];
    num /= 10;
  }
  return res;
}
int main() {
  int l, r;
  int res = 0;
  scanf("%d %d", &l, &r);
  for (int i = l; i <= r; i++) {
    res += getForNum(i);
  }
  printf("%d", res);
}
