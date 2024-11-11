#include <bits/stdc++.h>
using namespace std;
bool qf = false;
int w, m, i, a[34], top = -1;
int ans = true;
int main() {
  scanf("%d%d", &w, &m);
  while (m) {
    a[++top] = m % w;
    m /= w;
  }
  for (i = 0; i <= top; i++) {
    if (a[i] == 0 or a[i] == 1) continue;
    ;
    if (a[i] != w - 1 and a[i] != w) {
      ans = false;
      break;
    }
    if (i + 1 <= top) a[i + 1]++;
  }
  if (ans)
    printf("YES");
  else
    printf("NO");
  return 0;
}
