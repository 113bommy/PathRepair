#include <bits/stdc++.h>
using namespace std;
const int SIZE = 116;
char buffer[SIZE];
int main() {
  int n, m, i;
  scanf("%d %d", &n, &m);
  for (i = 0; i < 250; i++) {
    printf("%d", 4 + (i % 2));
  }
  printf("5\n");
  for (i = 0; i < 250; i++) {
    printf("%d", 5 - (i % 2));
  }
  printf("5\n");
  return 0;
}
