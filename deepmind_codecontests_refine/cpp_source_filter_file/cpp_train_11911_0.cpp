#include <bits/stdc++.h>
using namespace std;
vector<pair<long long int, long long int> > vp;
vector<pair<long long int, long long int> > ad;
int isap(long long int l, long long int r) {
  long long int d, i;
  if (l == r) return 1;
  d = vp[l + 1].second - vp[l].second;
  for (i = l; i < r - 1; i++) {
    if (d != vp[i + 1].second - vp[i].second) return 0;
  }
  return 1;
}
int main() {
  cout.sync_with_stdio(false);
  cin.sync_with_stdio(false);
  long long int i, n, j, size, l, r;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> j;
    vp.push_back(make_pair(j, i));
  }
  sort(vp.begin(), vp.end());
  l = 0;
  r = l;
  size = vp.size();
  long long int sum = 0;
  while (r < size && l < size) {
    while (r < size && vp[r].first == vp[l].first) r++;
    if (isap(l, r - 1)) {
      sum++;
      if (l != r - 1)
        ad.push_back(make_pair(vp[l].first, vp[l + 1].second - vp[l].second));
      else
        ad.push_back(make_pair(vp[l].first, 0));
    }
    l = r;
  }
  long long int s = ad.size();
  cout << sum << "\n";
  for (i = 0; i < s; i++) {
    cout << ad[i].first << "  " << ad[i].second << "\n";
  }
  return 0;
}
