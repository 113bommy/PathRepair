#include <bits/stdc++.h>
using namespace std;
const int maxn = 1234567;
int a[100000];
vector<int> v1, v2;
map<char, int> m2;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a[i + 1] - a[i] <= k)
      ans++;
    else
      ans = 1;
  }
  cout << ans;
}
