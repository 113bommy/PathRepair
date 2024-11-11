#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 5;
const int mod = 1000000007;
vector<int> v1, v2;
int a[N];
map<int, int> mp;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  int i, j, n, m, k, d, x, y, z;
  cin >> n;
  for (int i = 0; i < 2 * n; i++) {
    cin >> x;
    v1.push_back(x);
  }
  sort((v1).begin(), (v1).end());
  x = v1[n - 1] - v1[0];
  y = v1[2 * n - 1] - v1[n];
  long long ans = (long long)x * y;
  for (int i = 1; i < n; i++)
    ans =
        min(ans, (long long)(v1[2 * n - 1] - v1[0]) * (v1[i + n - 1] - v1[i]));
  cout << ans << endl;
  return 0;
}
