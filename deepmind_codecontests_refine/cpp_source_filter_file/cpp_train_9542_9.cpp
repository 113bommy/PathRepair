#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, m;
  cin >> n >> k >> m;
  map<string, int> cost;
  string T[n];
  for (int i = 0; i < n; i++) cin >> T[i];
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cost[T[i]] = x;
  }
  int cosst[k];
  for (int i = 0; i < k; i++) {
    int c;
    cin >> c;
    int MIN = 1000000007;
    while (c--) {
      int indx;
      cin >> indx;
      indx--;
      MIN = min(cost[T[indx]], MIN);
      cost[T[indx]] = i;
    }
    cosst[i] = MIN;
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    string str;
    cin >> str;
    ans += cosst[cost[str]];
  }
  cout << ans;
  return 0;
}
