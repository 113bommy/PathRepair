#include <bits/stdc++.h>
const long long mod = 1000000007;
const long long Inf = 1e9;
using namespace std;
int n, K;
vector<tuple<int, int, int>> gloss(2001);
int main() {
  ios::sync_with_stdio(false);
  vector<int> days;
  int n, k, ans = -1e9 - 1000;
  cin >> n >> k;
  map<int, int> cards;
  for (int i = 0; i < 5; i++) {
    int f, t;
    cin >> f >> t;
    if (t > k)
      ans = max(ans, f - (t - k));
    else
      ans = max(ans, f);
  }
  cout << ans;
  return 0;
}
