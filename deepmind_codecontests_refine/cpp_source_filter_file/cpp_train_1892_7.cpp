#include <bits/stdc++.h>
using namespace std;
int t, a[2000 + 10][2000 + 10], ans[2000 + 10][2000 + 10], viz[30];
pair<int, int> fs[30], ls[30];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    int n, m, l = 0;
    pair<int, int> aux = {0, 0};
    cin >> n >> m;
    for (int i = 1; i <= 26; i++) viz[i] = 0, fs[i] = {0, 0}, ls[i] = {0, 0};
    for (int i = 1; i <= n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) {
        if (s[j] >= 'a' && s[j] <= 'z')
          a[i][j + 1] = s[j] - 'a' + 1;
        else
          a[i][j + 1] = 0;
      }
    }
    for (int ch = 1; ch <= 26; ch++)
      for (int i = 1; i <= n && !viz[ch]; i++)
        for (int j = 1; j <= m && !viz[ch]; j++)
          if (a[i][j] == ch) {
            viz[ch] = 1;
            fs[ch] = {i, j};
            int j1 = j + 1, i1 = i + 1, ok = 0;
            while (j1 <= m) {
              if (a[i][j1] == ch) ok = 1, ls[ch] = {i, j1};
              j1++;
            }
            while (i1 <= m) {
              if (a[i1][j] == ch) ok = 1, ls[ch] = {i1, j};
              i1++;
            }
            if (!ok) ls[ch] = fs[ch];
            l = ch;
            aux = fs[ch];
          }
    for (int i = 1; i <= l; i++) {
      if (!fs[i].first) {
        fs[i] = aux;
        ls[i] = aux;
      }
      for (int i1 = fs[i].first; i1 <= ls[i].first; i1++)
        for (int j1 = fs[i].second; j1 <= ls[i].second; j1++) ans[i1][j1] = i;
    }
    int ok = 1;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (ans[i][j] != a[i][j]) ok = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) a[i][j] = ans[i][j] = 0;
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    cout << l << '\n';
    for (int i = 1; i <= l; i++)
      cout << fs[i].first << ' ' << fs[i].second << ' ' << ls[i].first << ' '
           << ls[i].second << '\n';
  }
  return 0;
}
