#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e6 + 8;
const long long MOD = 1e9 + 7;
const long long sz = 1e5 + 5;
void f_io() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
}
int32_t main() {
  f_io();
  long long tc = 1;
  cin >> tc;
  auto rotate = [](vector<long long> &arr, long long index) {
    swap(arr[index], arr[index + 1]);
    swap(arr[index], arr[index + 2]);
  };
  while (tc--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    vector<long long> ret;
    for (auto &el : v) cin >> el;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n - 2; j++) {
        if (v[j] > v[j + 1]) {
          rotate(v, j);
          rotate(v, j);
          ret.push_back(j);
          ret.push_back(j);
        } else if (v[j + 1] > v[j + 2]) {
          rotate(v, j);
          ret.push_back(j);
        }
      }
    }
    if (!is_sorted(begin(v), end(v)))
      cout << "-1"
           << "\n";
    else {
      cout << ret.size() << "\n";
      for (auto el : ret) cout << el + 1 << " ";
      cout << "\n";
    }
  }
}
