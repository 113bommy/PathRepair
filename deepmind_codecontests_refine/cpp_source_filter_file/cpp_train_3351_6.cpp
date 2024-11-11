#include <bits/stdc++.h>
int sch[26];
int tch[26];
char s[102];
char t[102];
void worker() {
  memset(sch, 0, sizeof(int) * 26);
  memset(tch, 0, sizeof(int) * 26);
  scanf("%s", s);
  scanf("%s", t);
  int n = strlen(s);
  for (int i = 0; i < n; i++) sch[s[i] - 'a'] = 1;
  for (int i = 0; i < n; i++) tch[t[i] - 'a'] = 1;
  for (int i = 0; i < n; i++) {
    if (sch[i] + tch[i] == 2) {
      puts("YES");
      return;
    }
  }
  puts("NO");
}
int main() {
  int q;
  scanf("%d", &q);
  while (q--) worker();
}
