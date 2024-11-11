#include <bits/stdc++.h>
using namespace std;
int n, k;
set<pair<int, int> > myset, v[100001];
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    pq;
int main() {
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v[a].insert(make_pair(b, c));
    v[b].insert(make_pair(a, c));
  }
  for (int i = 1; i <= n; i++)
    if (v[i].size() == 1) {
      pq.push(make_pair(v[i].begin()->second, i));
    }
  int nods = n - k, val = 0;
  for (int i = 1; i <= nods || pq.size() > 2; i++) {
    val = pq.top().first;
    int nod = pq.top().second;
    int next = v[nod].begin()->first;
    pq.pop();
    v[next].erase(v[next].lower_bound(make_pair(nod, v[nod].begin()->second)));
    if (v[next].size() == 1) {
      pq.push(make_pair(val + v[next].begin()->second, next));
    }
  }
  cout << val;
  return 0;
}
