#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  std::vector<long long> A(n);
  long long mx = 0;
  map<long long, long long> make_pair;
  std::vector<std::vector<long long>> pos(100002);
  for (long long i = 0; i < n; i++) {
    cin >> A[i];
    if (mx < A[i]) {
      mx = A[i];
    }
    pos[A[i]].push_back(i);
    make_pair[A[i]]++;
  }
  for (long long i = mx; i >= 2; i--) {
    if (make_pair[i] > make_pair[1]) {
      cout << -1 << endl;
      return;
    }
  }
  cout << make_pair[1] << endl;
  long long sz;
  std::vector<long long> res(n);
  long long num;
  for (long long i = 1; i <= mx; i++) {
    sz = pos[i].size();
    num = 1;
    for (long long j = 0; j < sz; j++) {
      res[pos[i][j]] = num;
      num++;
    }
  }
  for (long long a : res) {
    cout << a << " ";
  }
  cout << endl;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  solve();
  return 0;
}
