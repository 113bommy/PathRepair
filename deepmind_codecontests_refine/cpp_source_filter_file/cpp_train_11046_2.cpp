#include <bits/stdc++.h>
using namespace std;
int n;
long long int ans = 0;
int c['z' - 'a' + 1];
string p[100005];
map<int, int> mp;
int get_bitmask(string s) {
  for (int i = 0; i <= 'z' - 'a' + 1; i++) c[i] = 0;
  for (int i = 0; i < s.size(); i++) {
    c[s[i] - 'a']++;
    c[s[i] - 'a'] %= 2;
  }
  int bmsk = 0;
  for (int i = 0; i <= 'z' - 'a' + 1; i++) {
    bmsk *= 2;
    bmsk += c[i];
  }
  return bmsk;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    int b = get_bitmask(p[i]);
    mp[b]++;
  }
  for (int i = 0; i < n; i++) {
    int b = get_bitmask(p[i]);
    for (int i = 0; i < 26; i++) {
      int tb = b ^ (1 << i);
      if (mp.find(tb) != mp.end()) {
        ans += mp[tb];
      }
    }
    ans += mp[b] - 1;
  }
  cout << ans / 2;
  return 0;
}
