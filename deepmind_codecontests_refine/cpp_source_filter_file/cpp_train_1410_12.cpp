#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const long long mod = 1e9 + 7;
void solve();
signed main() {
  srand('V' + 'a' + 'n' + 'k' + 'a' + 'T' + 'a' + 'g' + 'a' + 'n' + 'a' + 'i');
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
long long sign(long long x) {
  if (x < 0) return 1;
  return 0;
}
void solve() {
  set<long long> numbers;
  map<long long, long long> left;
  map<long long, long long> right;
  long long n, v;
  cin >> n >> v;
  numbers.insert(v);
  for (long long i = 0; i < n - 1; i++) {
    cin >> v;
    auto it = numbers.upper_bound(v);
    long long result;
    if (it != numbers.end() && left.count(*it) == 0) {
      left[*it] = v;
      result = *it;
    } else {
      it--;
      right[*it] = v;
      result = *it;
    }
    numbers.insert(v);
    cout << result;
    if (i == n - 2)
      cout << 'n';
    else
      cout << ' ';
  }
  return;
}
