#include <bits/stdc++.h>
using namespace std;
int n, k;
int search(int x, int y) {
  int mid;
  string str;
  while (x != y) {
    mid = (x + y) / 2;
    printf("1 %d %d\n", mid, mid + 1);
    cin >> str;
    if (str == "TAK") {
      if (y == (x + y) / 2)
        y = (x + y) / 2 - 1;
      else
        y = (x + y) / 2;
    } else {
      if (x == (x + y) / 2)
        x = (x + y) / 2 + 1;
      else
        x = (x + y) / 2;
    }
  }
  return x;
}
int cmp(int x) {
  int tmp;
  string str;
  if (x == n) return -1;
  tmp = search(x + 1, n);
  printf("1 %d %d\n", tmp, x);
  cin >> str;
  if (str == "TAK")
    return tmp;
  else
    return -1;
}
int main(void) {
  int num1, num2;
  cin >> n >> k;
  num1 = search(1, n);
  num2 = cmp(num1);
  if (num2 == -1) num2 = search(1, num1 - 1);
  printf("2 %d %d\n", num1, num2);
  return 0;
}
