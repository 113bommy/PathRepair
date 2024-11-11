#include <bits/stdc++.h>
using namespace std;
int k;
char M[5][7];
int C[256];
int main() {
  scanf("%d", &k);
  for (int i = (0); i < (5); ++i) {
    scanf("%s", &M[i]);
    for (int j = (0); j < (5); ++j) C[M[i][j]]++;
  }
  for (int i = ('1'); i < ('9' + 1); ++i)
    if (C[i] > 2 * k) {
      printf("NO\n");
      return 0;
    }
  printf("YES\n");
  return 0;
}
