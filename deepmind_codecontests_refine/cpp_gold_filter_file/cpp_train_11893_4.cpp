#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 502;
int mat[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
int main() {
  int fillOne = 262143;
  int firstOne = 131072;
  int k;
  scanf("%d", &k);
  if (k == 0) {
    puts("1 1\n42");
    return 0;
  }
  int val = 1;
  while ((val & k) > 0) {
    val = val << 1;
  }
  printf("3 3\n");
  printf("%d %d %d\n", fillOne, val + k, val);
  printf("%d %d %d\n", firstOne, val + k, val);
  printf("%d %d %d\n", firstOne, fillOne, val + k);
  return 0;
}
