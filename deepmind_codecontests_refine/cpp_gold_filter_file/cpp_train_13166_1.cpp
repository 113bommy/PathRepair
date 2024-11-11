#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
const int m = 26;
long long x[m];
map<long long, long long> mp;
vector<long long> a[m];
string s;
int main() {
  ios::sync_with_stdio(false);
  for (int i = 0; i < m; i++) cin >> x[i];
  cin >> s;
  long long sum = 0;
  for (int i = 0; i < s.length(); i++) {
    int ch = s[i] - 'a';
    sum += x[ch];
    a[ch].push_back(sum);
  }
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    mp.clear();
    for (int j = 0; j < a[i].size(); j++) {
      ans += mp[a[i][j] - x[i]];
      mp[a[i][j]]++;
    }
  }
  cout << ans << "\n";
  return 0;
}
