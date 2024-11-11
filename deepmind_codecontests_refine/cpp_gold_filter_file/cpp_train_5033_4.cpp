#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> ad[1505];
bool chk[1505];
bool ch[1505];
int have[1505];
int ans[1505];
vector<pair<pair<int, int>, int> > xy;
double angle(pair<int, int> v1, pair<int, int> v2) {
  swap(v1.first, v1.second), swap(v2.first, v2.second);
  if (v1.second == v2.second) return 214000000000;
  double op = ((double)v2.first - v1.first) / (v2.second - v1.second);
  return op;
}
void dfs(int v) {
  have[v] = 1, chk[v] = true;
  for (int i = 0; i < ad[v].size(); i++) {
    if (!chk[ad[v][i]]) {
      dfs(ad[v][i]);
      have[v] += have[ad[v][i]];
    }
  }
}
void process(int v, vector<pair<pair<int, int>, int> > point) {
  sort(point.begin(), point.end());
  ans[point[0].second] = v;
  ch[v] = true;
  if (point.size() == 1) return;
  vector<pair<double, int> > p;
  for (int i = 1; i < point.size(); i++) {
    p.push_back(make_pair(angle(point[0].first, point[i].first), i));
  }
  sort(p.begin(), p.end());
  int st = 0;
  for (int i = 0; i < ad[v].size(); i++) {
    if (!ch[ad[v][i]]) {
      vector<pair<pair<int, int>, int> > pp;
      for (int j = 0; j < have[ad[v][i]]; j++)
        pp.push_back(point[p[st + j].second]);
      st += have[ad[v][i]];
      process(ad[v][i], pp);
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int in1, in2;
    scanf("%d %d", &in1, &in2);
    ad[in1].push_back(in2);
    ad[in2].push_back(in1);
  }
  for (int i = 0; i < n; i++) {
    int in1, in2;
    scanf("%d %d", &in1, &in2);
    xy.push_back(make_pair(make_pair(in2, in1), i + 1));
  }
  dfs(1);
  process(1, xy);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
