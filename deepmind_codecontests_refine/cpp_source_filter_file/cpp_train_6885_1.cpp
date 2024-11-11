#include <bits/stdc++.h>
using namespace std;
int n, sz[1010], id[1010];
int cp(int x, int y) { return sz[x] < sz[y]; }
set<int> s;
vector<pair<int, int> > rr;
int ck(int x, int l, int r) {
  auto it = s.begin();
  cout << r - l + 1 << '\n';
  for (int i = 1; i < l; i++) it++;
  for (int i = l; i <= r; i++) {
    printf("%d ", *it);
    it++;
  }
  printf("\n1\n1\n%d\n", x);
  fflush(stdout);
  int y;
  cin >> y;
  return y;
}
int main() {
  cin >> n;
  sz[1] = n;
  id[1] = 1;
  for (int i = 2; i <= n; i++) {
    cout << n - 1 << '\n';
    for (int i = 2; i <= n; i++) printf("%d ", i);
    printf("\n1\n1\n%d\n", i);
    fflush(stdout);
    cin >> sz[i];
    id[i] = i;
  }
  sort(id + 1, id + n + 1, cp);
  for (int i = n; i; i--) {
    if (!s.empty())
      while (!s.empty() && ck(id[i], 1, s.size())) {
        int l = 1, r = s.size();
        while (l <= r) {
          int md = (l + r) / 2;
          if (ck(id[i], l, md))
            r = md - 1;
          else
            l = md + 1;
        }
        auto it = s.begin();
        for (int j = 1; j < l; j++) it++;
        rr.push_back(make_pair(id[i], *it));
        s.erase(*it);
      }
    s.insert(id[i]);
  }
  puts("ANSWER");
  for (auto i : rr) cout << i.first << ' ' << i.second << '\n';
  fflush(stdout);
}
