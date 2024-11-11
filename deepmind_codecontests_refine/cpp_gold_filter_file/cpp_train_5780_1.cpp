#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
pair<int, int> ans[N];
bool solve(int n, vector<pair<int, int> > &in, vector<pair<int, int> > &out) {
  int l = 1, r = n;
  int id1 = in.size() - 1, id2 = out.size() - 1;
  set<pair<int, int> > s;
  for (int i = 0; i < (n - 1); ++i) {
    if (i & 1) {
      ans[in[id1].second].first = l;
      ans[in[id1].second].second = l + 1;
      s.insert(pair<int, int>(l, l + 1));
      for (int j = l + 2; id2 >= 0 && out[id2].first >= in[id1].first && j <= r;
           --id2, ++j) {
        if (s.find(pair<int, int>(l, j)) != s.end()) continue;
        s.insert(pair<int, int>(l, j));
        ans[out[id2].second].first = l;
        ans[out[id2].second].second = j;
      }
      l++;
    } else {
      ans[in[id1].second].first = r;
      ans[in[id1].second].second = r - 1;
      s.insert(pair<int, int>(r - 1, r));
      for (int j = r - 2; id2 >= 0 && out[id2].first >= in[id1].first && j >= l;
           --id2, --j) {
        if (s.find(pair<int, int>(j, r)) != s.end()) continue;
        s.insert(pair<int, int>(j, r));
        ans[out[id2].second].first = r;
        ans[out[id2].second].second = j;
      }
      r--;
    }
    --id1;
  }
  if (id2 >= 0) return 0;
  return 1;
}
int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<pair<int, int> > in, out;
    for (int i = 0; i < (m); ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      if (y == 1)
        in.push_back(pair<int, int>(x, i));
      else
        out.push_back(pair<int, int>(x, i));
    }
    sort(in.begin(), in.end());
    sort(out.begin(), out.end());
    if (!solve(n, in, out))
      cout << -1 << endl;
    else {
      for (int i = 0; i < (m); ++i)
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
  }
  return 0;
}
