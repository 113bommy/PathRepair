#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  cin >> n >> k;
  vector<pair<long long int, long long int>> v(n);
  for (long long int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    v[i] = {x, i};
  }
  sort(v.begin(), v.end());
  vector<long long int> dp(n);
  dp[0] = v[0].first;
  for (long long int i = 1; i < n; i++) {
    dp[i] = (dp[i - 1] + v[i].first);
  }
  long long int i = 0;
  while (dp[i] < k) {
    i++;
  }
  if (dp[i] == k) {
    cout << i + 1 << "\n";
    for (long long int j = 0; j < i + 1; j++) {
      cout << v[j].second + 1 << " ";
    }
    cout << "\n";
  } else {
    cout << i << "\n";
    if (i != 0) {
      for (long long int j = 0; j < i; j++) {
        cout << v[j].second + 1 << " ";
      }
      cout << "\n";
    }
  }
}
