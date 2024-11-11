#include <bits/stdc++.h>
using namespace std;
bool ok(int x) {
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
char s[100001];
int can[100001];
int cnt[101];
int main() {
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;
  int gas = 0;
  for (int i = 1; i <= n; i++)
    if (!ok(i) || i * 2 <= n) {
      gas++;
      can[i] = 1;
    }
  int mx = 0, pos = -1;
  for (int i = 0; i < 26; i++)
    if (mx < cnt[i]) mx = cnt[i], pos = i;
  if (mx < gas) return puts("NO");
  puts("YES");
  for (int i = 1; i <= n; i++) {
    if (can[i])
      printf("%c", 'a' + pos), cnt[pos]--;
    else {
      bool bf = 0;
      for (int j = 0; j < 26; j++)
        if (j != pos && cnt[j]) {
          bf = 1;
          cnt[j]--;
          printf("%c", 'a' + j);
          break;
        }
      if (bf) continue;
      for (int j = 0; j < 26; j++)
        if (cnt[j]) {
          bf = 1;
          cnt[j]--;
          printf("%c", 'a' + j);
          break;
        }
    }
  }
}
