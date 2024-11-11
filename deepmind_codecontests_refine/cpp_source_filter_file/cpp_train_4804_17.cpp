#include <bits/stdc++.h>
using namespace std;
const int N = 5010, M = 20010;
int main() {
  int T;
  scanf("%d", &T);
  int t = (T - 800000) / 800000;
  int rem = T - t * 799999 + 2;
  printf("%d\n-1 ", t + 2);
  for (int i = 1; i <= t; i++) printf("800000 ");
  printf("%d\n", rem);
  return 0;
}
