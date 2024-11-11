#include <bits/stdc++.h>
using namespace std;
vector<int> vec[5010];
void solve(int l, int r, vector<pair<int, int> >& cur) {
  if (l == r) {
    for (int i = 0; i < (int)vec[l].size(); i++)
      cur.push_back(make_pair(vec[l][i], l));
    return;
  }
  int mid = (l + r) >> 1;
  vector<pair<int, int> > lef, rig;
  solve(l, mid, lef);
  solve(mid + 1, r, rig);
  int p1 = 0, p2 = 0;
  while (p1 < (int)lef.size() || p2 < (int)rig.size()) {
    if (p1 == (int)lef.size()) {
      cur.insert(cur.end(), rig.begin() + p2, rig.end());
      break;
    } else if (p2 == (int)rig.size()) {
      cur.insert(cur.end(), lef.begin() + p1, lef.end());
      break;
    } else {
      int liml = p1 + 1, limr = p2 + 1;
      for (; liml < (int)lef.size() && lef[liml] >= lef[liml - 1]; liml++)
        ;
      for (; limr < (int)rig.size() && rig[limr] >= rig[limr - 1]; limr++)
        ;
      while (p1 < liml && p2 < limr) {
        if (lef[p1].first < rig[p2].first)
          cur.push_back(lef[p1]), p1++;
        else
          cur.push_back(rig[p2]), p2++;
      }
      if (p1 < liml)
        cur.insert(cur.end(), lef.begin() + p1, lef.begin() + liml), p1 = liml;
      if (p2 < limr)
        cur.insert(cur.end(), rig.begin() + p2, rig.begin() + limr), p2 = limr;
    }
  }
}
int main() {
  int N;
  scanf("%d", &N);
  int sigmak = 0;
  for (int i = 1; i <= N; i++) {
    int k, a, x, y, m;
    scanf("%d%d%d%d%d", &k, &a, &x, &y, &m);
    vec[i].push_back(a);
    for (int j = 2; j <= k; j++)
      vec[i].push_back(a = ((long long)a * x + y) % m);
    sigmak += k;
  }
  int ans1 = 0;
  for (int i = 1; i <= N; i++) {
    int cur = 0;
    for (int j = 1; j < (int)vec[i].size(); j++)
      cur += vec[i][j] < vec[i][j - 1];
    ans1 = max(ans1, cur);
  }
  printf("%d\n", ans1);
  if (sigmak <= 200000) {
    vector<pair<int, int> > ans2;
    solve(1, N, ans2);
    for (int i = 0; i < (int)ans2.size(); i++)
      printf("%d %d\n", ans2[i].first, ans2[i].second);
  }
}
