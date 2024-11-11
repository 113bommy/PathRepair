#include <bits/stdc++.h>
const long long mod = (long long)1e9 + 7;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  if (n % 2 == 0) {
    cout << -1 << "\n";
    return 0;
  }
  for (long long i = 1; i <= n; i++) cout << i << " ";
  cout << "\n";
  for (long long i = 1; i <= n; i++) cout << i << " ";
  cout << "\n";
  vector<long long> v;
  for (long long i = 1; i <= n; i++) {
    v.push_back((i + i) % n);
  }
  for (auto i : v) cout << i << " ";
  return 0;
}
