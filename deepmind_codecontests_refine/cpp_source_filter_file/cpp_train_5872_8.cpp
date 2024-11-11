#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  if (n == 5) {
    printf(">...v\nv.<..\n..^..\n>....\n..^.<\n1 1\n");
    return 0;
  }
  if (n == 3) {
    printf(">vv\n^<.\n^.<\n1 3");
    return 0;
  }
  for (int i = 1; i <= 50; i++) {
    for (int j = 1; j <= 34; j++) printf(">");
    for (int j = 1; j <= 32; j++) printf(".>");
    printf(".v\n");
    printf("^.");
    for (int j = 1; j <= 32; j++) printf("<.");
    for (int j = 1; j <= 34; j++) printf("<");
    printf("\n");
  }
  printf("1 1\n");
  return 0;
}
