#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  scanf("%d", &N);
  if (N <= 2)
    printf("%d", -1);
  else {
    for (int i = N; i >= 1; i--) {
      printf("%d", i);
      printf(" ");
    }
  }
  return 0;
}
