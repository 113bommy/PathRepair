#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<long long, int> st;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    int c[26];
    for (int j = 0; j < 26; j++) c[j] = 0;
    for (int j = 0; j < str.length(); j++) c[str[j] - 'a']++;
    long long btv = 0;
    for (int j = 0; j < 26; j++) {
      btv *= 2;
      btv += c[j] % 2;
    }
    ans += st[btv];
    for (int j = 0; j < 26; j++) ans += st[btv ^ (1ll << j)];
    st[btv]++;
  }
  cout << ans;
  return 0;
}
