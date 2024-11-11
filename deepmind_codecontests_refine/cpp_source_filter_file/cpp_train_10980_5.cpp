#include <bits/stdc++.h>
using namespace std;
map<char, int> mapp;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, ans = 0;
  cin >> n;
  string s;
  cin >> s;
  char need;
  for (int i = 0; i < s.size(); i += 2) {
    mapp[s[i]]++;
    need = tolower(s[i + 1]);
    if (mapp[need] == 0) {
      ans++;
    } else {
      mapp[s[i]]--;
    }
  }
  cout << ans;
  return 0;
}
