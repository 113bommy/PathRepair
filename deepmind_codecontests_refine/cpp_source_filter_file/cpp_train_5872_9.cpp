#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1000000000")
using namespace std;
const double pi = acos(-1.0);
int n, k;
void printftype() {
  printf("v");
  for (int i = 0; i < 66; i++)
    if (i % 2 == 0)
      printf(" ");
    else
      printf("<");
  for (int i = 0; i < 33; i++) printf("<");
  printf("\n");
}
void printstype() {
  for (int i = 0; i < 33; i++) printf(">");
  for (int i = 0; i < 66; i++)
    if (i % 2 == 0)
      printf(" ");
    else
      printf(">");
  printf("^");
  printf("\n");
}
int main() {
  scanf("%d%d", &n, &k);
  if (n == 5) {
    printf(">...v\nv.<..\n..^..\n>....\n..^.<\n1 1\n");
  }
  if (n == 3) {
    printf(">vv\n^<.\n^.<\n1 3\n");
  }
  if (n == 100) {
    for (int i = 0; i < 50; i++) {
      printftype();
      printstype();
    }
    printf("1 1\n");
  }
  return 0;
}
