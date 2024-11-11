#include <bits/stdc++.h>
using namespace std;
bool check(string s) {
  int f[27];
  memset(f, 0, sizeof f);
  int maxf = 0;
  for (int i = 0; i < s.size(); i++) {
    f[s[i] - 'a']++;
    maxf = max(maxf, f[s[i] - 'a']);
  }
  if (maxf <= s.size() / 2)
    return true;
  else
    return false;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    for (int j = i + 1; j < s.size() + 1; j++) {
      bool ok = check(s.substr(i, j - i));
      if (ok) cout << "YES " << endl << s.substr(i, j - i) << endl, exit(0);
    }
  }
  cout << "NO" << endl;
}
