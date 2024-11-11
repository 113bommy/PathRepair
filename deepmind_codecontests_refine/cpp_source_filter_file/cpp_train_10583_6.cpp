#include <bits/stdc++.h>
using namespace std;
int n;
string s, a[10000], that, anss;
char let;
int pi[100000], ans[100000], kol;
char lower(char c) {
  if ((int)c < 97)
    return c + 32;
  else
    return c;
}
char upper(char c) {
  if ((int)c >= 90) return c - 32;
  return c;
}
void prefix(string s, string t) {
  int n = (int)s.length();
  kol = 0;
  for (int i = 0; i <= 199; i++) pi[i] = 0, ans[i] = 0;
  for (int i = 1; i < n; ++i) {
    int j = pi[i - 1];
    while (j > 0 && lower(s[i]) != lower(s[j])) j = pi[j - 1];
    if (lower(s[i]) == lower(s[j])) ++j;
    pi[i] = j;
    if (pi[i] == (int)t.length()) ans[++kol] = i - 2 * t.length();
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cin >> that;
  cin >> let;
  anss = that;
  for (int i = 1; i <= n; i++) {
    string tmp = a[i] + '#' + that;
    prefix(tmp, a[i]);
    for (int j = 1; j <= kol; j++)
      for (int k = ans[j]; k < ans[j] + a[i].length(); k++)
        if (lower(that[k]) == lower(let) && lower(let) != 'a')
          anss[k] = 'a';
        else if (lower(that[k]) == lower(let) && lower(let) == 'a')
          anss[k] = 'b';
        else
          anss[k] = let;
  }
  for (int i = 0; i < that.length(); i++)
    if ((int)that[i] < 97)
      anss[i] = upper(anss[i]);
    else
      anss[i] = lower(anss[i]);
  cout << anss;
}
