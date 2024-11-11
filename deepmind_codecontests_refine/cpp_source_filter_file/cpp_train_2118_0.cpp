#include <bits/stdc++.h>
using namespace std;
int n, d;
int check2(int n, int d) {
  int p = 1;
  for (int i = 1; i <= d; i++) {
    p = p * n % d;
    if (p == 0) return i;
  }
  return -1;
}
bool check3(int n, int d) { return (n - 1) % d == 0; }
bool check11(int n, int d) { return (n + 1) % d == 0; }
bool check6(int n, int d) {
  int b = d;
  for (int i = 2; i <= d; i++)
    if (d % i == 0) {
      int p = 1;
      while (d % i == 0) d /= i, p *= i;
      if (p == b) return false;
      if (!check2(n, i) && !check3(n, i) && !check11(n, i)) return false;
    }
  return true;
}
void print() {
  if (check2(n, d) != -1) {
    printf("2-type\n");
    printf("%d\n", check2(n, d));
    return;
  }
  if (check3(n, d)) {
    printf("3-type\n");
    return;
  }
  if (check11(n, d)) {
    printf("11-type\n");
    return;
  }
  if (check6(n, d)) {
    printf("6-type\n");
    return;
  }
  printf("7-type\n");
}
int main() {
  scanf("%d %d", &n, &d);
  print();
  return 0;
}
