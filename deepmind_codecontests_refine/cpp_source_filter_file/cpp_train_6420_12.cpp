#include <bits/stdc++.h>
using namespace std;
long long n, m;
pair<long long, long long> a[12];
pair<long long, long long> b[12];
signed main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (long long i = 0; i < (n); i++) {
    cin >> a[i].first >> a[i].second;
  }
  for (long long i = 0; i < (m); i++) {
    cin >> b[i].first >> b[i].second;
  }
  vector<long long> ans;
  for (long long i = 0; i < (n); i++) {
    long long cur = 0;
    for (long long j = 0; j < (m); j++) {
      if ((a[i].first == b[j].first && a[i].second != b[j].second) ||
          (a[i].first == b[j].second && a[i].second != b[j].first)) {
        if (cur == 0) {
          cur = a[i].first;
          ans.push_back(a[i].first);
        } else if (cur != a[i].first) {
          cout << (-1) << "\n";
          return 0;
        }
      }
      if ((a[i].second == b[j].first && a[i].first != b[j].second) ||
          (a[i].second == b[j].second && a[i].first != b[j].first)) {
        if (cur == 0) {
          cur = a[i].second;
          ans.push_back(a[i].second);
        } else if (cur != a[i].second) {
          cout << (-1) << "\n";
          return 0;
        }
      }
    }
  }
  for (long long i = 0; i < (m); i++) {
    long long cur = 0;
    for (long long j = 0; j < (n); j++) {
      if ((b[i].first == a[j].first && b[i].second != a[j].second) ||
          (b[i].first == a[j].second && b[i].second != a[j].first)) {
        if (cur == 0) {
          cur = b[i].first;
          ans.push_back(b[i].first);
        } else if (cur != b[i].first) {
          cout << (-1) << "\n";
          return 0;
        }
      }
      if ((b[i].second == a[j].first && b[i].first != a[j].second) ||
          (b[i].second == a[j].second && b[i].first != a[j].first)) {
        if (cur == 0) {
          cur = b[i].second;
          ans.push_back(b[i].second);
        } else if (cur != b[i].second) {
          cout << (-1) << "\n";
          return 0;
        }
      }
    }
  }
  sort(ans.begin(), ans.end());
  for (long long i = 0; i < (ans.size() - 1); i++) {
    if (ans[i] != ans[i + 1]) {
      cout << (0) << "\n";
      return 0;
    }
  }
  cout << (1) << "\n";
}
