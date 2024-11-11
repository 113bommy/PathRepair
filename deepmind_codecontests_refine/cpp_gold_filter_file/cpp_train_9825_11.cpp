#include <bits/stdc++.h>
using namespace std;
using namespace std;
const long long INF = 1e16;
long long score[100100];
bool visited[100100];
int32_t main() {
  long long n, q;
  cin >> n >> q;
  vector<long long> v(n);
  vector<long long> c(n);
  for (long long i = 0; i < n; ++i) cin >> v[i];
  for (long long i = 0; i < n; ++i) cin >> c[i];
  while (q--) {
    for (long long i = 0; i < 100100; ++i) {
      visited[i] = false;
      score[i] = 0;
    }
    vector<long long> dp(n);
    long long maxValue = -INF, maxColor = -1, secMaxValue = -INF,
              secMaxColor = -1;
    long long a, b;
    cin >> a >> b;
    for (long long i = 0; i < n; ++i) {
      long long curr = b * v[i];
      if (visited[c[i]] == true) {
        curr = max(curr, score[c[i]] + a * v[i]);
      }
      if (maxColor != -1) {
        if (maxColor != c[i]) {
          curr = max(curr, maxValue + b * v[i]);
        } else if (secMaxColor != -1) {
          if (secMaxColor != c[i]) {
            curr = max(curr, secMaxValue + b * v[i]);
          }
        }
      }
      dp[i] = curr;
      if (visited[c[i]] == false)
        score[c[i]] = curr;
      else
        score[c[i]] = max(score[c[i]], curr);
      visited[c[i]] = true;
      if (curr >= maxValue) {
        if (c[i] != maxColor) {
          secMaxValue = maxValue;
          secMaxColor = maxColor;
          maxValue = curr;
          maxColor = c[i];
        } else {
          maxValue = curr;
        }
      } else if (curr > secMaxValue) {
        if (c[i] != maxColor) {
          secMaxValue = curr;
          secMaxColor = c[i];
        }
      }
    }
    for (long long i = 0; i < n; ++i) {
      maxValue = max(maxValue, dp[i]);
    }
    cout << max(0LL, maxValue) << endl;
  }
}
