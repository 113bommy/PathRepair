#include <bits/stdc++.h>
using namespace std;
bool double_comp(double a, double b) { return (abs(a - b) <= 1e-10); }
bool comp(pair<char, int> a, pair<char, int> b) { return a.second < b.second; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 3;
  map<char, int> mp;
  while (t--) {
    char a, b, c;
    cin >> a >> b >> c;
    if (b == '>')
      mp[a]++, mp[c]--;
    else
      mp[c]++, mp[a]--;
  }
  auto itr = mp.begin();
  auto itr1 = ++itr;
  --itr;
  auto itr2 = ++itr1;
  --itr1;
  if (itr->second == itr1->second || itr->second == itr2->second ||
      itr1->second == itr2->second)
    cout << "impossible";
  else {
    map<int, char> rev;
    auto iter = mp.begin();
    while (iter != mp.end()) {
      rev[iter->second] = iter->first;
      iter++;
    }
    for (auto i : rev) cout << i.second;
  }
}
