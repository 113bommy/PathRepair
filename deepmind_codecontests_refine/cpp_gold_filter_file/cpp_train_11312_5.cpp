#include <bits/stdc++.h>
using namespace std;
int t, k;
long long memo[1024][1024][2];
pair<int, int> check[1024];
int len;
char s[1024];
long long countNum(int pos, int last, bool done, bool free) {
  if (free && memo[pos][last][done] >= 0) return (memo[pos][last][done]);
  if (pos == 0) {
    return (done);
  }
  long long ret = 0;
  for (int i = 0; i < (free ? 10 : s[len - pos] - '0'); i++) {
    if (i == 4 || i == 7) {
      ret = (ret + countNum(pos - 1, pos,
                            done | (last != 1002 && (last - pos <= k)), 1));
    } else {
      ret = (ret + countNum(pos - 1, last, done, 1)) % (1000000007);
    }
  }
  return (free ? (memo[pos][last][done] = ret) : (ret));
}
void lucky(char *s) {
  int now = 1002, prev = 1002;
  for (int i = 0; i <= 1000; i++) {
    check[i].first = 1002;
    check[i].second = 0;
  }
  for (int i = 0; s[i]; i++) {
    if (s[i] == '4' || s[i] == '7') {
      prev = now;
      now = i;
    }
    check[i].first = i != now ? now : prev;
    check[i].second =
        (i ? check[i - 1].second : 0) | (prev != 1002 && now - prev <= k);
  }
}
int main() {
  scanf("%d %d", &t, &k);
  memset(memo, -1, sizeof(memo));
  while (t--) {
    scanf("%s", s);
    len = strlen(s);
    lucky(s);
    long long st = 0;
    for (int i = 0; s[i]; i++) {
      st = (st + countNum(len - i,
                          check[i].first != 1002 ? len - check[i].first : 1002,
                          i ? check[i - 1].second : 0, 0)) %
           (1000000007);
    }
    scanf("%s", s);
    len = strlen(s);
    lucky(s);
    long long en = 0;
    for (int i = 0; s[i]; i++) {
      en = (en + countNum(len - i,
                          check[i].first != 1002 ? len - check[i].first : 1002,
                          i ? check[i - 1].second : 0, 0)) %
           (1000000007);
    }
    en = (en + check[len - 1].second) % (1000000007);
    printf("%I64d\n", (en - st + (1000000007)) % (1000000007));
  }
  return (0);
}
