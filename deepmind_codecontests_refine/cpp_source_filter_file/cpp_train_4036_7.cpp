#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v;
  vector<int> adj[n + 1];
  int a, b;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int max = 0, root, count = 0;
  for (int i = 1; i <= n; i++) {
    if ((int)adj[i].size() > max) {
      max = adj[i].size();
      root = i;
    }
    if (adj[i].size() > 2) count++;
    if (adj[i].size() == 1) v.push_back(i);
  }
  if (count > 1)
    cout << "NO\n";
  else {
    if (n == 2)
      cout << "Yes\n"
           << "1\n"
           << a << " " << b;
    else {
      cout << "YES\n";
      cout << v.size() << "\n";
      for (int i = 0; i < (int)v.size(); i++)
        cout << root << " " << v[i] << "\n";
    }
  }
}
