#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, j;
  cin >> t;
  while (t--) {
    int flag = 0;
    string s;
    cin >> s;
    char a[500] = {0};
    a[250] = s[0];
    map<char, int> m;
    m[s[0]] = 250;
    for (int i = 1; i < s.length(); i++) {
      if (m[s[i]] == 0) {
        if (a[m[s[i - 1]] - 1] == 0) {
          m[s[i]] = m[s[i - 1]] - 1;
          a[m[s[i]]] = s[i];
        } else if (a[m[s[i - 1]] + 1] == 0) {
          m[s[i]] = m[s[i - 1]] + 1;
          a[m[s[i]]] = s[i];
        } else {
          printf("NO\n");
          flag = 1;
          break;
        }
      } else {
        if (m[s[i]] == m[s[i - 1]] + 1)
          continue;
        else if (m[s[i]] == m[s[i - 1]] - 1)
          continue;
        else {
          printf("NO\n");
          flag = 1;
          break;
        }
      }
    }
    if (flag) continue;
    printf("YES\n");
    for (int i = 0; i < 500; i++) {
      if (a[i]) printf("%c", a[i]);
    }
    for (int i = 97; i <= 122; i++) {
      if (!m[i]) printf("%c", i);
    }
    printf("\n");
  }
  return 0;
}
