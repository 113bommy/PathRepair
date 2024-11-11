#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long mod1 = 998244353;
const int N = 1e5 + 12;
long long b, m;
vector<long long> v;
void solve() {
  cin >> b >> m;
  if (b == m || m + 1 == b || m == 1) {
    cout << "YES";
    return;
  }
  if (m < b) {
    cout << "NO";
    return;
  }
  while (m) {
    v.push_back(m % b);
    m /= b;
  }
  v.push_back(0);
  for (int i = 0; i < (long long)v.size() - 1; i++) {
    if (v[i] <= 1) continue;
    if (v[i] >= b - 1)
      v[i + 1]++, v[i] = 0;
    else {
      cout << "NO";
      return;
    }
  }
  cout << "YES";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
