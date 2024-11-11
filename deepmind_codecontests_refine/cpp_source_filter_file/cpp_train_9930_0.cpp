#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> adj[n + 100];
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int count1 = 0, count2 = 0, count3 = 0;
  for (int i = 1; i <= n; i++) {
    if (adj[i].size() == 1) count1++;
    if (adj[i].size() == 2) count2++;
    if (adj[i].size() == n - 1) count3++;
  }
  if (count2 == n)
    cout << "ring topology";
  else if (count1 == 2 && count2 == n - 2)
    cout << "bus topology";
  else if (count1 == n - 1 && count3 == n - 1)
    cout << "star topology";
  else
    cout << "unknown topology ";
}
