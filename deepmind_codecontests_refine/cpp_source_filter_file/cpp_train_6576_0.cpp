#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  int q;
  cin >> q;
  while (q--) {
    string s, t, p;
    cin >> s >> t >> p;
    int f[101] = {}, f1[101] = {}, j = 0;
    bool can = 1;
    for (int i = 0; i < (int)(t).size(); i++) {
      if (t[i] == s[j]) j++;
    }
    if ((int)(s).size() > j) can = 0;
    for (int i = 0; i < (int)(t).size(); i++) f[t[i] - 'a']++;
    for (int i = 0; i < (int)(p).size(); i++) f1[p[i] - 'a']++;
    for (int i = 0; i < (int)(s).size(); i++) {
      if (f[s[i] - 'a'] == 0)
        can = 0;
      else
        f[s[i] - 'a']--;
    }
    for (int i = 0; i < 25; i++) {
      if (f[i] && f1[i] < f[i]) can = 0;
    }
    cout << (can == 1 ? "YES\n" : "NO\n");
  }
  return 0;
}
