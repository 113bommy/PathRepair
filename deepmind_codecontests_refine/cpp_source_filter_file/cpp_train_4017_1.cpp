#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
char a[MAXN], b[MAXN];
int main() {
  int n, lena, lenb, ans;
  scanf("%s", a);
  scanf("%s", b);
  lena = strlen(a);
  lenb = strlen(b);
  ans = max(lena, lenb);
  if (lena == lenb) {
    int i = 0;
    for (i = 0; i < lena; i++) {
      if (a[i] == b[i]) continue;
    }
    if (i == lena) ans = -1;
  }
  printf("%d\n", ans);
  return 0;
}
