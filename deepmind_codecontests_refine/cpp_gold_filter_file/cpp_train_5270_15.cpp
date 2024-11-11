#include <bits/stdc++.h>
using namespace std;
bool isvowel(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
    return true;
  } else {
    return false;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string str;
  cin >> str;
  int n = str.size();
  set<char> s;
  map<char, int> mp;
  int c = 0;
  int d = 0, sz = 0;
  int tsz[n];
  char l;
  for (int i = 0; i < n; i++) {
    mp.clear();
    c = 0;
    for (int j = i; j < n; j++) {
      if (!isvowel(str[j])) {
        c++;
        mp[str[j]]++;
      } else {
        c = 0;
        mp.clear();
      }
      if (c >= 3 && mp.size() >= 2) {
        tsz[i] = j - i - 1;
        break;
      }
      if (j == n - 1 && i != n - 1) {
        tsz[i] = j - i;
      } else if (j == n - 1 && i == n - 1) {
        tsz[i] = 1;
      }
    }
  }
  string ans;
  for (int i = 0; i < n; i++) {
    ans += str.substr(i, tsz[i] + 1);
    i = (i + tsz[i]);
    if (i < n - 1) {
      ans += " ";
    }
  }
  cout << ans << endl;
  return 0;
}
