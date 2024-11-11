#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int n, m;
int a[300000];
int b[300000];
vector<int> edge[300000];
int ngood;
int child[300000];
int good[300000];
int d[300000];
int ans;
void back(int now, int parent) {
  child[now] = 1;
  good[now] = b[now];
  for (auto e : edge[now])
    if (e != parent) {
      back(e, now);
      child[now] += child[e], good[now] += good[e];
    }
}
vector<pair<int, int> > v;
void back2(int now, int parent) {
  for (auto e : edge[now])
    if (e != parent) {
      back2(e, now);
    }
  if (b[now] == 0) {
    d[now] = 0;
    return;
  }
  d[now] = 1;
  int xgood = 0;
  for (auto e : edge[now])
    if (e != parent) {
      if (child[e] == good[e]) xgood += child[e];
    }
  for (auto e : edge[now])
    if (e != parent) {
      d[now] =
          max(d[now], 1 + d[e] + xgood - (child[e] == good[e] ? child[e] : 0));
    }
  ans = max(ans, d[now]);
  int u = 1 + (n - child[now] == ngood - good[now] ? n - child[now] : 0);
  v.clear();
  for (auto e : edge[now])
    if (e != parent) {
      v.emplace_back(d[e], e);
    }
  sort((v).begin(), (v).end(), greater<pair<int, int> >());
  for (int i = 0; i < 4 && i < v.size(); i++) {
    for (int j = i + 1; j < 4 && j < v.size(); j++) {
      ans = max(
          ans, u + v[i].first + v[j].first + xgood -
                   (child[v[i].second] == good[v[i].second] ? child[v[i].second]
                                                            : 0) -
                   (child[v[j].second] == good[v[j].second] ? child[v[j].second]
                                                            : 0));
    }
  }
}
int param(int x) {
  int i, j, k;
  for (i = 0; i < n; i++) b[i] = a[i] >= x;
  ngood = count(b, b + n, 1);
  back(0, -1);
  ans = 0;
  back2(0, -1);
  return ans >= m;
}
int main() {
  int i, j, k;
  cin >> n >> m;
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  for (i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y), x--, y--;
    edge[x].push_back(y), edge[y].push_back(x);
  }
  int low = 0, high = 1000001, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (param(mid))
      low = mid + 1;
    else
      high = mid - 1;
  }
  cout << high;
  return 0;
}
