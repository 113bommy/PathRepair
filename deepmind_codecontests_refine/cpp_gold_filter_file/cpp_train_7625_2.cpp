#include <bits/stdc++.h>
using namespace std;
struct info {
  int x, pos, dir = 0;
};
bool cmp(info a, info b) { return a.x < b.x; }
const int MAXN = 5001;
const int INF = 1e9;
int dp[MAXN][MAXN];
void solve() {
  map<char, int> cnt;
  string S;
  cin >> S;
  int n = S.size();
  for (int i = 0; i < n; i++) {
    cnt[S[i]]++;
  }
  int r = cnt['R'];
  int p = cnt['P'];
  int s = cnt['S'];
  char ans = ' ';
  if (r >= max(p, s)) {
    ans = 'P';
  } else if (s >= max(r, p)) {
    ans = 'R';
  } else {
    ans = 'S';
  }
  cout << string(n, ans) << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
