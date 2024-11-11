#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<long long, long long>>> v(222222);
pair<long long, long long> dp[222222];
long long be[222222];
long long _n;
void makeGraph(vector<long long> &in, vector<long long> &out) {
  vector<long long> now;
  for (long long(i) = (0); (i) < (in.size()); ++i) {
    now.push_back(in[i]);
  }
  sort(now.begin(), now.end());
  now.erase(unique(now.begin(), now.end()), now.end());
  _n = now.size();
  for (long long(i) = (0); (i) < (in.size()); ++i) {
    long long a = lower_bound(now.begin(), now.end(), in[i]) - now.begin();
    auto it = lower_bound(now.begin(), now.end(), out[i]);
    if (it == now.end()) {
      v[a].emplace_back(1000000000, 1000000000);
    } else {
      v[a].emplace_back(it - now.begin(), (*it) - out[i]);
    }
    be[i] = in[i];
  }
}
void mod_add(long long &a, long long b) {
  a += b;
  a %= 1000000007;
}
void merge(pair<long long, long long> &a, pair<long long, long long> b) {
  if (a.first == b.first) {
    mod_add(a.second, b.second);
  } else if (a.first > b.first) {
    a = b;
  }
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);
  long long n;
  cin >> n;
  vector<long long> in(n);
  vector<long long> out(n);
  for (long long(i) = (0); (i) < (n); ++i) {
    cin >> out[i] >> in[i];
  }
  makeGraph(in, out);
  for (long long(i) = (0); (i) < (222222); ++i) {
    dp[i] = make_pair(be[i], (i == 0));
  }
  long long ans = 0;
  long long mi = 1000000000;
  for (long long(i) = (0); (i) < (222220); ++i) {
    if (v[i].size() == 0) {
      continue;
    }
    long long seica = 1000000000;
    for (long long(j) = (0); (j) < (v[i].size()); ++j) {
      if (v[i][j].first == 1000000000) {
        mi = min(mi, dp[i].first);
      } else {
        long long pla = v[i][j].second;
        pair<long long, long long> tmp =
            make_pair(dp[i].first + pla, dp[i].second);
        merge(dp[v[i][j].first], tmp);
        seica = min(seica, v[i][j].first);
      }
    }
    if (seica != i + 1) {
      merge(dp[i + 1],
            make_pair(dp[i].first + (be[i + 1] - be[i]), dp[i].second));
    }
  }
  for (long long(i) = (0); (i) < (222222); ++i) {
    if (dp[i].first != mi) continue;
    for (long long(j) = (0); (j) < (v[i].size()); ++j) {
      if (v[i][j].first == 1000000000) {
        mod_add(ans, dp[i].second);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
