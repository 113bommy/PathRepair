#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<long long> x(n);
    for (long long i = 0; i < n; ++i) {
      cin >> x[i];
    }
    vector<string> s(n);
    for (long long i = 0; i < n; ++i) {
      cin >> s[i];
    }
    vector<vector<long long>> gr(1 << n);
    for (long long j = 0; j < m; ++j) {
      long long sum = 0;
      for (long long i = 0; i < n; ++i) {
        sum = (sum << 1) + s[i][j] - '0';
      }
      gr[sum].push_back(j);
    }
    vector<vector<long long>> srt;
    for (long long i = 0; i < (1 << n); ++i) {
      if ((long long)gr[i].size()) {
        srt.push_back(gr[i]);
      }
    }
    vector<long long> col(m);
    for (long long i = 0; i < (long long)srt.size(); ++i) {
      for (auto& j : srt[i]) {
        col[j] = i;
      }
    }
    vector<vector<long long>> uses(n);
    for (long long i = 0; i < n; ++i) {
      for (long long j = 0; j < m; ++j) {
        if (s[i][j] == '1') {
          uses[i].push_back(col[j]);
        }
      }
      sort(uses[i].begin(), uses[i].end());
      uses[i].erase(unique(uses[i].begin(), uses[i].end()), uses[i].end());
    }
    long long ans = 0;
    vector<long long> vans;
    for (long long i = 0; i < (1 << n); ++i) {
      long long sum = 0;
      vector<long long> gcnt((long long)srt.size());
      for (long long j = 0; j < n; ++j) {
        if (i & (1 << j)) {
          sum += x[j];
          for (auto& x : uses[j]) {
            --gcnt[x];
          }
        } else {
          sum -= x[j];
          for (auto& x : uses[j]) {
            ++gcnt[x];
          }
        }
      }
      vector<vector<long long>> gsrt;
      for (long long h = 0; h < (long long)srt.size(); ++h) {
        gsrt.push_back({gcnt[h], (long long)srt[h].size(), h});
      }
      sort(gsrt.begin(), gsrt.end());
      long long l = 1;
      for (long long h = 0; h < (long long)srt.size(); ++h) {
        long long r = l + (long long)gsrt[h][1] - 1;
        sum += (r + l) * (r - l + 1) / 2 * gsrt[h][0];
        l = r + 1;
      }
      if (sum >= ans) {
        ans = sum;
        vans.clear();
        for (long long h = 0; h < (long long)srt.size(); ++h) {
          vans.push_back(gsrt[h][2]);
        }
      }
    }
    vector<long long> out(m);
    long long l = 1;
    for (auto& i : vans) {
      for (auto& j : srt[i]) {
        out[j] = l++;
      }
    }
    for (long long i = 0; i < m; ++i) {
      cout << out[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
