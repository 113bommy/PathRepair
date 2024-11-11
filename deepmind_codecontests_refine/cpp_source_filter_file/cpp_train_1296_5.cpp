#include <bits/stdc++.h>
using namespace std;
const int N = 220;
const int M = 120;
int n;
pair<pair<int, int>, int> gp[N];
map<int, int> cnt;
vector<pair<int, int> > ans;
int cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  if (a.first.second != b.first.second) return a.first.second < b.first.second;
  return a.first.first < b.first.first;
}
int main() {
  cin >> n;
  for (int i = 0; i < (n); i++) {
    cin >> gp[i].first.first >> gp[i].first.second;
    gp[i].second = i;
  }
  sort(gp, gp + n, cmp);
  int x = gp[0].first.first;
  for (int i = 0; i < (n); i++) {
    x = max(x, gp[i].first.first);
    while (cnt.find(x) != cnt.end()) x++;
    cnt[x] = 1;
    ans.push_back(make_pair(gp[i].second, x));
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < (ans.size()); i++)
    if (ans.size() - 1 == i)
      cout << ans[i].second << endl;
    else
      cout << ans[i].second << " ";
}
