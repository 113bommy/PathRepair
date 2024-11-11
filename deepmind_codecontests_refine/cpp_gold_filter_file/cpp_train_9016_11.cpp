#include <bits/stdc++.h>
using namespace std;
int W[10004], cost[10004], dp[104][1004], ans[1000];
int NS(int i, int w, int cap, int n) {
  int p1, p2;
  if (i > n) return 0;
  if (dp[i][w] != -1) return dp[i][w];
  if (w + W[i] <= cap) {
    p1 = cost[i] + NS(i + 1, w + W[i], cap, n);
  } else {
    p1 = 0;
  }
  p2 = NS(i + 1, w, cap, n);
  dp[i][w] = max(p1, p2);
  if (w + W[i] <= cap) ans[w + W[i]] = dp[i][w];
  return dp[i][w];
}
int ar[123456], br[123456];
vector<int> v;
void solve() {
  int n, k, m, p = 0;
  cin >> n >> k >> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    br[i] = x;
    ar[x % m]++;
  }
  bool ok = 0;
  for (int i = 0; i < 100004; i++) {
    if (ar[i] >= k) {
      puts("Yes");
      ok = 1;
      p = i;
      break;
    }
  }
  if (ok) {
    int i = 0;
    while (k) {
      if (br[i] % m == p) {
        v.push_back(br[i]);
        k--;
      }
      i++;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  } else
    puts("No");
}
int main() {
  solve();
  return 0;
}
