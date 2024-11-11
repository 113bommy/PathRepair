#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  int m = 1;
  for (int i = 0; i < m; i++) {
    solve();
  }
  return 0;
}
long long INF = INT64_MAX;
long long mod = 1000000007LL;
long long b, c;
long long opt(long long val, long long r) {
  long long t = val - r;
  if (b > 5LL * c)
    return t * c;
  else
    return (t % 5) * c + (t / 5) * b;
}
void solve() {
  long long n, k;
  cin >> n >> k >> b >> c;
  vector<vector<long long> > tr(5);
  vector<vector<long long> > a(5);
  for (long long i = 0; i < n; i++) {
    long long cur;
    cin >> cur;
    a[((cur % 5) + 500000) % 5].push_back(cur);
    for (long long j = 0; j < 5; j++) {
      tr[(((cur + j) % 5) + 50000) % 5].push_back(cur + j);
    }
  }
  for (long long i = 0; i < 5; i++) {
    sort(a[i].begin(), a[i].end());
    reverse(a[i].begin(), a[i].end());
    sort(tr[i].begin(), tr[i].end());
    auto it = unique(tr[i].begin(), tr[i].end());
    tr[i].erase(it, tr[i].end());
    reverse(tr[i].begin(), tr[i].end());
  }
  long long ans = INF;
  for (long long i = 0; i < 5; i++) {
    long long kol = 0;
    long long res = 0;
    long long maxx = 100000000LL + i;
    vector<long long> begins(5, 0);
    vector<long long> ends(5, 0);
    for (long long j = 0; j < tr[i].size(); j++) {
      long long val = tr[i][j];
      for (long long q = 0; q < 5; q++) {
        while (begins[q] < ends[q]) {
          if (a[q][begins[q]] > val) {
            kol--;
            res -= opt(maxx, a[q][begins[q]]);
            begins[q]++;
          } else {
            break;
          }
        }
        if (begins[q] == ends[q]) {
          while (begins[q] < a[q].size()) {
            if (a[q][begins[q]] > val) {
              begins[q]++;
              ends[q]++;
            } else
              break;
          }
        }
      }
      while (kol < k) {
        long long q_opt = -1;
        long long val_opt = INF;
        for (long long q = 0; q < 5; q++) {
          if (a[q].size() > ends[q]) {
            long long cur = a[q][ends[q]];
            if (opt(maxx, cur) < val_opt) {
              val_opt = opt(maxx, cur);
              q_opt = q;
            }
          }
        }
        if (q_opt != -1) {
          res += val_opt;
          ends[q_opt]++;
          kol++;
        } else {
          res = INF;
          break;
        }
      }
      if (kol != k) {
        break;
      }
      if (res - (maxx - val) / 5 * min(b, 5 * c) * k < ans) {
        ans = res - (maxx - val) / 5 * min(b, 5 * c) * k;
      }
    }
  }
  cout << ans;
}
