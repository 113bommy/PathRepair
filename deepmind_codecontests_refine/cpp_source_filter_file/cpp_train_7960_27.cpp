#include <bits/stdc++.h>
using namespace std;
inline int D() {
  int t;
  scanf("%d", &t);
  return t;
}
inline long long LLD() {
  long long t;
  scanf("%lld", &t);
  return t;
}
int main() {
  map<char, string> mp;
  mp['0'] = mp['1'] = "";
  mp['2'] = "2";
  mp['3'] = "3";
  mp['4'] = "223";
  mp['5'] = "5";
  mp[6] = "35";
  mp['7'] = "7";
  mp['8'] = "2227";
  mp['9'] = "2337";
  int n;
  cin >> n;
  string a;
  cin >> a;
  string ans = "";
  for (int i = 0; a[i]; i++) {
    ans += mp[a[i]];
  }
  sort(ans.rbegin(), ans.rend());
  cout << ans;
}
