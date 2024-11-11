#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
vector<long long> g[1000005];
vector<bool> vis(1000005, 0);
long long dx[] = {-1, 0, 1, 0};
long long dy[] = {0, -1, 0, 1};
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  if (n <= 5) {
    cout << -1;
    for (long long i = 2; i <= n; i++) cout << 1 << " " << i << "\n";
  } else {
    cout << "1 2\n2 3\n2 4\n";
    for (long long i = 5; i <= n; i++) cout << 1 << " " << i << "\n";
    for (long long i = 2; i <= n; i++) cout << 1 << " " << i << "\n";
  }
}
