#include <bits/stdc++.h>
using namespace std;
void run_case() {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> A;
  for (long long i = 0; i < n; i++) {
    A.push_back({i, i});
    A.push_back({i, i + 1});
    A.push_back({i + 1, i});
  }
  A.push_back({n, n});
  cout << A.size() << '\n';
  for (auto a : A) {
    cout << a.first << ' ' << a.second << '\n';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  long long test = 1;
  while (test--) {
    run_case();
    cout << '\n';
  }
}
