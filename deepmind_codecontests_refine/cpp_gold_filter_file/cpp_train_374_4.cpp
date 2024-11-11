#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
int n;
string s, ans = "";
int mp[maxn], ct[maxn], in[maxn], out[maxn], used[maxn];
void span(int s) {
  ans = ans + char('a' + s);
  ct[s]--;
  if (mp[s] != -1) span(mp[s]);
}
int main() {
  cin >> n;
  memset(mp, -1, sizeof(mp));
  memset(ct, 0, sizeof(ct));
  for (int i = 0; i < n; ++i) {
    cin >> s;
    int len = s.size();
    if (len > 26) return 0 * printf("NO");
    for (int j = 0; j < len - 1; ++j) {
      ct[s[j] - 'a'] = 1;
      if (s[j] == s[j + 1]) return 0 * printf("NO");
      if (mp[s[j] - 'a'] == -1)
        mp[s[j] - 'a'] = s[j + 1] - 'a', in[s[j + 1] - 'a']++,
                  out[s[j] - 'a']++;
      else if (mp[s[j] - 'a'] != s[j + 1] - 'a')
        return 0 * printf("NO");
    }
    ct[s[len - 1] - 'a'] = 1;
  }
  for (int i = 0; i < 26; ++i)
    if (in[i] > 1 || out[i] > 1) return 0 * printf("NO");
  for (int s = 0; s < 26; ++s)
    if (ct[s] && !in[s]) span(s);
  int f = 0;
  for (int i = 0; i < 26; ++i)
    if (ct[i] != 0) f = 1;
  if (f) return 0 * printf("NO");
  cout << ans << endl;
  return 0;
}
