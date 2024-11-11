#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
char s[N], t[N];
int sn, tn, l = 1, cnt = 1;
int f[50];
int main() {
  scanf("%s%s", s + 1, t + 1);
  sn = strlen(s + 1);
  tn = strlen(t + 1);
  for (int i = 1; i <= sn; i++) {
    if (s[i] == t[cnt]) f[s[i] - 'a'] = ++cnt;
    if (s[i] == t[l]) l++;
    if (f[s[i] - 'a'] < l) l = f[s[i] - 'a'];
    if (l <= 1) {
      printf("No\n");
      return 0;
    }
  }
  if (l <= tn)
    printf("No\n");
  else
    printf("Yes\n");
  return 0;
}
