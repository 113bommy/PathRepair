#include <bits/stdc++.h>
using namespace std;
pair<int, int> query(set<int> &v) {
  cout << "? ";
  for (int i : v) {
    cout << i << " ";
  }
  cout << endl;
  pair<int, int> r;
  cin >> r.first >> r.second;
  if (r.first == -1) exit(1);
  return r;
}
void solve() {
  int n, k;
  cin >> n >> k;
  set<int> q;
  for (int i = 1; i <= k; i++) q.insert(i);
  pair<int, int> x = query(q);
  q.erase(x.first);
  q.insert(k + 1);
  pair<int, int> y = query(q);
  int m = 0;
  q.insert(x.first);
  for (int i = 1; i <= k + 1; i++) {
    if (i == x.first) continue;
    if (i == y.first) continue;
    q.erase(i);
    pair<int, int> ans = query(q);
    if ((ans.first == y.first) ^ (x.second < x.second)) m++;
    q.insert(i);
  }
  cout << "! " << m + 1 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
