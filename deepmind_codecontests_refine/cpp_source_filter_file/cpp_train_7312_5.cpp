#include <bits/stdc++.h>
using namespace std;
template <class A = long long int>
void Out(vector<A> a) {
  for (long long int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
vector<vector<long long int> > dp;
long long int val;
vector<vector<long long int> > a;
vector<vector<bool> > visited;
long long int f(long long int x, long long int y) {
  if (visited[x][y]) {
    return dp[x][y];
  }
  visited[x][y] = true;
  if (a[x][y] < val + x + y) {
    dp[x][y] = 100000000000000000LL;
    return 100000000000000000LL;
  }
  if (x > 0) {
    dp[x][y] = min(dp[x][y], f(x - 1, y));
  }
  if (y > 0) {
    dp[x][y] = min(dp[x][y], f(x, y - 1));
  }
  dp[x][y] += (a[x][y] - (val + x + y));
  return dp[x][y];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int T;
  cin >> T;
  vector<vector<long long int> > xx;
  vector<long long int> xxx;
  for (long long int t = 0; t < T; t++) {
    long long int N, M;
    cin >> N >> M;
    long long int ans = 100000000000000000LL;
    a.clear();
    dp.clear();
    vector<long long int> xx;
    for (long long int i = 0; i < M; i++) {
      xx.push_back(0LL);
    }
    for (long long int i = 0; i < N; i++) {
      a.push_back(xx);
      dp.push_back(xx);
    }
    visited.clear();
    vector<bool> yy;
    for (long long int i = 0; i < M; i++) {
      yy.push_back(false);
    }
    for (long long int i = 0; i < N; i++) {
      visited.push_back(yy);
    }
    set<long long int> s;
    set<long long int>::iterator it;
    for (long long int i = 0; i < N; i++) {
      for (long long int j = 0; j < M; j++) {
        cin >> a[i][j];
        s.insert(a[i][j] - i - j);
      }
    }
    it = s.begin();
    while (it != s.end()) {
      val = *it;
      for (long long int i = 0; i < N; i++) {
        for (long long int j = 0; j < M; j++) {
          dp[i][j] = 100000000000000000LL;
          visited[i][j] = false;
        }
      }
      if (val > a[0][0]) {
        break;
      }
      dp[0][0] = a[0][0] - val;
      visited[0][0] = true;
      ans = min(ans, f(N - 1, M - 1));
      it++;
    }
    cout << ans << endl;
  }
  return 0;
}
