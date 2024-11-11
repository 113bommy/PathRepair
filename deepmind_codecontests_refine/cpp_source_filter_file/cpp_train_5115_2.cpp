#include <bits/stdc++.h>
using namespace std;
long long n;
vector<vector<long long> > adj;
vector<long long> a, s;
bool flag = false;
void DFS(long long curr, long long par, long long level) {
  if (flag) return;
  if (level % 2 == 0) {
    long long choice = INT64_MAX;
    for (auto x : adj[curr]) {
      if (x == par) continue;
      choice = min(choice, s[x]);
    }
    if (choice == INT64_MAX) {
      a[curr] = 0;
      s[curr] = a[curr] + s[par];
    } else {
      s[curr] = choice;
      a[curr] = s[curr] - s[par];
      if (a[curr < 0]) {
        flag = true;
        return;
      }
    }
  } else {
    if (par == -1) {
      a[curr] = s[curr];
    } else {
      a[curr] = s[curr] - s[par];
      if (a[curr < 0]) {
        flag = true;
        return;
      }
    }
  }
  for (auto x : adj[curr]) {
    if (x == par) continue;
    DFS(x, curr, level + 1);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  adj.resize(n + 1);
  a.resize(n + 1);
  s.resize(n + 1);
  for (long long i = 2; i <= n; i++) {
    long long p;
    cin >> p;
    adj[i].push_back(p);
    adj[p].push_back(i);
  }
  for (long long i = 1; i <= n; i++) {
    cin >> s[i];
  }
  DFS(1, -1, 1);
  if (flag)
    cout << "-1";
  else {
    long long sum = 0;
    for (long long i = 1; i <= n; i++) {
      sum = sum + a[i];
    }
    cout << sum;
  }
  return 0;
}
