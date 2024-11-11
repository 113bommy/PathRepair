#include <bits/stdc++.h>
using namespace std;
int r[26][26];
int n;
string names[200];
int vis[26];
bool solve() {
  memset(r, 0, sizeof(r));
  for (int i = 0; i < 26; i++) r[i][i] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      bool good = false;
      for (int k = 0;
           k < ((int)(names[i].size())) && k < ((int)(names[j].size())); k++) {
        if (names[i][k] != names[j][k]) {
          good = true;
          r[names[i][k] - 'a'][names[j][k] - 'a'] = 1;
          break;
        }
      }
      if (!good && ((int)(names[j].size())) < ((int)(names[i].size())))
        return false;
    }
  }
  for (int k = 0; k < 26; k++) {
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        r[i][j] |= (r[i][k] && r[k][j]);
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = i + 1; j < 26; j++) {
      if (r[i][j] && r[j][i]) return false;
    }
  }
  memset(vis, 0, sizeof(vis));
  for (int k = 0; k < 26; k++) {
    for (int i = 0; i < 26; i++) {
      if (!vis[i]) {
        for (int j = 0; j < 26; j++) {
          if (!vis[j] && j != i && r[j][i] == 1) goto tryanother;
        }
        cout << (char)('a' + i);
        vis[i] = 1;
        goto nextchar;
      }
    tryanother:;
    }
  nextchar:;
  }
  cout << "\n";
  return true;
}
int main() {
  while (cin >> n) {
    for (int i = 0; i < n; i++) cin >> names[i];
    if (!solve()) {
      cout << "Impossible\n";
    }
  }
  return 0;
}
