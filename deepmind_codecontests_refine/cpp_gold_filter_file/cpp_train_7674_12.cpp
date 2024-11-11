#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const long double pi = acos(-1);
const int MOD = 1e9 + 7;
const int N = 1e6;
int n;
int a[66], b[66];
vector<int> v[66];
long double dp[110][110];
map<int, int> A;
double solve(int i, int k, long double limiar) {
  if (i == n) return 0;
  if (dp[i][k] > -1e16) {
    return dp[i][k];
  }
  double sum = 0;
  double y = A[i];
  for (int x : v[i]) {
    sum += limiar * x - y;
  }
  double ret = solve(i + 1, k + v[i].size(), limiar) + sum;
  int cnt = 1;
  for (int j = 0; j < v[i].size(); j++) {
    if ((k - cnt) >= 0) {
      sum = sum - (v[i][j] * limiar - y);
      ret = max(ret, solve(i + 1, k + v[i].size() - 2 * cnt, limiar) + sum);
      cnt++;
    }
  }
  return dp[i][k] = ret;
}
long double simula(long double x) {
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      dp[i][j] = -1e18;
    }
  }
  return solve(0, 0, x);
}
long double BB(long double b, long double e) {
  for (int i = 0; i < 400; i++) {
    double x = (b + e) / 2.0;
    if (simula(x) > 0) {
      e = x;
    } else {
      b = x;
    }
  }
  return b;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  map<int, vector<int>> caras;
  for (int i = 0; i < n; i++) {
    caras[a[i]].push_back(b[i]);
  }
  auto it = caras.end();
  it--;
  int cnt = 0;
  while (it != caras.begin()) {
    pair<int, vector<int>> aux = *it;
    v[cnt] = aux.second;
    A[cnt] = aux.first;
    it--;
    cnt++;
  }
  pair<int, vector<int>> aux = *it;
  v[cnt] = aux.second;
  A[cnt] = aux.first;
  cnt++;
  for (int i = 0; i < cnt; i++) {
    sort(v[i].begin(), v[i].end());
  }
  n = cnt;
  double lim = BB(0, 1000000000.0);
  long long resp = ceil(lim * 1000.0);
  cout << resp << endl;
  return 0;
}
