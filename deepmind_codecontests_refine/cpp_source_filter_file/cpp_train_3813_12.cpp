#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
bool compare(const pair<string, int> &a, const pair<string, int> &b) {
  return a.second < b.second;
}
bool compare_float(double x, double y) { return fabs(x - y) < DBL_EPSILON; }
double logn(double n, double r) { return (n > r - 1) ? 1 + logn(n / r, r) : 0; }
vector<long long int> pwx(61);
void cal(long long int x) {
  pwx[0] = 1;
  for (long long int i = 1; i < 61; i++) pwx[i] = x * pwx[i - 1];
}
void solve() {
  long long int n, m, k;
  cin >> n >> m >> k;
  long long int mat[m][n];
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }
  vector<vector<pair<long long int, long long int>>> vec(m);
  long long int score = 0, ans = 0;
  for (long long int j = 0; j < m; j++) {
    long long int cnt = 0;
    for (long long int i = 0; i < n; i++) {
      if (mat[i][j]) {
        cnt = 0;
        for (long long int l = i; l < i + k && l < n; l++) {
          if (mat[l][j]) cnt++;
        }
        vec[j].push_back({i, cnt});
      }
    }
  }
  long long int mx = 0;
  for (long long int i = 0; i < m; i++) {
    mx = 0;
    for (auto j : vec[i]) {
      mx = max(j.second, mx);
    }
    for (auto j : vec[i]) {
      if (j.second == mx) break;
      ans++;
    }
    score += mx;
  }
  cout << score << " " << ans << "\n";
}
int main() {
  cal(2);
  int t = 1, k = 1;
  while (t--) {
    solve();
    k++;
  }
}
