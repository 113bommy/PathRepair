#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
set<int> S[N];
pair<int, int> sz[N];
int req[N];
vector<pair<pair<int, int>, int> > ANS;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    int s;
    cin >> s;
    tot += s;
    sz[i] = make_pair(s, i);
    while (s--) {
      int p;
      cin >> p;
      S[i].insert(p);
    }
  }
  sort(sz + 1, sz + n + 1);
  for (int i = 1; i <= n; i++) {
    req[i] = tot / n;
    if (n - i + 1 <= tot % n) req[i]++;
  }
  int lo = 1, hi = n;
  while (1) {
    while (lo < hi and req[lo] == sz[lo].first) lo++;
    while (lo < hi and req[hi] == sz[hi].first) hi--;
    if (lo >= hi) break;
    int la = sz[lo].second, ra = sz[hi].second;
    int last = 0;
    auto it = S[la].begin();
    vector<int> toAdd;
    while (sz[lo].first < req[lo] and sz[hi].first > req[hi]) {
      while (sz[lo].first < req[lo] and sz[hi].first > req[hi] and
             (it == S[la].end() or *S[ra].upper_bound(last) < *it)) {
        ANS.push_back(make_pair(make_pair(ra, la), *S[ra].upper_bound(last)));
        sz[lo].first++;
        sz[hi].first--;
        S[ra].erase(S[ra].upper_bound(last));
        toAdd.push_back(ANS.back().second);
      }
      if (it != S[la].end()) last = *(it++);
    }
    for (auto it : toAdd) {
      S[la].insert(it);
    }
  }
  cout << ANS.size() << "\n";
  for (auto it : ANS) {
    cout << it.first.first << " " << it.first.second << " " << it.second
         << "\n";
  }
  return 0;
}
