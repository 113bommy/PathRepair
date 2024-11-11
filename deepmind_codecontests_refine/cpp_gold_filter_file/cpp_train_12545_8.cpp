#include <bits/stdc++.h>
using namespace std;
int k;
char s[110];
bool was[30];
void init() {
  scanf("%d", &k);
  scanf(" %s ", s);
}
void solve() {
  int len = strlen(s);
  for (int i = 0; i < (len + 1) / 2; i++)
    if (s[i] != '?' && s[len - i - 1] != '?' && s[i] != s[len - i - 1]) {
      printf("IMPOSSIBLE");
      return;
    } else if (s[i] == '?' && s[len - i - 1] != '?')
      s[i] = s[len - i - 1];
    else if (s[i] != '?' && s[len - i - 1] == '?')
      s[len - i - 1] = s[i];
  for (int i = 0; i < (len + 1) / 2; i++)
    if (s[i] != '?') was[s[i] - 'a'] = true;
  int cnt = k - 1;
  for (int i = (len + 1) / 2 - 1; i >= 0; i--) {
    if (s[i] == '?') {
      while (cnt >= 0 && was[cnt]) cnt--;
      if (cnt >= 0)
        s[i] = s[len - i - 1] = cnt + 'a', cnt--;
      else
        s[i] = s[len - i - 1] = 'a';
    }
  }
  while (cnt >= 0 && was[cnt]) cnt--;
  if (cnt >= 0)
    printf("IMPOSSIBLE");
  else
    printf("%s\n", s);
}
int main() {
  init();
  solve();
  return 0;
}
