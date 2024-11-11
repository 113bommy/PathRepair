#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
template <typename T>
void printv(const T& t) {
  std::copy(t.cbegin(), t.cend(),
            std::ostream_iterator<typename T::value_type>(std::cout, ", "));
  cout << endl;
}
long long int modpower(long long int a, long long int b, long long int c) {
  long long int res = 1;
  while (b) {
    if (b & 1LL) res = (res * a) % c;
    a = (a * a) % c;
    b >>= 1;
  }
  return res;
}
void solve() {
  long long int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << "YES\n";
    return;
  }
  cout << "NO\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
