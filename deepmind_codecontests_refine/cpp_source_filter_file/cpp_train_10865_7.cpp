#include <bits/stdc++.h>
using namespace std;
long long a[5000], inf = 9e18;
vector<set<long long> > ind(1000005);
set<long long>::iterator ii;
set<long long> t;
vector<long long> uniq;
int main() {
  long long n, m, i, j;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    ind[a[i]].insert(i);
  }
  long long ans = 0;
  for (i = 1; i <= 1000000; i++) {
    ind[i].insert(inf);
    if (ind[i].size() > 1) {
      t.insert(i);
      ans = max(ans, (long long)ind[i].size() - 1);
    }
  }
  for (ii = t.begin(); ii != t.end(); ii++) uniq.push_back((*ii));
  for (i = 0; i < uniq.size(); i++) {
    for (j = 0; j < uniq.size(); j++) {
      long long one = uniq[i], two = uniq[j];
      if (two > one) {
        long long cur = 0, lastpos = 0;
        while (true) {
          if (cur % 2 == 1)
            ii = ind[two].upper_bound(lastpos);
          else
            ii = ind[one].upper_bound(lastpos);
          if ((*ii) == inf) break;
          cur++;
          lastpos = (*ii);
        }
        ans = max(ans, cur);
      }
    }
  }
  cout << ans;
  return 0;
}
