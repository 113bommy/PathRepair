#include <bits/stdc++.h>
using namespace std;
struct edge {
  int r;
  int c;
  int id;
} edges[100005];
bool operator<(edge e1, edge e2) {
  if (e1.r == e2.r) return e1.c < e2.c;
  return (e1.r < e2.r);
}
set<int> myset;
int main() {
  int n, m, i, j;
  cin >> n >> m;
  for ((i) = 0; (i) < (int)(m); (i)++) {
    cin >> edges[i].r >> edges[i].c;
    edges[i].id = i + 1;
  }
  sort(edges, edges + m);
  for (i = 1; i <= n; i++) myset.insert(i);
  myset.insert(1000000);
  int ans = 0;
  vector<int> toans;
  for ((i) = 0; (i) < (int)(m); (i)++) {
    int maxi = edges[i].r, mini = n + 1 - edges[i].c;
    set<int>::iterator it = myset.lower_bound(mini);
    if ((*it) <= maxi + 1) {
      int k = (*it);
      ans++;
      myset.erase(k);
      toans.push_back(edges[i].id);
    }
  }
  cout << ans << endl;
  for ((i) = 0; (i) < (int)(((int)(toans).size())); (i)++) {
    cout << toans[i] << " ";
  }
  cin.get();
  cin.get();
  return 0;
}
