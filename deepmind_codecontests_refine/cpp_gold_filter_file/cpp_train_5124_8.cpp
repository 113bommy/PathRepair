#include <bits/stdc++.h>
using namespace std;
char op[150];
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    int ans = 0, at = 0;
    scanf("%d", &n);
    scanf("%s", op);
    for (int i = 0; op[i]; i++) {
      if (op[i] == 'A')
        at = 1;
      else if (at)
        ++at;
      ans = max(at, ans);
    }
    printf("%d\n", max(ans - 1, 0));
  }
  return 0;
}
