#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
int n, c[maxn], topo[maxn], p[maxn][maxn], t;
bool dfs(int u) {
  c[u] = -1;
  for (int i = 0; i < 26; i++) {
    if (p[u][i]) {
      if (c[i] < 0)
        return false;
      else if (!c[i])
        if (!dfs(i)) return false;
    }
  }
  c[u] = 1;
  topo[t--] = u;
  return true;
}
bool toposort() {
  memset(c, 0, sizeof(c));
  for (int i = 0; i < 26; i++) {
    if (!c[i])
      if (!dfs(i)) return false;
  }
  return true;
}
int main() {
  char s[110], s1[110];
  cin >> n;
  cin >> s;
  t = 25;
  bool flag;
  if (n == 1) {
    char ch = 'a';
    while (t--) cout << ch++;
    return 0;
  }
  for (int i = 1; i < n; i++) {
    cin >> s1;
    flag = false;
    int len = min(strlen(s), strlen(s1));
    for (int i = 0; i < len; i++) {
      if (s[i] != s1[i]) {
        p[s[i] - 'a'][s1[i] - 'a'] = 1;
        flag = true;
        break;
      }
    }
    if (!flag && strlen(s) > strlen(s1)) {
      flag = false;
      break;
    } else
      flag = true;
    strcpy(s, s1);
  }
  if (!flag || !toposort())
    cout << "Impossible" << endl;
  else {
    for (int i = 0; i < 26; i++) {
      char ch = topo[i] + 'a';
      cout << ch;
    }
  }
  return 0;
}
