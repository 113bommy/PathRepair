#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  int ans = 0;
  int s[28][28];
  int i, j, n;
  cin >> n >> a >> b;
  for (int i = 0; i < n; ++i) ans += (a[i] != b[i]);
  memset(s, 0, sizeof(s));
  for (int i = 0; i < n; ++i)
    if (a[i] != b[i]) s[a[i] - 'a'][b[i] - 'a'] = i + 1;
  for (int i = 0; i < n; ++i)
    if (a[i] != b[i] && s[b[i] - 'a'][a[i] - 'a']) {
      cout << ans - 2 << endl
           << i + 1 << " " << s[b[i] - 'a'][a[i] - 'a'] << endl;
      return 0;
    }
  for (i = 0; i < n; ++i)
    if (a[i] != b[i])
      for (j = 0; j < 26; ++j)
        if (s[j][a[i] - 'a']) {
          cout << ans - 1 << endl << i + 1 << " " << s[j][a[i] - 'a'] << endl;
          return 0;
        }
  cout << ans << endl << "-1 -1\n";
  return 0;
}
