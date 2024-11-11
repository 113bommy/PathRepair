#include <bits/stdc++.h>
using namespace std;
int tac, n;
string s;
char str[200010];
int main() {
  scanf("%d", &tac);
  while (tac--) {
    scanf("%d%s", &n, &str);
    s = str;
    int t, res = 0;
    bool fl = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != s[(i - 1 + n) % n]) {
        fl = 1;
        t = 0;
        while (s[(i + t) % n] == s[i] && t != n) t++;
        if (t < 3) continue;
        t -= 2;
        res += (t + 2) / 3;
      }
    }
    if (!fl) res += (n + 2) / 3;
    printf("%d\n", res);
  }
  return 0;
}
