#include <bits/stdc++.h>
using namespace std;
long long int dp[500][500];
void init() {
  memset(dp, 0ll, sizeof(dp));
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  init();
  long long int n;
  cin >> n;
  long long int w[n + 1];
  w[0] = 0ll;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  int p;
  cin >> p;
  long long int a, b;
  set<pair<pair<long long int, long long int>, int> > queries;
  for (int i = 0; i < p; i++) {
    cin >> a >> b;
    queries.insert(make_pair(make_pair(a, b), i));
  }
  long long int sol[p];
  set<pair<pair<long long int, long long int>, int> >::iterator it =
      queries.end();
  it--;
  bool done = false;
  for (int i = n; i > 0; i--) {
    for (int j = 1; j < 500; j++) {
      dp[i % 500][j] = w[i] + ((i + j <= n) ? (dp[(i + j) % 500][j]) : 0ll);
    }
    while ((*it).first.first == i) {
      int gap = (*it).first.second;
      if (gap < 500) {
        sol[(*it).second] = dp[i % 500][gap];
      } else {
        long long int ans = 0ll;
        for (int j = i; j <= n; j += gap) {
          ans += w[i];
        }
        sol[(*it).second] = ans;
      }
      if (it == queries.begin()) {
        done = true;
        break;
      }
      it--;
    }
    if (done) break;
  }
  for (int i = 0; i < p; i++) {
    cout << sol[i] << "\n";
  }
  return 0;
}
