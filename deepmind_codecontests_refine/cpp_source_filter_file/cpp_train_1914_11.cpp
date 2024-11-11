#include <bits/stdc++.h>
using namespace std;
void fileIO() {}
bool sortbysecdesc(const pair<long long, long long> &a,
                   const pair<long long, long long> &b) {
  return a.second > b.second;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  fileIO();
  long long T;
  T = 1;
  while (T--) {
    long long n;
    cin >> n;
    long long sz = ((n * (n - 1)) / 2) - 1;
    vector<pair<long long, long long>> xy(sz);
    unordered_map<long long, long long> freq;
    for (auto &p : xy) {
      cin >> p.first >> p.second;
      freq[p.first]++;
      freq[p.second]++;
    }
    long long x1 = 0, x2 = 0;
    for (auto p : freq) {
      if (p.second < n - 1) {
        if (x1 == 0) {
          x1 = p.first;
        } else {
          x2 = p.first;
        }
      }
    }
    unordered_set<long long> win, lose;
    for (auto p : xy) {
      if (p.first == x1) {
        win.insert(p.second);
      }
      if (p.second == x1) {
        lose.insert(p.first);
      }
    }
    long long ans1 = 0, ans2 = 0;
    for (auto p : xy) {
      if (p.first == x2) {
        if (lose.find(p.second) != lose.end()) {
          ans1 = x2;
          ans2 = x1;
          break;
        }
      }
      if (p.second == x2) {
        if (win.find(p.second) != win.end()) {
          ans1 = x1;
          ans2 = x2;
          break;
        }
      }
    }
    cout << ans1 << " " << ans2;
  }
  return 0;
}
