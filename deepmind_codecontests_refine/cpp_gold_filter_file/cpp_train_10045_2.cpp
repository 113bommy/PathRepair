#include <bits/stdc++.h>
using namespace std;
long long n, k, dp[100];
long long f(int i) {
  if (dp[i] != -1) return dp[i];
  if (i == n + 1) return 1;
  return dp[i] = (i < n ? f(i + 2) : 0) + f(i + 1);
}
vector<int> r;
void bt(int i, long long k) {
  if (i == n + 1) return;
  if (k <= f(i + 1)) {
    r.push_back(i);
    bt(i + 1, k);
  } else {
    r.push_back(i + 1);
    r.push_back(i);
    bt(i + 2, k - f(i + 1));
  }
}
int main() {
  while (cin >> n >> k) {
    memset(dp, -1, sizeof(dp));
    r.clear();
    bt(1, k);
    for (int i = (0); i < (((int)r.size())); i++)
      cout << r[i] << (i == ((int)r.size()) - 1 ? '\n' : ' ');
  }
  return 0;
}
