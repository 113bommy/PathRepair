#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, c = 0, i, j = 0;
  string s1, s2;
  cin >> s1 >> s2;
  n = s1.length();
  for (i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      c++;
    }
  }
  if (c & 1)
    cout << "impossible";
  else {
    for (i = 0; i < n; i++) {
      if (s1[i] != s2[i]) {
        if ((j + 1) * 2 <= c)
          cout << s1[i];
        else
          cout << s2[i];
        j++;
      } else
        cout << s1[i];
    }
  }
  return 0;
}
