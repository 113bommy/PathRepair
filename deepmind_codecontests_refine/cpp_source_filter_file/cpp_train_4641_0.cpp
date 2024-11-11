#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int maxbid[N], del[N];
vector<int> llist[N];
set<pair<int, int> > s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int k, b;
    cin >> k >> b;
    llist[k].push_back(b);
    maxbid[k] = max(maxbid[k], b);
  }
  for (int i = 1; i <= n; i++)
    if (maxbid[i]) s.insert(make_pair(maxbid[i], i));
  int q;
  cin >> q;
  for (int j = 1; j <= q; j++) {
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++) {
      cin >> del[i];
      if (maxbid[del[i]]) s.erase(pair<int, int>(maxbid[del[i]], del[i]));
    }
    int sz = s.size();
    if (sz == 0)
      cout << "0 0\n";
    else if (sz == 1) {
      cout << s.begin()->second << ' ' << *llist[s.begin()->second].begin()
           << endl;
    } else {
      auto it1 = s.end(), it2 = s.end();
      it1--;
      it2--;
      it2--;
      int x = it2->first;
      int index = it1->second;
      auto it = upper_bound(llist[index].begin(), llist[index].end(), x);
      cout << index << *it << endl;
    }
    for (int i = 1; i <= k; i++) {
      if (maxbid[del[i]]) s.insert(make_pair(maxbid[del[i]], del[i]));
    }
  }
  return 0;
}
