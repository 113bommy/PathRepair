#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  map<string, string> mp;
  while (n--) {
    string s1, s2;
    cin >> s1 >> s2;
    s2 += ";";
    mp[s2] = s1;
  }
  while (m--) {
    string s1, s2;
    cin >> s1 >> s2;
    cout << s1 << " " << s2 << " #" << mp[s2] << '\n';
  }
  return 0;
}
