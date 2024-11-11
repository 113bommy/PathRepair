#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  string a[n + 1];
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long len = a[0].size();
  string res = "";
  for (long long i = 0; i < len; i++) {
    map<char, long long> mp;
    for (long long j = 0; j < n; j++) {
      mp[a[j][i]]++;
    }
    long long ans = 0, ans1 = 0;
    char vis[200] = {0}, ch;
    for (auto x : mp) {
      if (x.first == '?')
        ans++;
      else {
        if (vis[x.first] == 0) {
          ans1++;
          vis[x.first] = 1;
          ch = x.first;
        }
      }
    }
    if (ans1 == 0) {
      res += 'a';
    } else if (ans1 == 1) {
      res += ch;
    } else
      res += '?';
  }
  cout << res << endl;
}
