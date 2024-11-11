#include <bits/stdc++.h>
using namespace std;
int N;
pair<int, int> P[52];
int Xn;
vector<int> X;
map<int, int> dx;
vector<pair<int, int> > V[52];
long long cc[52][52][52 * 100];
long long dp(int n, int r, int sum) {
  if (n == -1) return sum == 0 ? 0 : 1e18;
  long long &ret = cc[n][r][sum];
  if (ret != -1) return ret;
  ret = 1e18;
  if (r >= V[n].size()) ret = min(ret, dp(n - 1, r - (int)V[n].size(), sum));
  int tmp = 0;
  int cnt = 0;
  long long cum = 0;
  for (int i = (int)V[n].size() - 1; i >= 0; i--) {
    tmp += V[n][i].first;
    cnt++;
    cum += P[V[n][i].second].first;
    if (tmp <= sum && r >= (int)V[n].size() - cnt)
      ret =
          min(ret, dp(n - 1, r + 2 * cnt - (int)V[n].size(), sum - tmp) + cum);
  }
  return ret;
}
int main() {
  cout << fixed;
  cout.precision(0);
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &P[i].first);
    X.push_back(P[i].first);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", &P[i].second);
  }
  sort(X.begin(), X.end());
  X.resize(unique(X.begin(), X.end()) - X.begin());
  Xn = X.size();
  for (int i = 0; i < Xn; i++) dx[X[i]] = i;
  for (int i = 0; i < N; i++) V[dx[P[i].first]].push_back({P[i].second, i});
  for (int i = 0; i < 52; i++) {
    sort(V[i].begin(), V[i].end());
  }
  double ans = 1e18;
  memset(cc, -1, sizeof(cc));
  for (int i = 1; i <= 100 * N; i++) {
    ans = min(ans, (double)dp(Xn - 1, 0, i) / i);
  }
  ans *= 1000;
  cout << ceil(ans);
}
