#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110000;
bool b[26], t[26];
int main() {
  int n;
  scanf("%d", &n);
  memset(b, 1, sizeof b);
  bool flag = 0;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    char op;
    string w;
    cin >> op >> w;
    switch (op) {
      case '.':
        for (char c : w) b[c - 'a'] = 0;
        break;
      case '!':
        memset(t, 0, sizeof t);
        for (char c : w) t[c - 'a'] = 1;
        for (int j = 0; j < 26; j++)
          if (!t[j]) b[j] = 0;
        break;
      case '?':
        b[w[0] - 'a'] = 0;
        break;
    }
    if (flag) {
      if (op == '!' || op == '?' && i != n) ans++;
    } else {
      int cnt = 0;
      for (int j = 0; j < 26; j++)
        if (b[j]) cnt++;
      if (cnt == 1) flag = 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}
