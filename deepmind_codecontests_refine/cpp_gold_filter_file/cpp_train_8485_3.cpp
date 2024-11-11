#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  long long L = n * n;
  vector<vector<long long> > g;
  g.resize(n);
  for (int i = 0; i < n; i++) {
    g[i].resize(n);
  }
  for (int i = 0; i < n; ++i) {
    long long mx = L - (i + 1) * (n - k) - i;
    long long mn = (k - 1) * i + 1;
    for (int j = 0; j < (k - 1); j++) {
      g[i][j] = (mn++);
    }
    for (int j = (k - 1); j < n; j++) {
      g[i][j] = (mx++);
    }
  }
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += g[i][k - 1];
  }
  cout << sum << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; j++) {
      cout << g[i][j] << ' ';
    }
    cout << endl;
  }
}
