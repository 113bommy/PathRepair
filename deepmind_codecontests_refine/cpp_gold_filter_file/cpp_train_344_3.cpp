#include <bits/stdc++.h>
using namespace std;
const int N = 5020;
char s[N], t[N];
int cnt[30], ans[N];
int lens, lent, tot;
void print(int k) {
  for (int i = 0; i <= k; i++) printf("%c", ans[i]);
  for (int i = 0; i < 26; i++)
    for (int j = 1; j <= cnt[i]; j++) printf("%c", i + 'a');
  exit(0);
}
void dfs(int k) {
  if (k == lent) {
    if (k < lens) print(k - 1);
    return;
  }
  if (k == lens) return;
  int cht = t[k] - 'a';
  if (cnt[cht] > 0) {
    cnt[cht]--;
    ans[k] = t[k];
    dfs(k + 1);
    cnt[cht]++;
  }
  for (int i = cht + 1; i < 26; i++)
    if (cnt[i]) {
      cnt[i]--;
      ans[k] = i + 'a';
      print(k);
    }
}
int main() {
  scanf("%s", s);
  scanf("%s", t);
  lens = strlen(s);
  lent = strlen(t);
  for (int i = 0; i < lens; i++) cnt[s[i] - 'a']++;
  dfs(0);
  cout << -1;
}
