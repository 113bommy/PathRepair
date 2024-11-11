#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  for (int it = 0; it < t; it++) {
    int n, cnt = 0, res;
    char c;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
      scanf("%c", &c);
      if (c == '(')
        cnt++;
      else
        cnt--;
      res = max(res, -cnt);
    }
    printf("%d\n", res);
  }
}
