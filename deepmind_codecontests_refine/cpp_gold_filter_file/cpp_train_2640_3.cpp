#include <bits/stdc++.h>
char s[200010];
char t[200010];
int main() {
  int lens;
  int lent;
  int front[200010];
  int tail[200010];
  int pos[30];
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  lens = strlen(s + 1);
  lent = strlen(t + 1);
  int j = 1;
  memset(front, 0, sizeof(front));
  memset(tail, 0, sizeof(tail));
  memset(pos, 0, sizeof(pos));
  for (int i = 1; i <= lens; i++) {
    if (j <= lent && s[i] == t[j]) {
      pos[s[i] - 'a'] = j;
      j++;
    }
    front[i] = pos[s[i] - 'a'];
  }
  memset(pos, 0, sizeof(pos));
  j = lent;
  for (int i = lens; i >= 1; i--) {
    if (j >= 1 && s[i] == t[j]) {
      pos[s[i] - 'a'] = lent - j + 1;
      j--;
    }
    tail[i] = pos[s[i] - 'a'];
  }
  bool ans = true;
  for (int i = 1; i <= lens && ans; i++)
    if (front[i] + tail[i] <= lent) {
      ans = false;
    }
  if (ans)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
