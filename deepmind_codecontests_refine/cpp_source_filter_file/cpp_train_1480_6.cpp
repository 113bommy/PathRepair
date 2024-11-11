#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
void solve(vector<int> cnt, vector<int> to_del) {
  if (cnt[1] - cnt[0] != cnt[2] - cnt[3] || cnt[1] - cnt[0] < 0) {
    return;
  }
  if (cnt[1] - cnt[0] == 0 && cnt[0] != 0 && cnt[3] != 0) {
    return;
  }
  cout << "YES\n";
  vector<int> res;
  for (int i = 0; i < 2; ++i) {
    if (cnt[i] == 0) {
      continue;
    }
    int j = i;
    while (j < 4 && cnt[j] != 0) {
      while (cnt[j] > 0) {
        res.push_back(j + 1);
        res.push_back(j);
        --cnt[j];
        --cnt[j + 1];
      }
      res.pop_back();
      ++j;
    }
    --j;
    while (j >= i) {
      res.push_back(j);
      --j;
    }
  }
  int n = (int)(res).size();
  if ((int)(to_del).size() == 1) {
    for (int i = 0; i < n; ++i) {
      if (res[i] == to_del[0]) {
        reverse(res.begin(), res.begin() + i);
        reverse(res.begin() + i, res.end());
        res.pop_back();
        break;
      }
    }
  }
  if ((int)(to_del).size() == 2) {
    if ((res[0] == to_del[0] && res.back() == to_del[1]) ||
        (res[0] == to_del[1] && res.back() == to_del[0])) {
      res.pop_back();
      reverse((res).begin(), (res).end());
      res.pop_back();
    } else {
      for (int i = 0; i < n - 1; ++i) {
        if ((res[i] == to_del[0] && res[i + 1] == to_del[1]) ||
            (res[i] == to_del[1] && res[i + 1] == to_del[0])) {
          reverse(res.begin(), res.begin() + i);
          reverse(res.begin() + i, res.end());
          res.pop_back();
          res.pop_back();
          break;
        }
      }
    }
  }
  for (int i = 0; i < (int)(res).size(); ++i) {
    cout << res[i] << " ";
  }
  cout << "\n";
  exit(0);
}
void solve() {
  vector<int> cnt(4);
  for (int i = 0; i < 4; ++i) {
    cin >> cnt[i];
  }
  solve(cnt, {});
  for (int i = 0; i < 4; ++i) {
    ++cnt[i];
    solve(cnt, {i});
    --cnt[i];
  }
  ++cnt[1];
  ++cnt[2];
  solve(cnt, {1, 2});
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(12) << fixed;
  cerr << setprecision(12) << fixed;
  int tests = 1;
  while (tests--) {
    solve();
  }
}
