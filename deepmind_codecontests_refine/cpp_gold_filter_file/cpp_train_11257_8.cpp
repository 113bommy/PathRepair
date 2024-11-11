#include <bits/stdc++.h>
int k, n, conti = 0, ans = 0, max_ans = 0;
char s[200005];
int main() {
  scanf("%d %d\n%s", &n, &k, s);
  for (int i = 'a'; i <= 'z'; i++) {
    for (int j = 0; j <= n; j++) {
      if (s[j] == i)
        conti++;
      else {
        conti /= k, ans += conti;
        if (ans > max_ans) max_ans = ans;
        conti = 0;
      }
    }
    ans = 0;
  }
  printf("%d", max_ans);
  return 0;
}
