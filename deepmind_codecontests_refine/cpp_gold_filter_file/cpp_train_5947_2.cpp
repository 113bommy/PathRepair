#include <bits/stdc++.h>
using namespace std;
int cnt[123];
int main() {
  string s;
  int len, i, j, cp, z;
  cin >> len;
  cin >> s;
  bool ok = true, ok2 = true;
  for (i = 0; i < len && ok2 == true; i++) {
    for (j = 97; j <= 122; j++) {
      cnt[j] = 0;
    }
    for (j = 2; j <= len - i && ok2 == true; j++) {
      ok = true;
      for (z = i; z < i + j && ok == true; z++) {
        cnt[s[z]]++;
        if (cnt[int(s[z])] > j - 1) ok = false;
      }
      cp = z - 1;
      if (ok) {
        cout << "YES" << endl;
        for (z = i; z <= cp; z++) cout << s[z];
        ok2 = false;
      }
    }
  }
  if (ok2 == true) cout << "NO";
}
