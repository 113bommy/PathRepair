#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, q;
  cin >> n >> k >> q;
  vector<long long> friends(n);
  set<pair<long long, long long>> online;
  for (long long i = 0; i < n; i++) {
    cin >> friends[i];
  }
  for (long long i = 0; i < q; i++) {
    long long a, b;
    cin >> a >> b;
    if (a == 1) {
      online.insert({friends[b], b});
      auto it = online.rbegin();
      if (online.size() > k) online.erase(*it);
    } else {
      if (online.find({friends[b], b}) != online.end()) {
        cout << "YES";
      } else
        cout << "NO";
      cout << endl;
    }
  }
}
