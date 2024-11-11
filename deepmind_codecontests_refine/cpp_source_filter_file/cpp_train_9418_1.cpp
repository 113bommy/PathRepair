#include <bits/stdc++.h>
using namespace std;
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
const int mod = 1000000007;
const int N = 3e5, M = N;
int max3(int a, int b, int c) {
  int ma = max(a, b);
  return max(ma, c);
}
vector<int> g[N];
int a[N];
void solve() {
  int i = 0, j = 0, n, flag = 0, flag2 = -1, sma_pos = INT_MAX, lar_pos = -1;
  string s;
  cin >> s;
  n = s.size();
  int first = s[n - 1] - '0';
  for (i = n - 2; i >= 0; i--) {
    if ((s[i] - '0') % 2 == 0) {
      flag = 1;
      if (s[i] - '0' < first)
        sma_pos = min(sma_pos, i);
      else
        lar_pos = max(lar_pos, i);
    }
  }
  if (flag == 0) {
    cout << -1;
    return;
  }
  if (sma_pos > lar_pos && (sma_pos < (n + 1)))
    swap(s[sma_pos], s[n - 1]);
  else {
    for (i = lar_pos + 1; i < n; i++) {
      if ((s[i] - '0') % 2 == 0) {
        flag2 = i;
        break;
      }
    }
    if (flag2 != -1)
      swap(s[flag2], s[n - 1]);
    else
      swap(s[lar_pos], s[n - 1]);
  }
  cout << s;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
