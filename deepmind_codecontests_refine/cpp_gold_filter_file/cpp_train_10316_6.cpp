#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int main() {
  int n, ans = 0;
  cin >> n >> s1 >> s2;
  for (int i = 0; i < n / 2; i++) {
    map<char, int> s;
    s[s1[i]]++, s[s1[n - i - 1]]++, s[s2[i]]++, s[s2[n - 1 - i]]++;
    if (s.size() == 4)
      ans += 2;
    else if (s.size() == 3) {
      if (s1[i] == s1[n - i - 1])
        ans += 2;
      else
        ans++;
    } else if (s.size() == 2) {
      if (s[s1[i]] != 2) ans++;
    }
  }
  if (n % 2 && s1[n / 2] != s2[n / 2]) ans++;
  cout << ans << endl;
}
