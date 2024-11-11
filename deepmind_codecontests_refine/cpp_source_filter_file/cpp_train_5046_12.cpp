#include <bits/stdc++.h>
using namespace std;
int deg[7000005], xo[7000005], xo1[7000005];
int main() {
  int n, i, p;
  cin >> n;
  queue<int> que;
  for (i = 0; i < n; i++) {
    cin >> deg[i] >> xo[i];
    if (deg[i] == 1) que.push(i);
  }
  vector<pair<int, int> > vec;
  while (!que.empty()) {
    p = que.front();
    que.pop();
    if (deg[p] == 0) continue;
    int k = xo[p] ^ xo1[p];
    xo1[k] ^= xo[p];
    deg[k]--;
    deg[p]--;
    vec.push_back(make_pair(p, k));
    if (deg[k] >= 1) {
      que.push(k);
    }
  }
  int s = vec.size();
  cout << s << "\n";
  for (i = 0; i < s; i++) cout << vec[i].first << " " << vec[i].second << "\n";
  return 0;
}
