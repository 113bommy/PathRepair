#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 15;
char s[N], a[N], b[N], mp[128];
bool used[128];
bool dfs(int i, int k, bool low, bool lim) {
  if (!s[i]) {
    return true;
  }
  if (mp[s[i]]) {
    if (low && mp[s[i]] < a[i] || lim && mp[s[i]] > b[i]) {
      return false;
    }
    return dfs(i + 1, k, low & (mp[s[i]] == a[i]), lim & (mp[s[i]] == b[i]));
  } else {
    for (char ch = (low ? a[i] : 'a'); ch <= (lim ? b[i] : k + 'a' - 1); ch++) {
      if (used[ch]) {
        continue;
      }
      mp[s[i]] = ch;
      used[ch] = true;
      if (dfs(i + 1, k, low & (ch == a[i]), lim & (ch == b[i]))) {
        return true;
      }
      mp[s[i]] = 0;
      used[ch] = false;
    }
    return false;
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(used, false, sizeof(used));
    memset(mp, 0, sizeof(mp));
    int k;
    scanf("%d%s%s%s", &k, s, a, b);
    if (dfs(0, k, true, true)) {
      puts("YES");
      for (int i = 'a', j = 'a'; i < k + 'a'; i++) {
        if (!mp[i]) {
          while (used[j]) {
            j++;
          }
          used[j] = true;
          mp[i] = j;
        }
      }
      printf("%.*s\n", k, mp + 'a');
    } else {
      puts("NO");
    }
  }
  return 0;
}
