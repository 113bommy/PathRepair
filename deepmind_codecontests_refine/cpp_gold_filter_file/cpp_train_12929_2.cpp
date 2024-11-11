#include <bits/stdc++.h>
using namespace std;
deque<int> cur[100006], fr[100005];
int idcnt = 0;
int fa[300005];
int gfa(int a) {
  if (fa[a] == a) return a;
  return fa[a] = gfa(fa[a]);
}
void otp(vector<int> a) {
  for (auto v : a) cout << v << ' ';
  cout << endl;
}
priority_queue<pair<int, int> > s;
int id[300005];
int main() {
  int n;
  const int test = 0;
  if (test)
    n = 3334;
  else
    cin >> n;
  for (int i = 1; i <= n; i++) {
    int ns;
    if (test)
      if (i < n)
        ns = 3;
      else
        ns = 290000;
    else
      scanf("%d", &ns);
    for (int j = 0; j < ns; j++)
      idcnt++, cur[i].push_back(idcnt), fr[i].push_back(idcnt);
    s.push(make_pair(ns, i));
  }
  for (int i = 1; i <= idcnt; i++) fa[i] = i;
  while (s.size() > 1) {
    pair<int, int> u1 = s.top();
    s.pop();
    pair<int, int> u2 = s.top();
    s.pop();
    int ls = 3;
    if (s.size()) ls = s.top().first;
    fa[gfa(cur[u2.second].front())] = gfa(cur[u1.second].front());
    int b1 = cur[u2.second].front(), b2 = 0;
    cur[u2.second].pop_front(), cur[u1.second].pop_front();
    int ur = u1.first + u2.first, tm = 1;
    while (tm < u2.first && (ur - 2) >= ls) {
      fa[gfa(cur[u2.second].front())] = gfa(cur[u1.second].front()), tm++,
      b2 = cur[u2.second].front();
      cur[u2.second].pop_front(), cur[u1.second].pop_front();
      ur -= 2;
    }
    cur[u1.second].push_front(b2);
    while (cur[u2.second].size())
      cur[u1.second].push_front(cur[u2.second].front()),
          cur[u2.second].pop_front();
    cur[u1.second].push_back(b1);
    s.push(make_pair(cur[u1.second].size(), u1.second));
  }
  int cnt = 0;
  for (int i = 1; i <= idcnt; i++)
    if (fa[i] == i) id[i] = ++cnt;
  printf("%d\n", cnt);
  for (int i = 1; i <= n; i++) {
    while (fr[i].size()) {
      printf("%d ", id[gfa(fr[i].front())]);
      fr[i].pop_front();
    }
    printf("\n");
  }
  return 0;
}
