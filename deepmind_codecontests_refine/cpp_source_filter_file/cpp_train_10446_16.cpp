#include <bits/stdc++.h>
using namespace std;
vector<long long> adj[100002];
vector<long long> vis(100002, 0);
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long n, m;
  cin >> n >> m;
  long long sum = 0;
  if (n >= 2 && m >= 2) {
    for (int i = 2; i <= n; i += 2) {
      for (int j = 2; j <= m; j += 2) {
        sum += (n - i - 1) * (m - 1 - j);
      }
    }
    cout << sum;
  } else {
    cout << 0 << '\n';
  }
}
