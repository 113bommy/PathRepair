#include <bits/stdc++.h>
using namespace std;
long long component = 0, no_of_com = 0;
unordered_map<long long, long long> com;
void dfs(vector<long long> adj[], long long s) {
  no_of_com++;
  com[s] = component;
  for (long long a : adj[s]) {
    if (com[a] == 0) dfs(adj, a);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long k, m;
  cin >> k;
  vector<long long> adj[n + 1];
  unordered_map<long long, long long> mp;
  for (long long i = 0; i < k; i++) {
    long long a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (long long i = 1; i <= n; i++) {
    if (com[i] == 0) {
      component++;
      no_of_com = 0;
      dfs(adj, i);
      mp[com[i]] = no_of_com;
    }
  }
  cin >> k;
  for (long long i = 0; i < k; i++) {
    long long a, b;
    cin >> a >> b;
    if (com[a] == com[b]) {
      mp[com[a]] = 0;
    }
  }
  long long maxx = -1;
  for (long long i = 1; i <= component; i++) {
    if (maxx < mp[i]) maxx = mp[i];
  }
  cout << maxx;
  return 0;
}
