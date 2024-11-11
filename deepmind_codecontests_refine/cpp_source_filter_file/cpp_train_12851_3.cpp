#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a;
  cin >> n >> m;
  vector<int> v;
  queue<int> q;
  for (int i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);
    q.push(i);
  }
  while (q.size() != 1) {
    for (int i = 0; i < q.size(); i++) {
      int j = q.front();
      q.pop();
      v[j] -= m;
      if (v[j] >= 0) q.push(j);
    }
  }
  int ans = q.front();
  cout << ans + 1 << endl;
  return 0;
}
