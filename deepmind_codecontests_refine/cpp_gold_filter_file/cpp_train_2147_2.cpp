#include <bits/stdc++.h>
using namespace std;
const int inf = 1000 * 1000 * 1000;
int k[3], t[3];
int n;
long long c[1 << 17], out[1 << 17];
queue<long long> w[3], Q;
set<long long> S;
int main() {
  for (int i = 0; i < 3; ++i) cin >> k[i];
  for (int i = 0; i < 3; ++i) cin >> t[i];
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> c[i];
  long long time = c[0];
  int cur = 0;
  int tt = 0;
  S.insert(c[0]);
  while (S.size()) {
    time = *S.begin();
    while (cur < n && time >= c[cur]) Q.push(c[cur]), cur++;
    while (!w[2].empty() && w[2].front() <= time) w[2].pop(), out[tt++] = time;
    while (!w[1].empty() && w[1].front() <= time && w[2].size() < k[2])
      w[2].push(time + t[2]), w[1].pop();
    while (!w[0].empty() && w[0].front() <= time && w[1].size() < k[1])
      w[1].push(time + t[1]), w[0].pop();
    while (!Q.empty() && w[0].size() < k[0]) w[0].push(time + t[0]), Q.pop();
    for (int i = 0; i < 3; ++i)
      if (w[i].size() && time < w[i].front()) S.insert(w[i].front());
    if (Q.size() && time < Q.front()) S.insert(Q.front());
    if (cur < n && time < c[cur]) S.insert(c[cur]);
    S.erase(S.begin());
  }
  long long res = 0;
  for (int i = 0; i < n; ++i) res = max(res, out[i] - c[i]);
  cout << res << endl;
  return 0;
}
