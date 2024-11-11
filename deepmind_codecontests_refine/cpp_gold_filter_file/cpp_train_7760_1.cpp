#include <bits/stdc++.h>
using namespace std;
map<char, int> m;
char c;
int n;
int flag[100005];
int f[100005];
int main() {
  scanf("%d", &n);
  getchar();
  int t = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%c", &c);
    if (m[c])
      flag[i] = m[c];
    else
      m[c] = ++t, flag[i] = t;
  }
  int k = 0;
  int pos = 0;
  int ans = n;
  for (int i = 1; i <= n; i++) {
    while (k < t && pos < n) {
      pos++;
      if (f[flag[pos]] == 0) k++;
      f[flag[pos]]++;
    }
    if (k < t) break;
    ans = min(ans, pos - i + 1);
    if (f[flag[i]] == 1) k--;
    f[flag[i]]--;
  }
  printf("%d\n", ans);
  return 0;
}
