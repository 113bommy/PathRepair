#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> ts, cs;
vector<long long> dijk(vector<pair<int, int> > v[], int s) {
  vector<long long> ans(n, -1LL);
  priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                 greater<pair<long long, int> > >
      pq;
  ans[s] = 0;
  pq.push(make_pair(0LL, s));
  while (!pq.empty()) {
    pair<long long, int> now = pq.top();
    pq.pop();
    long long value = now.first;
    int id = now.second;
    for (int nexti = 0; nexti < (v[id].size()); ++nexti) {
      pair<int, int> pnext = v[id][nexti];
      int next = pnext.first;
      long long w = pnext.second;
      long long go = value + w;
      if (ans[next] == -1 || go < ans[next]) {
        ans[next] = go;
        pq.push(make_pair(go * 1LL, next));
      }
    }
  }
  return ans;
}
int main() {
  scanf("%d %d", &n, &m);
  int s, t;
  scanf("%d %d", &s, &t);
  s--;
  t--;
  vector<pair<int, int> > conn[1024];
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    a--;
    b--;
    conn[a].push_back(make_pair(b, c));
    conn[b].push_back(make_pair(a, c));
  }
  for (int i = 0; i < n; ++i) {
    int ti, ci;
    scanf("%d %d", &ti, &ci);
    ts.push_back(ti);
    cs.push_back(ci);
  }
  vector<pair<int, int> > cnn2[1024];
  for (int i = 0; i < n; ++i) {
    vector<long long> dis = dijk(conn, i);
    for (int j = 0; j < n; ++j) {
      if (dis[j] != -1 && dis[j] <= ts[i]) {
        cnn2[i].push_back(make_pair(j, cs[i]));
      }
    }
  }
  vector<long long> ans = dijk(cnn2, s);
  cout << ans[t] << endl;
}
