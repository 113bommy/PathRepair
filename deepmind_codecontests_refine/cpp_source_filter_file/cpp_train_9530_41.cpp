#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc, a, b, c;
  string s;
  scanf("%d", &tc);
  for (int i = 1; i <= tc; i++) {
    cin >> s >> a >> b;
    if (a >= 2400 && b > a) {
      c = 1;
    }
  }
  if (c == 1)
    printf("YES");
  else
    printf("NO");
  return 0;
}
