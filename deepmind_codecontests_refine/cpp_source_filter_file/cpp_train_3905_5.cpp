#include <bits/stdc++.h>
using namespace std;
int n, d;
struct trieType {
  int nxt[10];
  int fail;
  int depth;
} trie[25005];
int cntTrie;
char str[1005];
int s[1005];
int x[55], y[55];
int qhy[25005], closed, open;
int dp[55][25005];
bool zyg = true;
void get_number(int* a, int& len) {
  int i;
  scanf("%s", str);
  len = strlen(str);
  for (i = 0; i < len; i++) a[len - i - 1] = str[i] - '0';
}
void standing_by() {
  int i, j, k;
  get_number(s, n);
  get_number(x, d);
  get_number(y, d);
  for (i = n; i >= d / 2; i--) {
    for (j = 1, k = 0; j <= d / 2; j++) {
      if (trie[k].nxt[s[i - j]] == 0) trie[k].nxt[s[i - j]] = ++cntTrie;
      k = trie[k].nxt[s[i - j]];
      trie[k].depth = j;
    }
  }
  for (i = 0; i < 10; i++)
    if (trie[0].nxt[i] == 0) qhy[++open] = trie[0].nxt[i];
  do {
    closed++;
    if (trie[qhy[closed]].depth == d / 2) {
      for (i = 0; i < 10; i++) trie[qhy[closed]].nxt[i] = qhy[closed];
    } else
      for (i = 0; i < 10; i++)
        if (trie[qhy[closed]].nxt[i]) {
          qhy[++open] = trie[qhy[closed]].nxt[i];
          trie[qhy[open]].fail = trie[trie[qhy[closed]].fail].nxt[i];
        } else
          trie[qhy[closed]].nxt[i] = trie[trie[qhy[closed]].fail].nxt[i];
  } while (closed < open);
  for (i = 0; i <= cntTrie; i++)
    if (trie[i].depth == d / 2) dp[0][i] = 1;
  for (i = 1; i <= d; i++)
    for (j = 0; j <= cntTrie; j++)
      for (k = 0; k < 10; k++)
        dp[i][j] = (dp[i][j] + dp[i - 1][trie[j].nxt[k]]) % 1000000007;
}
long long solve(int* a) {
  int i, j, k;
  long long ans = 0;
  for (i = d, j = 0; i > 0; i--) {
    for (k = 0; k < a[i - 1]; k++)
      ans = (ans + dp[i - 1][trie[j].nxt[k]]) % 1000000007;
    j = trie[j].nxt[k];
  }
  if (trie[j].depth == d / 2 && zyg) ans = (ans + 1) % 1000000007;
  zyg = false;
  return ans;
}
void complete() {
  long long ans = solve(y);
  ans = (ans - solve(x)) % 1000000007;
  if (ans < 0) ans += 1000000007;
  printf("%lld\n", ans);
}
int main() {
  standing_by();
  complete();
  return 0;
}
