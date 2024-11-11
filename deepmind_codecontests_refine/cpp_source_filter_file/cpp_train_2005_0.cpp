#include <bits/stdc++.h>
using namespace std;
int n;
int k;
int ans[300005];
string a;
string b;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    k = 0;
    int n;
    scanf("%d", &n);
    cin >> a >> b;
    int i = n - 1;
    ;
    while (i >= 0) {
      if (a[i] == b[i]) {
        i--;
        continue;
      }
      if (a[0] == b[i]) ans[k++] = 1;
      ans[k++] = i + 1;
      int ii = 0, jj = i;
      for (int k = 0; k <= jj; ++k) {
        if (a[k] == '1')
          a[k] = '0';
        else
          a[k] = '1';
      }
      while (ii < jj) swap(a[ii++], b[jj--]);
      i--;
    }
    printf("%d ", k);
    for (int i = 0; i < k; ++i) printf("%d ", ans[i]);
    putchar('\n');
  }
}
