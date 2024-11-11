#include <bits/stdc++.h>
using namespace std;
vector<long long int> adj[100001];
vector<long long int> num;
bool visit[100001] = {};
long long int ans = 0;
void dfs(long long int node) {
  visit[node] = true;
  num.push_back(node);
  for (auto to : adj[node]) {
    if ((long long int)adj[node].size() > 2) {
      ans = -1;
    }
    if (visit[to] == false) {
      dfs(to);
    }
  }
}
int main() {
  long long int n;
  cin >> n;
  long long int colour[4][n + 1];
  for (long long int i = 1; i <= 3; i++) {
    for (long long int j = 1; j <= n; j++) {
      cin >> colour[i][j];
    }
  }
  for (long long int i = 1; i <= n - 1; i++) {
    long long int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  long long int deg1 = 1;
  for (long long int i = 1; i <= n; i++) {
    if ((long long int)adj[i].size() == 1) {
      deg1 = i;
      break;
    }
  }
  dfs(deg1);
  if (ans == -1 || (long long int)num.size() != n) {
    cout << -1;
    return 0;
  }
  long long int minimum = 10000;
  long long int p[n + 1];
  vector<long long int> a;
  for (long long int i = 1; i <= 3; i++) {
    for (long long int j = 1; j <= 3; j++) {
      if (i == j) continue;
      long long int s = 0;
      long long int ci = i, cj = j;
      a.clear();
      a.push_back(ci);
      a.push_back(cj);
      s = colour[ci][num[0]] + colour[cj][num[1]];
      for (long long int i = 2; i < n; i++) {
        s = s + colour[6 - ci - cj][num[i]];
        a.push_back(6 - ci - cj);
        long long int temp = ci;
        ci = cj;
        cj = 6 - temp - cj;
      }
      if (minimum > s) {
        minimum = s;
        for (long long int i = 0; i < n; i++) p[num[i]] = a[i];
      }
    }
  }
  cout << minimum << "\n";
  for (long long int i = 1; i <= n; i++) cout << p[i] << " ";
}
