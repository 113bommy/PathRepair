#include <bits/stdc++.h>
using namespace std;
int main() {
  char str1[10010], str2[10010];
  long long int m, l, r, k;
  scanf("%s", str1);
  long long int len = strlen(str1);
  cin >> m;
  while (m--) {
    long long int bg = 0, j, i, k1;
    cin >> l >> r >> k;
    k1 = k % (r - l + 1);
    for (i = r - k1; i <= r - 1; i++) {
      str2[bg++] = str1[i];
    }
    for (i = l - 1; i <= r - k1 - 1; i++) {
      str2[bg++] = str1[i];
    }
    for (i = l - 1, j = 0; i <= r - 1, j < bg; i++, j++) {
      str1[i] = str2[j];
    }
  }
  printf("%s\n", str1);
  return 0;
}
