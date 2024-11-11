#include <bits/stdc++.h>
using namespace std;
string s;
int n, k, cnt, c;
vector<pair<int, int>> p;
vector<int> l, r;
pair<int, int> ans[1000001];
int main() {
  scanf("%d%d", &n, &k);
  for (int l, r, i = 0; i < n; i++) {
    scanf("%d%d", &l, &r);
    p.push_back({l, 0});
    p.push_back({r, 1});
  }
  sort(p.begin(), p.end());
  for (int i = 0; i < 2 * n; i++) {
    if (p[i].second == 0) {
      cnt++;
      if (cnt == k) {
        l.push_back(p[i].first);
      }
    } else {
      if (cnt == k) {
        r.push_back(p[i].first);
      }
      cnt--;
      c++;
    }
  }
  int d = l.size();
  cout << d << "\n";
  for (int i = 0; i < d; i++) {
    printf("%d %d\n", l[i], r[i]);
  }
  return 0;
}
