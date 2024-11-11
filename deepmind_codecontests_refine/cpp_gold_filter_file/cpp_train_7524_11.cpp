#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int a[26] = {0}, l = s2.length(), b[26] = {0}, lw = 0, cnt = 0, ans = 0;
  for (int i = 0; i < s2.length(); i++) b[s2[i] - 'a']++;
  for (int i = 0; i < s1.length(); i++) {
    if (s1[i] - 'a' >= 0 && s1[i] - 'a' < 26)
      a[s1[i] - 'a']++;
    else
      cnt++;
    if (i - lw + 1 == l) {
      int req = 0;
      for (int j = 0; j < 26; j++)
        if (a[j] != b[j]) req += abs(a[j] - b[j]);
      if (req - cnt == 0) ans++;
      if (s1[lw] - 'a' >= 0 && s1[lw] - 'a' < 26)
        a[s1[lw] - 'a']--;
      else
        cnt--;
      lw++;
    }
  }
  cout << ans << endl;
  return 0;
}
