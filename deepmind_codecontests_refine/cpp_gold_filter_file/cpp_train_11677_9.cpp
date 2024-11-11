#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
void solve() {
  long long int n, m;
  cin >> n >> m;
  for (long long int i = 1; i <= n / 2; i++)
    for (long long int j = 1; j <= m; j++) {
      cout << i << " " << j << "\n";
      cout << n - i + 1 << " " << m - j + 1 << "\n";
    }
  if (n % 2) {
    deque<long long int> q;
    long long int x = n / 2;
    cout << x + 1 << " " << 1 << "\n";
    for (long long int i = 2; i <= m; i++) q.push_back(i);
    while (q.size() > 0) {
      cout << x + 1 << " " << q.back() << "\n";
      q.pop_back();
      if (q.size() > 0) {
        cout << x + 1 << " " << q.front() << "\n";
        q.pop_front();
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
