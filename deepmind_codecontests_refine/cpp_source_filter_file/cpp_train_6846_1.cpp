#include <bits/stdc++.h>
using namespace std;
int solve() {
  long long n, k, a;
  string ans;
  set<long long> set;
  map<long long, long long> map;
  cin >> n >> k;
  for (long long i = 0; i < n; i++) {
    cin >> map[i];
    set.insert(map[i]);
  }
  if (set.size() >= k) {
    long long counter = 1;
    cout << "YES\n";
    for (auto X : map) {
      if (set.find(X.second) != set.end()) {
        if (counter >= k) {
          break;
        }
        cout << X.first + 1 << " ";
        set.erase(X.second);
        counter++;
      }
    }
  } else {
    cout << "NO";
  }
  return 0;
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
