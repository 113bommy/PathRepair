#include <bits/stdc++.h>
using namespace std;
vector<long long> vis(3e5 + 10, 0);
vector<long long> temp;
class graph {
 private:
  long long v;
  list<long long>* adj;

 public:
  graph(long long x) {
    v = x + 1;
    adj = new list<long long>[v];
  }
  void adedge(long long a, long long b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  void dfs(long long s);
  void bfs(long long s);
};
void graph::dfs(long long s) {
  vis[s] = 1;
  temp.push_back(s);
  list<long long>::iterator it;
  for (it = adj[s].begin(); it != adj[s].end(); it++) {
    if (!vis[*it]) {
      dfs(*it);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long i, j, k, l, m, n;
    cin >> n >> m;
    long long arr[n + 1];
    long long cnt[n];
    memset(cnt, 0, sizeof cnt);
    for (i = 1; i <= n; i++) {
      cin >> arr[i];
      long long pos = i, num = arr[i];
      if (pos >= num)
        cnt[pos - num] += 1;
      else
        cnt[n - num + pos] += 1;
    }
    vector<long long> ans;
    for (i = 0; i < n; i++) {
      long long a1 = cnt[i];
      long long rem = n - cnt[i];
      if (rem - 1 <= m)
        ans.push_back(i);
      else {
        if (cnt[i] >= n - 2 * m) {
          vector<long long> v2(n + 1, 0);
          vector<long long> v1(n + 1, 0);
          graph g(n);
          for (j = 0; j <= n; j++) vis[j] = 0;
          for (j = 1; j <= n; j++) {
            long long x = n - i + 1;
            if (j <= i)
              v1[j] = n - i + j;
            else
              v1[j] = j - i;
            if (arr[j] > n - i)
              v2[j] = i - (n - arr[j]);
            else
              v2[j] = arr[j] + i;
            g.adedge(j, v1[j]);
          }
          long long tot = 0;
          for (j = 1; j <= n; j++) {
            if (!vis[j]) {
              temp.clear();
              g.dfs(j);
              tot += (long long)temp.size() - 1;
            }
          }
          if (tot <= m) ans.push_back(i);
        }
      }
    }
    cout << (long long)ans.size() << " ";
    for (auto it : ans) cout << it << " ";
    cout << "\n";
  }
  return 0;
}
