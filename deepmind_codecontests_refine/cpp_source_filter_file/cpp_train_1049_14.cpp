#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, d, i, j, k, start, end, targ, y, last;
  cin >> n >> d >> k;
  vector<pair<int, int> > vec;
  queue<int> que;
  if (n < d + 1 || (k == 1 && n > 1)) {
    cout << "NO";
    return 0;
  }
  start = 1;
  end = d + 1;
  vector<int> cap(n + 1, 0);
  vector<int> dis(n + 1, 0);
  int prev = 1;
  for (i = 2; i < end; ++i) {
    dis[i] = (i - start < end - i ? i - start : end - i);
    que.push(i);
    cap[i] = 2;
    vec.push_back({prev, i});
    prev = i;
  }
  vec.push_back({prev, end});
  targ = n - d - 1;
  last = end + 1;
  while (!que.empty() && targ > 0) {
    i = que.front();
    que.pop();
    if (dis[i] == 0) continue;
    y = (k - cap[i] < targ ? k - cap[i] : targ);
    targ -= y;
    cap[i] -= y;
    for (j = 0; j < y; ++j) {
      dis[last + j] = dis[i] - 1;
      cap[last + j] = 1;
      que.push(last + j);
      vec.push_back({last + j, i});
    }
    last += y;
  }
  if (targ != 0) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  for (auto j : vec) cout << j.first << " " << j.second << "\n";
}
