#include <bits/stdc++.h>
using namespace std;
vector<long long> graph[100005];
long long parent[100005];
long long s[100005];
long long a[100005];
bool visited[100005];
bool ass = false;
void dfs(long long v, long long sum) {
  visited[v] = true;
  if (s[v] == -1) {
    if ((long long)graph[v].size() == 1) {
      a[v] = 0;
      return;
    }
    long long mn = 987654321987654321;
    for (auto x : graph[v]) {
      if (!visited[x]) {
        mn = min(mn, s[x]);
      }
    }
    if (mn < sum) {
      ass = true;
      return;
    }
    a[v] = mn - sum;
    sum = mn;
  } else {
    a[v] = s[v] - sum;
    if (a[v] < 0) {
      ass = true;
      return;
    }
    sum = s[v];
  }
  for (auto x : graph[v]) {
    if (!visited[x]) {
      dfs(x, sum);
    }
  }
}
int main() {
  long long n;
  cin >> n;
  for (long long i = 2; i <= n; ++i) {
    cin >> parent[i];
    graph[i].push_back(parent[i]);
    graph[parent[i]].push_back(i);
  }
  for (long long i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  dfs(1, 0);
  if (ass) {
    cout << "-1\n";
    return 0;
  }
  long long sum = 0;
  for (long long i = 1; i <= n; ++i) {
    sum += a[i];
  }
  cout << sum << "\n";
  return 0;
}
