#include <bits/stdc++.h>
using namespace std;
int ar[300], i, j, n;
char in[210000];
int main() {
  scanf("%s", in);
  memset(ar, -1, sizeof(ar));
  n = strlen(in);
  for (i = 0; i < n; i++) ar[in[i]] = i;
  j = 0;
  for (i = 'z'; i >= 'a'; i--) {
    if (ar[i] == -1 || ar[i] < j) continue;
    for (j = j; j < n; j++) {
      if (in[j] == i) {
        printf("%c", in[j]);
        if (j == ar[i]) break;
      }
    }
  }
  printf("\n");
  return 0;
}
