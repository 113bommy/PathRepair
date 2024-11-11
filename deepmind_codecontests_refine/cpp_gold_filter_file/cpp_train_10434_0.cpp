#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    std::vector<long long> v;
    for (long long i = 0; i < n; ++i) {
      long long x;
      cin >> x;
      v.push_back(x);
    }
    std::vector<long long> val;
    long long temp = 1;
    while (temp <= 10000000000000000) {
      val.push_back(temp);
      temp *= k;
    }
    map<long long, long long> track;
    long long flag = 0;
    for (auto i : v) {
      long long check = i;
      while (check > 0) {
        auto lb = lower_bound(val.begin(), val.end(), check);
        long long pos = lb - val.begin();
        if (val[pos] != check) pos--;
        if (track.count(pos) == 0) {
          track[pos] = 1;
        } else {
          flag = 1;
          break;
        }
        check -= val[pos];
      }
      if (flag) break;
    }
    if (flag) {
      cout << "NO" << endl;
    } else
      cout << "YES" << endl;
  }
}
