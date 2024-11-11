#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
template <class T>
int size(T &x) {
  return x.size();
}
int main() {
  int n;
  scanf("%d\n", &n);
  vector<pair<int, int> > *adj = new vector<pair<int, int> >[n];
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    scanf("%d %d %d\n", &a, &b, &c);
    a--, b--;
    adj[a].push_back(pair<int, int>(b, c));
    adj[b].push_back(pair<int, int>(a, c));
  }
  vector<int> cnt(n);
  int totalcnt = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d\n", &cnt[i]);
    totalcnt += cnt[i];
  }
  int lo = 0, hi = 10000;
  while (lo < hi) {
    int m = hi - (hi - lo) / 2;
    bool ok = true;
    vector<bool> visited(n, false);
    for (int i = 0; ok && i < n; i++) {
      if (visited[i]) continue;
      stack<int> S;
      S.push(i);
      visited[i] = true;
      int cursize = 0;
      int curcnt = 0;
      while (!S.empty()) {
        int cur = S.top();
        S.pop();
        cursize++;
        curcnt += cnt[cur];
        for (int i = 0; i < size(adj[cur]); i++) {
          pair<int, int> nxt = adj[cur][i];
          if (nxt.second >= m) {
            continue;
          }
          if (!visited[nxt.first]) {
            S.push(nxt.first);
            visited[nxt.first] = true;
          }
        }
      }
      ok = cursize <= totalcnt - curcnt;
    }
    if (ok) {
      lo = m;
    } else {
      hi = m - 1;
    }
  }
  printf("%d\n", hi);
  return 0;
}
