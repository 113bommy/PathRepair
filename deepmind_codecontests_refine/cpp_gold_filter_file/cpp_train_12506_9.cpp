#include <bits/stdc++.h>
using namespace std;
const double pi = 2 * acos(0.0);
const int maxn = 1e3 + 10;
const int mod = 1e9 + 7;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int len;
    scanf("%d", &len);
    char s[500];
    scanf("%s", s);
    if (len == 2 && s[0] >= s[1])
      printf("NO\n");
    else {
      printf("YES\n2\n");
      printf("%c %s\n", s[0], s + 1);
    }
  }
  return 0;
}
