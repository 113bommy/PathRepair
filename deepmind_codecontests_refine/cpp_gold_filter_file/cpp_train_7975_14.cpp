#include <bits/stdc++.h>
using namespace std;
typedef struct {
  long long int d;
  long long int t;
  long long int p;
  long long int idx;
} inp;
int comp(inp a, inp b) { return a.d < b.d; }
int main() {
  long long int n;
  cin >> n;
  vector<inp> a(n);
  for (long long int i = 0; i < n; i++) {
    cin >> a[i].t >> a[i].d >> a[i].p;
    a[i].idx = i;
  }
  sort(a.begin(), a.end(), comp);
  long long int ct = 0;
  for (long long int i = 0; i < n; i++) ct += a[i].p;
  long long int dp[n + 1][ct + 1], e[n + 1][ct + 1];
  for (long long int i = 0; i <= n; i++) {
    dp[i][0] = 0;
    e[i][0] = 0;
  }
  for (long long int i = 1; i <= ct; i++) {
    dp[0][i] = INT_MAX;
    e[0][i] = 0;
  }
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= ct; j++) {
      dp[i][j] = dp[i - 1][j];
      e[i][j] = 0;
      if (a[i - 1].p <= j &&
          (dp[i - 1][j - a[i - 1].p] + a[i - 1].t < a[i - 1].d)) {
        if (dp[i - 1][j - a[i - 1].p] + a[i - 1].t < dp[i - 1][j]) {
          dp[i][j] = dp[i - 1][j - a[i - 1].p] + a[i - 1].t;
          e[i][j] = 1;
        }
      }
    }
  }
  long long int i;
  for (i = ct; i >= 0; i--) {
    if (dp[n][i] != INT_MAX) break;
  }
  cout << i << endl;
  long long int j = n;
  vector<long long int> ans;
  while (i && j) {
    if (e[j][i] == 1) {
      ans.push_back(j);
      i -= a[j - 1].p;
      j -= 1;
    } else {
      j -= 1;
    }
  }
  cout << ans.size() << endl;
  sort(ans.begin(), ans.end());
  for (long long int i = 0; i < ans.size(); i++)
    cout << a[ans[i] - 1].idx + 1 << " ";
  cout << endl;
  return 0;
}
