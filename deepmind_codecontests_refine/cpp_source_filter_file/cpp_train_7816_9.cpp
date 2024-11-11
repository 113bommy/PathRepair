#include <bits/stdc++.h>
using namespace std;
int n, cnt[1000], ans;
char s[101000];
int main(void) {
  scanf("%d%s", &n, s);
  for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;
  for (int i = 0; i < 26; i++) ans += cnt[i] == 1;
  puts(ans == n ? "No" : "Yes");
}
