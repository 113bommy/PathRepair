#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
map<char, int> mp, curmp;
vector<pair<int, char> > v, resvec;
int main() {
  int n;
  string s;
  cin >> s >> n;
  for (auto x : s) mp[x]++;
  if (n < mp.size()) return cout << -1, 0;
  string ress;
  int res = -1;
  if (n >= s.size()) {
    ress = s;
    for (int i = s.size(); i < n; i++) ress += 'a';
    res = 1;
  } else {
    int lo = 1, hi = 1e9;
    int tempn = n;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      for (auto x : mp)
        v.push_back({(int)ceil(1.0 * x.second / mid), x.first}),
            tempn -= (int)ceil(1.0 * x.second / mid);
      if (tempn >= 0) {
        res = mid;
        hi = mid - 1;
        resvec = v;
      } else
        lo = mid + 1;
      tempn = n;
      v.clear();
    }
    for (auto x : resvec)
      for (int j = 0; j < x.first; j++) ress += x.second;
    int rem = res - ress.size();
    for (int i = 0; i < rem; i++) ress += 'a';
  }
  cout << res << endl << ress;
  return 0;
}
