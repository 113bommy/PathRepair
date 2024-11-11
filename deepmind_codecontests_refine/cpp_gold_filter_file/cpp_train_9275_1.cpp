#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18, MOD = 1e9 + 7;
const int N = 1e5 + 10, N2 = 26 * N + 10, INFI = 1e9 + 10, L = 19;
int n, a[N], dp[N];
priority_queue<pair<int, int> > q;
long long add(long long a, long long b) {
  long long sum = a + b;
  if (sum < 0) {
    sum += MOD;
  }
  if (sum >= MOD) {
    sum -= MOD;
  }
  return sum;
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    q.push({a[i], i});
  }
  while (!q.empty()) {
    int i = q.top().second;
    for (int j = i + a[i]; j < n; j += a[i]) {
      if (a[j] > a[i]) {
        if (!dp[j]) {
          dp[i] = 1;
          break;
        }
      }
    }
    for (int j = i - a[i]; j >= 0; j -= a[i]) {
      if (a[j] > a[i]) {
        if (!dp[j]) {
          dp[i] = 1;
          break;
        }
      }
    }
    q.pop();
  }
  for (int i = 0; i < n; i++) {
    cout << (dp[i] ? 'A' : 'B');
  }
  cout << endl;
  return 0;
}
