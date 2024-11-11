#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string t = "aeiou";
  string a = "";
  for (int j = 0; j < 100000; j++) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'a' &&
          (s[i + 1] == 'a' || s[i + 1] == 'e' || s[i + 1] == 'i' ||
           s[i + 1] == 'i' && s[i + 1] == 'o' || s[i + 1] == 'u' ||
           s[i + 1] == 'y')) {
        s.erase(s.begin() + i + 1);
        continue;
      }
      if (s[i] == 'e' &&
          (s[i + 1] == 'a' || s[i + 1] == 'e' || s[i + 1] == 'i' ||
           s[i + 1] == 'i' && s[i + 1] == 'o' || s[i + 1] == 'u' ||
           s[i + 1] == 'y')) {
        s.erase(s.begin() + i + 1);
        continue;
      }
      if (s[i] == 'i' &&
          (s[i + 1] == 'a' || s[i + 1] == 'e' || s[i + 1] == 'i' ||
           s[i + 1] == 'i' && s[i + 1] == 'o' || s[i + 1] == 'u' ||
           s[i + 1] == 'y')) {
        s.erase(s.begin() + i + 1);
        continue;
      }
      if (s[i] == 'o' &&
          (s[i + 1] == 'a' || s[i + 1] == 'e' || s[i + 1] == 'i' ||
           s[i + 1] == 'i' || s[i + 1] == 'o' || s[i + 1] == 'u' ||
           s[i + 1] == 'y')) {
        s.erase(s.begin() + i + 1);
        continue;
      }
      if (s[i] == 'u' &&
          (s[i + 1] == 'a' || s[i + 1] == 'e' || s[i + 1] == 'i' ||
           s[i + 1] == 'i' || s[i + 1] == 'o' || s[i + 1] == 'u' ||
           s[i + 1] == 'y')) {
        s.erase(s.begin() + i + 1);
        continue;
      }
      if (s[i] == 'y' &&
          (s[i + 1] == 'a' || s[i + 1] == 'e' || s[i + 1] == 'i' ||
           s[i + 1] == 'i' || s[i + 1] == 'o' || s[i + 1] == 'u' ||
           s[i + 1] == 'y')) {
        s.erase(s.begin() + i + 1);
        continue;
      }
    }
  }
  cout << s << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
