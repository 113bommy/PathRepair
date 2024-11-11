#include <bits/stdc++.h>
using namespace std;
int main() {
  int i;
  printf("9\?\?>>\?\?0\n");
  for (i = 8; i >= 0; i--) printf("%d\?\?<>%d\n", i, i + 1);
  printf("\?\?<>1\n");
  for (i = 9; i >= 0; i--) printf("?%d>>%d?\n", i, i);
  printf(">>?\n");
}
