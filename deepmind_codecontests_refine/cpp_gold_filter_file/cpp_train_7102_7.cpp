#include <bits/stdc++.h>
using namespace std;
int ps[26][100010];
long long an[26];
int cnt[26];
char s[100010];
int n, k;
int main() {
  scanf("%s%d", &s, &k);
  n = strlen(s);
  if (k > 1ll * n * (n + 1) / 2) {
    puts("No such line.");
    return 0;
  }
  for (int i = 0; i < n; ++i) s[i] -= 'a';
  for (int i = 0; i < n; ++i) an[s[i]] += n - i, ps[s[i]][cnt[s[i]]++] = i;
  while (k > 0) {
    int x;
    for (int i = 0; i < 26; ++i)
      if (an[i]) {
        if (k > an[i]) {
          k -= an[i];
        } else {
          x = i;
          printf("%c", char(i + 'a'));
          goto here;
        }
      }
    break;
  here:;
    int d = cnt[x];
    for (int i = 0; i < 26; ++i) an[i] = cnt[i] = 0;
    for (int i = 0; i < d; ++i) {
      int t = 1 + ps[x][i];
      if (t < n) {
        an[s[t]] += n - t;
        ps[s[t]][cnt[s[t]]++] = t;
      }
    }
    k -= d;
  }
  return 0;
}
