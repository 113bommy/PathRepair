#include <bits/stdc++.h>
using namespace std;
long long int p = 1000000007;
int main() {
  long long int n, m;
  cin >> n >> m;
  pair<long long int, long long int> a[m + 1];
  vector<long long int> adj[n + 1];
  long long int ans1[n + 1], ans2[n + 1];
  for (long long int i = 1; i <= m; i++) {
    cin >> a[i].first >> a[i].second;
    adj[a[i].first].push_back(a[i].second);
    adj[a[i].second].push_back(a[i].first);
  }
  long long int c, d;
  c = d = -1;
  if (n == 1) {
    cout << "NO" << endl;
    return 0;
  }
  for (long long int i = 1; i <= n; i++) {
    if (adj[i].size() != n - 1) {
      if (adj[i].size() == 0) {
        c = i;
        d = i + 1;
        if (i == n) {
          d = 1;
        }
      } else {
        c = i;
        adj[i].push_back(i);
        sort(adj[i].begin(), adj[i].end());
        for (long long int j = 0; j < adj[i].size(); j++) {
          if (adj[i][j] != j + 1) {
            d = j + 1;
            break;
          }
        }
        if (d == -1) {
          d = adj[i].size() + 1;
        }
      }
      break;
    }
    if (i == n) {
      cout << "NO" << endl;
      return 0;
    }
  }
  for (long long int i = 1; i <= n; i++) {
    ans1[i] = ans2[i] = -1;
  }
  ans1[c] = ans2[c] = 1;
  ans1[d] = 2;
  ans2[d] = 1;
  long long int k = 3;
  for (long long int i = 1; i <= n; i++) {
    if (ans1[i] == -1) {
      ans1[i] = ans2[i] = k;
      k++;
    }
  }
  cout << "YES" << endl;
  for (long long int i = 1; i <= n; i++) {
    cout << ans1[i] << " ";
  }
  cout << endl;
  for (long long int i = 1; i <= n; i++) {
    cout << ans2[i] << " ";
  }
  cout << endl;
}
