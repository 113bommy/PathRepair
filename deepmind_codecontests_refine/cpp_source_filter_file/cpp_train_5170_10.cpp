#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n;
int a[maxn];
string w, s[maxn];
char let;
char bound(char c1, char c2) {
  if ((c1 >= 'a' && c2 >= 'a') || ((c1 < 'a' && c2 < 'a'))) return c2;
  if (c2 >= 'a')
    return c2 - 'a' + 'A';
  else
    return c2 - 'A' + 'a';
}
char tolo(char c2) {
  if (c2 >= 'a')
    return c2;
  else
    return c2 - 'A' + 'a';
}
int mark[maxn];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i];
  cin >> w >> let;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j + s[i].size() - 1 < w.size(); j++) {
      bool T = 1;
      for (int ii = j; ii <= j + s[i].size() - 1; ii++)
        if (tolo(s[i][ii - j]) != tolo(w[ii])) {
          T = 0;
          break;
        }
      if (T)
        for (int ii = j; ii <= j + s[i].size() - 1; ii++) mark[ii] = 1;
    }
  for (int i = 0; i < w.size(); i++)
    if (mark[i] == 1) {
      if (tolo(w[i]) != tolo(let))
        w[i] = bound(w[i], let);
      else {
        if (tolo(w[i]) != 'a')
          w[i] = bound(w[i], 'a');
        else
          w[i] = bound(w[i], 'a');
      }
    }
  cout << w;
}
