#include <bits/stdc++.h>
using namespace std;
const double PI = 2 * acos(0.0);
int CASE = 1, TEST = 1;
struct vpair {
  int a;
  int b;
  vpair(int a, int b) {
    this->a = a;
    this->b = b;
  }
};
bool cmp(vpair &a, vpair &b) {
  if (a.a < b.a)
    return true;
  else if (a.a == b.a) {
    if (a.b < b.b)
      return true;
    else
      return false;
  } else {
    return false;
  }
}
int arr[1000005] = {0};
int n;
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  if (n <= 2) {
    printf("0\n");
    return 0;
  }
  int a = 0;
  for (int i = 1; i < n - 1; i++) {
    if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
      a++;
    }
    if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
      a++;
    }
  }
  printf("%d\n", a);
  return 0;
}
