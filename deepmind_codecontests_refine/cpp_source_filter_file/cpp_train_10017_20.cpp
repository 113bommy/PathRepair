#include <bits/stdc++.h>
#pragma warning(disable : 4786)
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int N;
int a[200];
int sum;
int main() {
  int i, ev;
  while (scanf("%d", &N) == 1) {
    sum = 0, ev = 0;
    for (i = 0; i < N; i++) {
      scanf("%d", &a[i]);
      sum += a[i];
      if (a[i] % 2 == 0) ev++;
    }
    if (sum & 1) {
      printf("%d\n", 1);
    } else
      printf("%d\n", ev);
  }
  return 0;
}
