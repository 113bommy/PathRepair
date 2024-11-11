#include <bits/stdc++.h>
using namespace std;
int now[15];
char s[15];
void query(int l, int r) {
  printf("next");
  for (int i = l; i <= r; i++) printf(" %d", i);
  puts("");
  fflush(stdout);
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    for (int j = 1; j <= len; j++) now[s[j] - '0'] = i;
  }
}
int main() {
  query(0, 1);
  query(1, 1);
  int tot = 1;
  while (now[0] != now[1]) {
    query(0, 1);
    query(1, 1);
    tot++;
  }
  int c = 1;
  query(1, 1);
  while (now[0] != now[1]) {
    query(1, 1);
    c++;
  }
  while (tot > c) {
    query(2, 9);
    tot--;
  }
  while (now[0] != now[2]) query(0, 9);
  puts("done");
}
