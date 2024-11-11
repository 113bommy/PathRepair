#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 20;
set<pair<int, int> > ta[2][N];
set<pair<int, int> > ti;
set<int> ans;
int best;
pair<int, pair<int, int> > in[N], ero[N];
void solve(int n, int _time, bool sol) {
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (_time < in[i].first || cnt > in[i].second.first) continue;
    if (ta[sol][cnt].size()) {
      auto temp = ta[sol][cnt].end();
      temp--;
      int idx = temp->second;
      _time += temp->first;
      ans.erase(ans.find(idx));
      ta[sol][cnt].erase(temp);
      ti.erase(ti.find({ero[idx].first, ero[idx].second.second}));
      cnt--;
    }
    cnt++;
    best = max(best, cnt);
    _time -= in[i].first;
    ta[sol][in[i].second.first].insert({in[i].first, in[i].second.second});
    ti.insert({in[i].first, in[i].second.second});
    ans.insert(in[i].second.second);
    if (cnt == best && sol) {
      printf("%d\n%d\n", cnt, ans.size());
      for (auto it = ans.begin(); it != ans.end(); it++) printf("%d ", *it);
      exit(0);
    }
  }
}
int main() {
  int n, _time;
  scanf("%d%d", &n, &_time);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &in[i].second.first, &in[i].first), in[i].second.second = i;
    ero[i] = in[i];
  }
  sort(in + 1, in + n + 1);
  solve(n, _time, 0);
  ans.clear();
  ti.clear();
  solve(n, _time, 1);
  printf("0\n0");
}
