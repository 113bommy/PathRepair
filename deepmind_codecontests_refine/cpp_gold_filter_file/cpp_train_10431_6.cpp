#include <bits/stdc++.h>
using namespace std;
long long n, k;
vector<int> v;
long long cache[2001][4001];
long long dp(int idx, int score) {
  if (idx == n && score > 0) return 1;
  if (idx == n) return 0;
  long long &ret = cache[idx][score + 2000];
  if (ret != -1) return ret;
  if (v[idx] == v[idx + 1]) return ret = (dp(idx + 1, score) * k) % 998244353;
  ret = dp(idx + 1, score + 1);
  ret += dp(idx + 1, score - 1);
  ret += dp(idx + 1, score) * (k - 2);
  return ret %= 998244353;
}
int main() {
  cin >> n >> k;
  v.resize(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  v.push_back(v[0]);
  if (k == 1) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < 2001; i++)
    for (int j = 0; j < 4001; j++) cache[i][j] = -1;
  cout << dp(0, 0);
}
