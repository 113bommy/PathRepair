#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;
int n, m, ans;
double k;
string str[maxn];
map<string, int> mp;
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> str[i] >> tmp;
    tmp *= (k + 0.0000001);
    if (tmp >= 100) {
      mp[str[i]] = (int)tmp;
      ++ans;
    }
  }
  string st;
  for (int i = 0; i < m; ++i) {
    cin >> st;
    if (mp.find(st) == mp.end()) {
      mp[st] = 0;
      ++ans;
    }
  }
  cout << ans << endl;
  map<string, int>::iterator i;
  for (i = mp.begin(); i != mp.end(); ++i) {
    cout << i->first << " " << i->second << endl;
  }
  return 0;
}
