#include <bits/stdc++.h>
using namespace std;
const long long magic_number = 37, magic_number2 = 7777747447474LL;
long long mod = 4398042316799LL;
int i, j, ans;
string s;
vector<string> a;
map<long long, long long> mp;
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie();
  while (getline(cin, s)) {
    int n = s.size();
    string st = "";
    ans++;
    for (i = 0; i < n; i++) {
      if (s[i] >= 'a' && s[i] <= 'z')
        st += s[i];
      else {
        if (st != "") a.push_back(st);
        st = "";
        ans++;
      }
    }
    if (st != "") a.push_back(st);
  }
  for (i = 0; i < a.size(); i++) {
    long long H1 = 0, H = 0;
    map<long long, long long> mp2;
    for (j = 0; j < a[i].size(); j++) {
      H1 = (H1 * magic_number + int(a[i][j] - 'a')) % mod;
      mp2[H1] = j;
    }
    long long res = int(a[i].size());
    for (j = 0; j < a[i].size(); j++) {
      H = (H * magic_number + int(a[i][j] - 'a')) % mod;
      if (!mp.count(H)) {
        mp[H] = H1;
        continue;
      }
      if (mp2.count(mp[H])) {
        res = min(res, int(a[i].size()) - mp2[mp[H]] + j + 1);
      }
      if (mp[H] != H1) {
        mp[H] = magic_number2;
      }
    }
    ans += res;
  }
  cout << ans;
  return 0;
}
