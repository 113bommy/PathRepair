#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
char s[maxn];
int n;
bool no[30];
void check() {
  for (int i = 0; i < n; i++) {
    if (no[s[i] - 'a']) {
      puts("NO");
      return;
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] != s[n - 1 - i]) {
      puts("NO");
      return;
    }
  }
  puts("YES");
}
int main() {
  no[1] = no[2] = no[3] = no[4] = no[5] = no[6] = 1;
  no[9] = no[10] = no[11] = 1;
  no[13] = no[15] = no[16] = no[17] = no[18] = no[25] = 1;
  scanf("%s", s);
  n = strlen(s);
  check();
}
