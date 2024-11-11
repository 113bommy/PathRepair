#include <bits/stdc++.h>
using namespace std;
long n, ar1[200000], ar2[200000];
long q;
vector<pair<long, long> > ans;
void domove(long a, long b) {
  if (a == b) return;
  swap(ar2[a - 1], ar2[a]);
  ans.push_back(make_pair(a - 1, a));
  domove(a - 1, b);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> ar1[i];
  for (int i = 1; i <= n; i++) cin >> ar2[i];
  for (int i = 1; i <= n; i++) {
    q = i;
    while (ar1[q] != ar2[i]) ++q;
    domove(q, i);
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i].first << " " << ans[i].second << endl;
  cin.get();
  cin.get();
  return 0;
}
