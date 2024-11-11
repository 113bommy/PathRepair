#include <bits/stdc++.h>
using namespace std;
struct edge {
  int f, s, id;
};
bool comp(edge x, edge y) {
  if (x.f == y.f) {
    if (x.s == y.s) {
      return x.id < y.id;
    }
    return x.s < y.s;
  }
  return x.f < y.f;
}
edge a[100010];
int n;
queue<int> q;
vector<pair<int, int> > ans;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].f >> a[i].s;
    a[i].id = i;
  }
  for (int i = 0; i < n; i++) {
    if (a[i].f == 1) {
      q.push(i);
    }
  }
  while (q.empty() == false) {
    edge cur = a[q.front()];
    q.pop();
    if (cur.f != 1)
      continue;
    else {
      ans.push_back(make_pair(cur.id, cur.s));
      int sosed = cur.s ^ cur.id;
      a[sosed].f--;
      a[sosed].s = a[sosed].s ^ cur.id;
      if (a[sosed].f == 1) q.push(sosed);
    }
  }
  cout << ans.size();
  cout << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}
