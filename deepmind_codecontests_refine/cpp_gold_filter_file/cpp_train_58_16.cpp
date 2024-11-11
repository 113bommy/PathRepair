#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, m, a[120];
  bool cheak;
  scanf("%d%d", &n, &m);
  memset(a, 0, sizeof(a));
  char s[1000];
  string b;
  int size;
  int p = 1;
  for (int i = 0; i < n; i++) {
    scanf("%s", &s);
    b = (string)s;
    if (b == "alloc") {
      scanf("%d", &size);
      cheak = false;
      int kl = 0;
      int j = 0;
      while (j != m) {
        if (!a[j])
          kl++;
        else
          kl = 0;
        if (kl == size) {
          cheak = true;
          for (int k = j - kl + 1; k <= j; k++) a[k] = p;
          printf("%d\n", p++);
          break;
        }
        j++;
      }
      if (!cheak) printf("NULL\n");
    } else if (b == "erase") {
      scanf("%d", &size);
      cheak = false;
      for (int j = 0; j < m; j++)
        if (a[j] == size) {
          cheak = true;
          a[j] = 0;
        }
      if (!cheak || !size) printf("ILLEGAL_ERASE_ARGUMENT\n");
    } else {
      int fre = 0;
      for (int j = 0; j < m; j++) {
        if (a[j]) {
          a[fre] = a[j];
          if (j != fre) a[j] = 0;
          fre++;
        }
      }
    }
  }
  return 0;
}
