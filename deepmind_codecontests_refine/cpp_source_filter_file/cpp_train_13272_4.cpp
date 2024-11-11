#include <bits/stdc++.h>
using namespace std;
int n, k, a, m;
vector<int> hits;
int f(int s) {
  if (s < a) return 0;
  int times = (s - a) / (a + 1) + 1;
  return times;
}
bool solve(int moves) {
  if (moves == m + 1) return true;
  vector<int> all;
  for (int i = 0; i < moves; ++i) all.push_back(hits[i]);
  sort(all.begin(), all.end());
  int cnt = 0;
  cnt += f(all[0] - 1);
  cnt += f(n - all.back());
  for (int i = 0; i < moves - 1; ++i) cnt += f(all[i + 1] - all[i]);
  return cnt >= k;
}
int main() {
  cin >> n >> k >> a >> m;
  hits.resize(m);
  for (int i = 0; i < m; ++i) scanf("%d", &hits[i]);
  int lo = 1, hi = m + 1, mid;
  while (lo < hi) {
    mid = (lo + hi) / 2;
    if (!solve(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  if (lo == m + 1)
    cout << "-1\n";
  else
    cout << lo << '\n';
};
