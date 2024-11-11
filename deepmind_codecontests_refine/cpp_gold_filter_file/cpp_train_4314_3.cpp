#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
char s[25];
int m;
long long ans[1 << 18][105];
long long fac(int n) {
  long long out = 1;
  for (int i = 1; i <= n; i++) out *= i;
  return out;
}
int tool[10];
int main() {
  scanf("%s%d", s, &m);
  int len = strlen(s);
  sort(s, s + len);
  for (int i = 0; i < len; i++) {
    if (s[i] - '0') ans[1 << i][(s[i] - '0') % m] = 1;
    tool[s[i] - '0']++;
  }
  for (int i = 1; i < (1 << len) - 1; i++) {
    for (int k = 0; k < m; k++) {
      for (int j = 0; j < len; j++) {
        if (i & (1 << j)) continue;
        ans[i + (1 << j)][(k * 10 + (s[j] - '0')) % m] += ans[i][k];
      }
    }
  }
  long long out = ans[(1 << len) - 1][0];
  for (int i = 0; i <= 9; i++) out /= fac(tool[i]);
  cout << out << '\n';
  return 0;
}
