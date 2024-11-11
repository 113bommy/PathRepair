#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
vector<int> adj[35];
int solve(int cnt, vector<int>& v) {
  if ((int)v.size() <= 1) {
    return (int)v.size();
  }
  vector<int> one, two;
  for (int u : v) {
    if (u & (1 << (cnt - 1))) {
      one.push_back(u);
    } else {
      two.push_back(u);
    }
  }
  int sol = 0;
  sol = solve(cnt - 1, one) + ((int)two.size() > 0);
  sol = max(sol, solve(cnt - 1, two) + ((int)one.size() > 0));
  return sol;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed;
  cout.precision(10);
  int n;
  cin >> n;
  vector<int> a(n);
  int group = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int x = a[i];
    int cnt = 0;
    while (x) {
      cnt++;
      x >>= 1;
    }
    if ((int)adj[cnt].size() == 0) {
      group++;
    }
    adj[cnt].push_back(a[i]);
  }
  int ct = 0;
  int sol = group;
  for (int i = 0; i < 34; i++) {
    if ((int)adj[i].size() == 0) {
      continue;
    }
    ct++;
    sol = max(sol, solve(i - 1, adj[i]) + group - 1);
    if (ct > 1) group--;
  }
  cout << n - sol << "\n";
  return 0;
}
