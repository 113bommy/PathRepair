#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> v;
  vector<long long> ans(n, 0);
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    v.push_back(x);
  }
  vector<pair<long long, long long> > p[2];
  p[0].push_back(pair<long long, long long>(-1, LLONG_MIN));
  p[1].push_back(pair<long long, long long>(-1, LLONG_MIN));
  for (long long i = 1; i < n; i++) {
    long long x = v[i];
    long long y = -1 * v[i];
    pair<long long, long long> a = p[0][i - 1];
    pair<long long, long long> b = p[1][i - 1];
    pair<long long, long long> a0(2, LLONG_MAX);
    pair<long long, long long> a1(2, LLONG_MAX);
    if (a.first != 2) {
      if (v[i - 1] < x) {
        if (a0.second > a.second) {
          a0 = pair<long long, long long>(0, a.second);
        }
      }
      if (a.second < x) {
        if (a0.second > v[i - 1]) {
          a0 = pair<long long, long long>(0, v[i - 1]);
        }
      }
      if (v[i - 1] < y) {
        if (a1.second > a.second) {
          a1 = pair<long long, long long>(0, a.second);
        }
      }
      if (a.second < y) {
        if (a1.second > v[i - 1]) {
          a1 = pair<long long, long long>(0, v[i - 1]);
        }
      }
    }
    if (b.first != 2) {
      if (-1 * v[i - 1] < x) {
        if (a0.second > b.second) {
          a0 = pair<long long, long long>(1, b.second);
        }
      }
      if (b.second < x) {
        if (a0.second > -1 * v[i - 1]) {
          a0 = pair<long long, long long>(1, -1 * v[i - 1]);
        }
      }
      if (-1 * v[i - 1] < y) {
        if (a1.second > b.second) {
          a1 = pair<long long, long long>(1, b.second);
        }
      }
      if (b.second < y) {
        if (a1.second > -1 * v[i - 1]) {
          a1 = pair<long long, long long>(1, -1 * v[i - 1]);
        }
      }
    }
    p[0].push_back(a0);
    p[1].push_back(a1);
  }
  if (p[0][n - 1].first != 2) {
    ans[n - 1] = v[n - 1];
    long long c = 0;
    for (int i = n - 2; i >= 0; i--) {
      c = p[c][i + 1].first;
      if (c == 0) {
        ans[i] = v[i];
      } else {
        ans[i] = -1 * v[i];
      }
    }
  } else if (p[1][n - 1].first != 2) {
    ans[n - 1] = -1 * v[n - 1];
    long long c = 1;
    for (int i = n - 2; i >= 0; i--) {
      c = p[c][i + 1].first;
      if (c == 0) {
        ans[i] = v[i];
      } else {
        ans[i] = -1 * v[i];
      }
    }
  } else {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (long long i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    solve();
  }
}
