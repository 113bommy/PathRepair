#include <bits/stdc++.h>
using namespace std;
int main() {
  int K;
  scanf("%d", &K);
  puts("3 2");
  printf("262143 %d\n", K);
  printf("%d 262143\n", 262143 ^ K);
  printf("0 %d\n", K);
  return 0;
}
