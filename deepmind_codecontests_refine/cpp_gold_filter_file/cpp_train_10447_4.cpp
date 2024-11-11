#include <bits/stdc++.h>
using namespace std;
vector<int> v[26];
map<int, int> mpp;
unsigned char mp[1 << 26][3];
int state[1000005], cnt[26];
string input, s, t;
void pls(int x) {
  if (mp[x][1] == 255 && mp[x][0] == 255)
    mp[x][1] = 0, mp[x][0] = 0, ++mp[x][2];
  else if (mp[x][0] == 255)
    mp[x][0] = 0, ++mp[x][1];
  else
    ++mp[x][0];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> s >> q;
  for (int i = 0; i < s.size(); ++i) v[s[i] - 'a'].push_back(i);
  for (int i = 0; i < 26; ++i)
    if (v[i].size()) mpp[v[i][0]] = i;
  for (int i = 0; i < s.size(); ++i) {
    int x = 0;
    for (auto p = mpp.begin();
         p != mpp.end() && (!i || p->second != s[i - 1] - 'a'); ++p)
      x |= 1 << p->second, pls(x);
    int t = mpp.begin()->second;
    mpp.erase(mpp.begin()), ++cnt[t];
    if (cnt[t] < v[t].size()) mpp[v[t][cnt[t]]] = t;
  }
  while (q--) {
    int tmp = 0;
    cin >> t;
    for (char c : t) tmp |= 1 << (c - 'a');
    cout << ((mp[tmp][2] << 16) | (mp[tmp][1] << 8) | mp[tmp][0]) << "\n";
  }
}
