#include <bits/stdc++.h>
using namespace std;
char vow[5] = {'a', 'e', 'i', 'o', 'u'};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int N = s.length();
  vector<int> cum(N + 1, 0);
  for (int i = 0; i < N; i++) {
    bool huh = 0;
    for (int j = 0; j < 5; j++) {
      huh |= (vow[j] == s[i]) || ((vow[j] ^ 32) == s[i]);
    }
    cum[i + 1] = cum[i];
    if (huh) {
      cum[i + 1] -= 1;
    } else {
      cum[i + 1] += 2;
    }
  }
  vector<pair<int, int> > P(N + 1);
  for (int i = 0; i <= N; i++) {
    P[i] = {cum[i], i};
  }
  sort(P.begin(), P.end());
  int ans = 0;
  int mnn = P[0].second;
  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    if (mnn <= P[i].second) {
      int cur = P[i].second - mnn;
      if (cur == ans) {
        cnt++;
      }
      if (cur > ans) {
        cnt = 1;
        ans = cur;
      }
    }
    mnn = min(P[i].second, mnn);
  }
  if (ans == 0) {
    cout << "No solution\n";
    return 0;
  }
  cout << ans << ' ' << cnt << endl;
  return 0;
}
