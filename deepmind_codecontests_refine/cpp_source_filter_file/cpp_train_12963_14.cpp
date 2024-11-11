#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1234567;
const int MOD = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  vector<pair<int, int> > M, F;
  while (N--) {
    char s;
    int l, r;
    cin >> s >> l >> r;
    if (s == 'M')
      M.push_back(pair<int, int>(l, r));
    else
      F.push_back(pair<int, int>(l, r));
  }
  int ans = 0;
  for (int i = 1; i <= 366; i++) {
    int a = 0, b = 0;
    for (int j = 0; j < M.size(); j++) {
      if (M[i].first <= i && M[i].second >= i) a++;
    }
    for (int j = 0; j < F.size(); j++) {
      if (F[i].first <= i && F[i].second >= i) b++;
    }
    ans = max(ans, 2 * min(a, b));
  }
  cout << ans << endl;
  return 0;
}
