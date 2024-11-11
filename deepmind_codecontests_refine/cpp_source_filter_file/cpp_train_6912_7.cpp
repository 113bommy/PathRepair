#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 7;
int n;
char s[N];
int main() {
  scanf("%d %s", &n, s);
  int L = strlen(s), ans = 0;
  for (int i = (3); i < (L); ++i)
    if (i % 4 == 0) {
      if (s[i - 3] == s[i - 2] && s[i - 2] == s[i - 1]) {
        ++ans;
      }
    }
  printf("%d", ans);
  return 0;
}
