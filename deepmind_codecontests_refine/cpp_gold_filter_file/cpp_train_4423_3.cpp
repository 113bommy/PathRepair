#include <bits/stdc++.h>
using namespace std;
set<int> have[1005];
set<int>::iterator it, ti;
int N, M;
vector<pair<int, int> > p, ans;
void Delete(int x, int y) {
  int i, j;
  int fr, to;
  if (x > y) swap(x, y);
  ans.push_back(make_pair(x, y));
  it = have[x].find(y);
  if (it == have[x].begin())
    fr = *have[x].rbegin();
  else
    ti = it, fr = *--ti;
  ++it;
  if (it != have[x].end())
    to = *it;
  else
    to = *have[x].begin();
  have[x].erase(y), have[y].erase(x);
  have[fr].insert(to), have[to].insert(fr);
}
void Work(vector<pair<int, int> > p) {
  int i, j, x, tmp;
  int fr, to;
  if (p.size() == 0) return;
  x = rand() % p.size();
  fr = p[x].first, to = p[x].second;
  for (i = (fr == 1 ? N : fr - 1); i != to; i = (i == 1 ? N : i - 1))
    while (true) {
      it = have[i].lower_bound(fr + 1);
      if (it == have[i].end() || *it >= to) break;
      Delete(i, *it);
    }
  vector<pair<int, int> > lt, rt;
  lt.resize(0), rt.resize(0);
  for (i = 0; i < p.size(); i++)
    if (i != x) {
      if (p[i].first >= fr && p[i].first <= to && p[i].second >= fr &&
          p[i].second <= to)
        lt.push_back(p[i]);
      else
        rt.push_back(p[i]);
    }
  p.resize(0);
  Work(lt), Work(rt);
}
int main() {
  int i, j;
  int fr, to;
  srand(1000);
  scanf("%d", &N);
  for (i = 1; i <= N - 3; i++) {
    scanf("%d %d", &fr, &to);
    have[fr].insert(to);
    have[to].insert(fr);
  }
  for (i = 1; i <= N; i++) have[i].insert((i == N ? 1 : i + 1));
  for (i = 1; i <= N; i++) have[i].insert((i == 1 ? N : i - 1));
  for (i = 1; i <= N - 3; i++) {
    scanf("%d %d", &fr, &to);
    if (fr > to) swap(fr, to);
    p.push_back(make_pair(fr, to));
  }
  Work(p);
  printf("%d\n", ans.size());
  for (i = 0; i < ans.size(); i++)
    printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
