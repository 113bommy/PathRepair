#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, v, sp;
  bool ill;
  scanf("%d", &n);
  ill = false;
  for (sp = 3; n--;) {
    scanf("&d", &v);
    if (v == sp) {
      ill = true;
      break;
    }
    sp = 6 - sp - v;
  }
  if (ill)
    printf("NO\n");
  else
    printf("YES\n");
  return 0;
}
