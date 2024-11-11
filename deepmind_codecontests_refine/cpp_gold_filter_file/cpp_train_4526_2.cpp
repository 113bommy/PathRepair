#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10;
string s, t;
int vis[M];
int key[M];
int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  int n = s.size();
  int r = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (r && s[i] == '(')
      vis[i] = 1, r--;
    else if (s[i] == ')')
      r++, vis[i] = 1;
  }
  if (r) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i]) t.push_back(s[i]);
  }
  n = t.size();
  int l = 0, jin = 0;
  for (int i = 0; i < n; i++)
    if (t[i] == '(')
      l++;
    else
      jin++;
  if (jin > l) {
    puts("-1");
    return 0;
  }
  l = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (t[i] == '(')
      l++;
    else if (t[i] == '#') {
      if (cnt + 1 == jin)
        key[cnt++] = l, l = 0;
      else {
        if (l == 0) {
          puts("-1");
          return 0;
        } else
          key[cnt++] = 1, l--;
      }
    }
  }
  if (l) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i < cnt; i++) printf("%d\n", key[i]);
  return 0;
}
