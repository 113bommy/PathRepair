#include <bits/stdc++.h>
using namespace std;
const double PI = 2 * acos(0.0);
int CASE = 1, TEST = 0;
struct vpair {
  double a;
  int indx;
  vpair(double a, int b) {
    this->a = a;
    this->indx = b;
  }
};
bool cmp(vpair &a, vpair &b) {
  if (a.a < b.a)
    return true;
  else if (a.a == b.a) {
    if (a.indx > b.indx)
      return true;
    else
      return false;
  } else {
    return false;
  }
}
int n, m, a, b;
int arr[10] = {1, 10};
int main(void) {
  for (int i = 1; i <= 9; i++) {
    arr[i] = arr[i - 1] * 10;
  }
  scanf("%d", &n);
  if (n < 9) {
    printf("1\n");
  } else {
    for (int i = 1; i <= 9; i++) {
      if (n <= arr[i]) {
        printf("%d\n", (arr[i - 1] * ((n / arr[i - 1]) + 1)) - n);
        return 0;
      }
    }
  }
  return 0;
}
