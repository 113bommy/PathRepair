#include <bits/stdc++.h>
using namespace std;
int n, k, T, S;
int v[26][26], t[26];
int s[26], bin[26];
char ch[200010];
int f[4194304], x;
int main() {
  scanf("%d%d%d%s", &n, &k, &T, ch + 1);
  for (int i = 0; i < k; i++) scanf("%d", &t[i]);
  for (int i = 0; i < k; i++)
    for (int j = 0; j < k; j++) scanf("%d", &v[i][j]);
  bin[0] = 1;
  for (int i = 1; i <= k; i++) bin[i] = bin[i - 1] << 1;
  for (int i = 0; i < k; ++i) f[bin[i]] = t[i];
  memset(s, -1, sizeof(s));
  S = bin[n + 1];
  for (int i = n - 1; i; i--) {
    x = ch[i] - 'A';
    S |= bin[x];
    for (int c = 0; c < 26; c++)
      if (~s[c]) s[c] |= bin[ch[i + 1] - 'A'];
    s[ch[i + 1] - 'A'] = 0;
    for (int c = 0; c < k; c++)
      if (~s[c]) {
        if (!(s[c] & bin[c]) && !(s[c] & bin[x])) {
          f[s[c]] += v[x][c];
          f[s[c] | bin[x]] -= v[x][c];
          f[s[c] | bin[c]] -= v[x][c];
          f[s[c] | bin[c] | bin[x]] += v[x][c];
        }
      }
  }
  for (int j = 0; j < k; j++)
    for (int i = 0; i < bin[k]; i++)
      if (bin[j] & i) f[i] += f[i ^ bin[j]];
  int ans = 0;
  for (int i = 0; i < bin[k]; i++)
    if ((i & S) == i && f[i] <= T && (i ^ S)) ans++;
  cout << ans;
}
