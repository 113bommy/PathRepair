#include <bits/stdc++.h>
using namespace std;
int Q, n, ans;
char s[100][100];
int main() {
  scanf("%d", &Q);
  while (Q--) {
    int num0 = 0, num1 = 0, vis = 0;
    ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; i++) {
      int l = strlen(s[i] + 1);
      if (l & 1) vis = 1;
      for (int j = 1; j <= l; j++)
        if (s[i][j] == '0')
          num0++;
        else
          num1++;
    }
    if (vis == 1 || (num0 & 1) == 0 || (num1 & 1) == 0)
      printf("%d\n", n);
    else
      printf("%d\n", n - 1);
  }
}
