#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  long long int n;
  cin >> n;
  vector<long long int> v[n + 1];
  for (long long int i = 0; i < n - 1; i++) {
    long long int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (long long int i = 0; i < n; i++) {
    if (v[i].size() == 2) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
