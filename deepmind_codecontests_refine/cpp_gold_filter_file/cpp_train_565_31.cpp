#include <bits/stdc++.h>
using namespace std;
int n, cnt[110000];
char s[10000];
int cur[10000];
int main() {
  cin >> n;
  cin >> (s + 1);
  for (int i = 1; i <= n; i++) cnt[s[i]]++;
  int ans = -1;
  for (int i = 1; i <= n; i++)
    if (s[i] == 'H') {
      for (int j = 0; j <= n; j++) cur[j] = 0;
      for (int j = i; j <= n; j++) cur[++cur[0]] = s[j];
      for (int j = 1; j < i; j++) cur[++cur[0]] = s[j];
      int g = 0;
      for (int j = 1; j <= cnt['H']; j++)
        if (cur[j] == 'T') g++;
      if (ans == -1 || g < ans) ans = g;
    }
  cout << ans;
}
