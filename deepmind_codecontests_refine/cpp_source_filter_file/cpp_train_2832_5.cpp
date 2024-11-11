#include <bits/stdc++.h>
using namespace std;
int as[27], at[27];
int main() {
  ios::sync_with_stdio(0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    string s, t;
    cin >> n;
    cin >> s >> t;
    memset(at, 0, sizeof(at));
    memset(as, 0, sizeof(as));
    for (int i = 0; i < n; i++) {
      as[s[i] - 'a']++;
      at[t[i] - 'a']++;
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (as[i] != at[i]) {
        ok = false;
      }
    }
    if (!ok) {
      puts("NO");
      continue;
    }
    ok = false;
    for (int i = 0; i < 26; i++) {
      if (as[i] >= 2) ok = true;
    }
    if (ok) {
      puts("YES");
      continue;
    }
    int pos;
    for (int i = 0; i < n - 2; i++) {
      pos = -1;
      for (int j = 0; j < n; j++) {
        if (t[j] == s[i]) {
          pos = j;
          break;
        }
      }
      while (pos > i) {
        swap(s[n - 1], s[n - 2]);
        swap(t[pos], t[pos - 1]);
        pos--;
      }
    }
    if (s[n - 1] == t[n - 1]) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
