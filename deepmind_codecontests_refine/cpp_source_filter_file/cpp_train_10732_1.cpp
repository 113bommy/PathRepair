#include <bits/stdc++.h>
using namespace std;
string a, b, t, te;
int main() {
  int n, m, flag = 0, s1 = 0, s2 = 0;
  scanf("%d%d", &n, &m);
  cin >> a >> b;
  if (n > m) {
    printf("NO\n");
  } else {
    for (int i = 0; i <= n - 1; i++) {
      if (a[i] == '*') {
        flag = 1;
        t = a.substr(0, i);
        te = b.substr(0, i);
        if (t == te)
          s1 = 1;
        else
          break;
        t = a.substr(i + 1, n - i - 1);
        te = b.substr(m - n + i + 1, n - i - 1);
        if (t == te)
          s2 = 1;
        else
          break;
        break;
      }
    }
    if (!flag) {
      if (a == b)
        printf("YES\n");
      else
        printf("NO\n");
    } else {
      if (s1 && s2)
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
}
