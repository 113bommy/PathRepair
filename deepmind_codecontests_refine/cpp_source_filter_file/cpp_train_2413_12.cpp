#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long i, j;
  long long n, m, k, q;
  cin >> n >> m >> k >> q;
  long long maxirow = -1;
  map<long long, pair<long long, long long>> tre;
  while (k--) {
    long long r, c;
    cin >> r >> c;
    if (tre[r].first == 0)
      tre[r].first = c;
    else
      tre[r].first = min(tre[r].first, c);
    if (tre[r].second == 0)
      tre[r].second = c;
    else
      tre[r].second = max(tre[r].second, c);
    maxirow = max(maxirow, r);
  }
  vector<long long> safe;
  while (q--) {
    long long c;
    cin >> c;
    safe.push_back(c);
  }
  sort(safe.begin(), safe.end());
  long long startrow = tre.begin()->first;
  long long cc = 1, dist = maxirow - 1;
  auto cr = tre.begin();
  if (startrow == 1) {
    cc = tre[1].second;
    dist += tre[1].second - 1;
    cr++;
  }
  queue<pair<long long, long long>> ans;
  ans.push({cc, dist});
  while (cr != tre.end()) {
    long long ends[2];
    ends[0] = cr->second.first;
    ends[1] = cr->second.second;
    map<long long, long long> eed;
    eed[ends[0]] = eed[ends[1]] = LLONG_MAX;
    while (!ans.empty()) {
      long long ccol = ans.front().first, cdist = ans.front().second;
      long long pos =
          lower_bound(safe.begin(), safe.end(), ccol) - safe.begin();
      if (safe[pos] == ccol) {
        eed[ends[0]] = min(
            eed[ends[0]], cdist + abs(ends[1] - ccol) + abs(ends[0] - ends[1]));
        eed[ends[1]] = min(
            eed[ends[1]], cdist + abs(ends[0] - ccol) + abs(ends[0] - ends[1]));
      } else {
        if (pos != safe.size()) {
          eed[ends[0]] = min(eed[ends[0]], cdist + abs(ccol - safe[pos]) +
                                               abs(safe[pos] - ends[1]) +
                                               abs(ends[0] - ends[1]));
          eed[ends[1]] = min(eed[ends[1]], cdist + abs(ccol - safe[pos]) +
                                               abs(safe[pos] - ends[0]) +
                                               abs(ends[0] - ends[1]));
        }
        pos--;
        if (pos != -1) {
          eed[ends[0]] = min(eed[ends[0]], cdist + abs(ccol - safe[pos]) +
                                               abs(safe[pos] - ends[1]) +
                                               abs(ends[0] - ends[1]));
          eed[ends[1]] = min(eed[ends[1]], cdist + abs(ccol - safe[pos]) +
                                               abs(safe[pos] - ends[0]) +
                                               abs(ends[0] - ends[1]));
        }
      }
      ans.pop();
    }
    ans.push({ends[0], eed[ends[0]]});
    ans.push({ends[1], eed[ends[1]]});
    cr++;
  }
  long long mini = INT_MAX;
  while (!ans.empty()) {
    mini = min(mini, ans.front().second);
    ans.pop();
  }
  cout << mini;
}
