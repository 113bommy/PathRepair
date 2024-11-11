#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > g[100010];
int n, m, dist[100010];
vector<pair<int, int> > ans1[100010];
int count1 = 0;
vector<pair<int, pair<int, int> > > v[100010], res[100010];
int vis[100010];
void dikstraw(int ind1, int ind2) {
  for (int i = 0; i < n + 1; i++) {
    dist[i] = 1000000007;
  }
  dist[ind1] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      p;
  p.push(make_pair(0, ind1));
  ans1[1].push_back(make_pair(0, 0));
  while (!p.empty()) {
    pair<int, int> it = p.top();
    p.pop();
    int ind = it.second;
    for (int i = 0; i < g[ind].size(); i++) {
      if (dist[g[ind][i].first] >= dist[ind] + 1) {
        if (dist[g[ind][i].first] > dist[ind] + 1)
          ans1[g[ind][i].first].clear();
        if ((ans1[g[ind][i].first].size() != 0) &&
            (ans1[g[ind][i].first][0].second >
             ans1[ind][0].second + (g[ind][i].second ^ 1)))
          ans1[g[ind][i].first].clear();
        ans1[g[ind][i].first].push_back(
            make_pair(ind, ans1[ind][0].second + g[ind][i].second ^ 1));
        dist[g[ind][i].first] = dist[ind] + 1;
        p.push(make_pair(dist[g[ind][i].first], g[ind][i].first));
      }
    }
  }
  queue<int> q;
  q.push(ind2);
  int ind22 = ind2;
  set<pair<int, int> > s;
  while (!q.empty()) {
    int num = q.front();
    q.pop();
    if (num != 1) q.push(ans1[num][0].first);
    s.insert(make_pair(ind22, num));
    s.insert(make_pair(num, ind22));
    ind22 = num;
  }
  for (int i = 0; i < m; i++) {
    int num1 = v[i][0].first;
    int num2 = v[i][0].second.first;
    set<pair<int, int> >::iterator it;
    it = s.find(make_pair(num1, num2));
    if (it == s.end()) {
      if (v[i][0].second.second == 1) {
        res[count1].push_back(
            make_pair(num1, make_pair(num2, v[i][0].second.second ^ 1)));
        count1++;
      }
    } else {
      if (v[i][0].second.second == 0) {
        res[count1].push_back(
            make_pair(num1, make_pair(num2, v[i][0].second.second ^ 1)));
        count1++;
      }
    }
  }
}
int main() {
  count1 = 0;
  scanf("%d", &n);
  scanf("%d", &m);
  int source = 1, dest = n;
  for (int i = 0; i < m; i++) {
    int x, y, z;
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);
    g[x].push_back(make_pair(y, z));
    g[y].push_back(make_pair(x, z));
    v[i].push_back(make_pair(x, make_pair(y, z)));
  }
  dikstraw(source, dest);
  printf("%d\n", count1);
  for (int i = 0; i < count1; i++)
    printf("%d %d %d\n", res[i][0].first, res[i][0].second.first,
           res[i][0].second.second);
  return 0;
}
