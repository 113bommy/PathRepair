#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
const int mod = 1000000007;
const double pi = (double)22 / 7;
int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; cin >> a[i++])
    ;
  if (n < k) {
    cout << -1;
    return 0;
  }
  sort(a.rbegin(), a.rend());
  cout << "0 " << a[k - 1];
}
