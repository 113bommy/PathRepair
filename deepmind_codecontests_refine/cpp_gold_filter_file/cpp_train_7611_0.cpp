#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
int T, k, len;
char s[maxn], a[maxn], b[maxn];
int mp[26], re[26], cnt[26];
void init() {
  memset(mp, -1, sizeof mp);
  memset(re, -1, sizeof re);
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= len; i++) {
    s[i] -= 'a';
    a[i] -= 'a';
    b[i] -= 'a';
  }
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &k);
    scanf("%s%s%s", s + 1, a + 1, b + 1);
    len = strlen(s + 1);
    init();
    int pos = 1;
    for (; pos <= len; pos++) {
      cnt[s[pos]]++;
      if (mp[s[pos]] == a[pos]) continue;
      if (mp[s[pos]] == -1 && re[a[pos]] == -1) {
        mp[s[pos]] = a[pos];
        re[a[pos]] = s[pos];
        continue;
      }
      break;
    }
    if (pos <= len) {
      cnt[s[pos]]--;
      int xx = pos;
      for (; pos > 0; pos--) {
        if (mp[s[pos]] > a[pos]) break;
        if (pos != xx) {
          cnt[s[pos]]--;
          if (!cnt[s[pos]]) mp[s[pos]] = re[a[pos]] = -1;
        }
        if (~mp[s[pos]]) continue;
        int tmp = -1;
        for (int j = a[pos] + 1; j < k; j++) {
          if (~re[j]) continue;
          tmp = j;
          break;
        }
        if (tmp == -1) continue;
        mp[s[pos]] = tmp;
        re[tmp] = s[pos];
        break;
      }
      if (!pos) {
        puts("NO");
        continue;
      }
      for (pos++; pos <= len; pos++) {
        if (~mp[s[pos]]) continue;
        for (int j = 0; j < k; j++) {
          if (~re[j]) continue;
          mp[s[pos]] = j;
          re[j] = s[pos];
          break;
        }
      }
    }
    for (int i = 0; i < k; i++) {
      if (~mp[i]) continue;
      for (int j = 0; j < k; j++) {
        if (~re[j]) continue;
        mp[i] = j;
        re[j] = i;
        break;
      }
    }
    bool f = 1;
    for (int i = 1; i <= len; i++) {
      if (mp[s[i]] < b[i]) break;
      if (mp[s[i]] > b[i]) {
        f = 0;
        break;
      }
    }
    if (!f) {
      puts("NO");
    } else {
      puts("YES");
      for (int i = 0; i < k; i++) printf("%c", (char)('a' + mp[i]));
      puts("");
    }
  }
  return 0;
}
