#include <bits/stdc++.h>
using namespace std;
const int o = 5e3 + 1;
char s[o], c[o];
int a[31], b[31];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s >> c;
  int n = strlen(s), m = strlen(c);
  for (int i = 0; i < n; i++) a[s[i] - 'a']++;
  for (int i = 0; i < m; i++) b[c[i] - 'a']++;
  int q = 0, w = 1, r;
  for (int i = 0; i < 26; i++)
    if (a[i] < b[i])
      w = 0;
    else if (a[i] > b[i])
      q++;
  if (q && w) {
    r = m;
    for (int i = 0; i < 26; i++)
      for (int j = 0; j < a[i] - b[i]; j++) b[r++] = i + 'a';
    b[r] = '\0';
    cout << b;
    return 0;
  }
  for (int i = m - 1; i >= 0; i--) {
    q = 1;
    b[c[i] - 'a']--;
    for (int j = 0; j < 26; j++)
      if (a[j] < b[j]) q = 0;
    if (!q) continue;
    for (int j = 0; j < 26; j++)
      if (j > c[i] - 'a' && a[j] > b[j]) {
        a[j]--, c[i] = 'a' + j, r = i + 1;
        for (int k = 0; k < 26; k++)
          for (int l = 0; l < a[k] - b[k]; l++) c[r++] = 'a' + k;
        c[r] = 0;
        cout << c;
        return 0;
      }
  }
  cout << -1;
  return 0;
}
