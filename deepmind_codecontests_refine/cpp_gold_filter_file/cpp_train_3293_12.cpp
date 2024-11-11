#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0, ans = 0;
  vector<pair<int, int> > v;
  map<int, int> mp;
  map<int, int> rev_mp;
  map<int, set<int> > freq_mp;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x = 0;
    cin >> x;
    if (!v.size())
      v.push_back(make_pair(x, 1));
    else if (v.back().first == x)
      v.back().second++;
    else
      v.push_back(make_pair(x, 1));
  }
  n = v.size();
  for (int i = 0, j = n - 1; j >= 0; i++, j--)
    mp[i] = v[i].second, rev_mp[j] = v[i].second,
    freq_mp[v[i].second].insert(i);
  while (!freq_mp.empty()) {
    ans++;
    map<int, set<int> >::reverse_iterator rt = freq_mp.rbegin();
    int fr = (*rt).first;
    int idx1 = *freq_mp[fr].begin();
    freq_mp[fr].erase(idx1);
    if (freq_mp[fr].empty()) freq_mp.erase(fr);
    int idx2 = n - idx1 - 1;
    mp.erase(idx1);
    rev_mp.erase(idx2);
    auto it1 = mp.upper_bound(idx1), it2 = rev_mp.upper_bound(idx2);
    if (it1 == mp.end() || it2 == rev_mp.end()) continue;
    int nidx1 = (*it1).first, nidx2 = n - (*it2).first - 1;
    if (v[nidx1].first != v[nidx2].first) continue;
    int f1 = (*it1).second, f2 = (*it2).second;
    int nf = f1 + f2;
    mp.erase(nidx1);
    mp.erase(nidx2);
    rev_mp.erase(n - nidx1 - 1);
    rev_mp.erase(n - nidx2 - 1);
    freq_mp[f1].erase(nidx1);
    freq_mp[f2].erase(nidx2);
    if (freq_mp[f1].empty()) freq_mp.erase(f1);
    if (freq_mp[f2].empty()) freq_mp.erase(f2);
    mp[idx1] = nf;
    rev_mp[n - idx1 - 1] = nf;
    freq_mp[nf].insert(idx1);
    v[idx1].first = v[nidx1].first;
  }
  cout << ans;
  return 0;
}
