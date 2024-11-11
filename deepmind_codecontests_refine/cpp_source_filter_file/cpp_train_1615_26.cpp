#include <bits/stdc++.h>
using namespace std;
void c_p_c() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const long long N = 123456;
vector<long long> graph[N + 1];
long long dist[N + 1];
void dfs(long long src, long long par, long long& maxlen, long long& snode,
         set<long long>& s) {
  if (s.find(src) != s.end()) {
    if (dist[src] > maxlen) {
      maxlen = dist[src];
      snode = src;
    }
    if (dist[src] == maxlen && src < snode) snode = src;
  }
  for (long long nbr : graph[src]) {
    if (nbr != par) {
      dist[nbr] = dist[src] + 1;
      dfs(nbr, src, maxlen, snode, s);
    }
  }
}
long long dfs2(long long src, long long par, set<long long>& s) {
  long long ans = -1;
  if (s.find(src) != s.end()) ans = 0;
  for (long long nbr : graph[src]) {
    if (nbr != par) {
      long long subans = dfs2(nbr, src, s);
      if (subans == -1)
        continue;
      else {
        if (ans == -1) ans = 0;
        ans += subans + 1;
      }
    }
  }
  return ans;
}
int32_t main() {
  c_p_c();
  long long n, m;
  cin >> n >> m;
  set<long long> s;
  for (long long i = 0; i < n - 1; i++) {
    long long a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (long long i = 0; i < m; i++) {
    long long a;
    cin >> a;
    s.insert(a);
  }
  if (m == 1) {
    cout << *(s.begin()) << endl;
    cout << 0 << endl;
    return 0;
  }
  long long maxnode = -1;
  queue<long long> q;
  q.push(*(s.begin()));
  vector<bool> visited(n + 1, false);
  visited[*(s.begin())] = true;
  while (!q.empty()) {
    long long src = q.front();
    q.pop();
    for (long long nbr : graph[src]) {
      if (!visited[nbr]) {
        if (s.find(nbr) != s.end()) {
          maxnode = nbr;
        }
        visited[nbr] = true;
        q.push(nbr);
      }
    }
  }
  long long snode = maxnode;
  long long maxlen = 0;
  dist[snode] = 0;
  dfs(maxnode, -1, maxlen, snode, s);
  dist[maxnode] = 0;
  dfs(maxnode, -1, maxlen, snode, s);
  cout << snode << endl;
  cout << 2 * dfs2(snode, -1, s) - maxlen << endl;
}
