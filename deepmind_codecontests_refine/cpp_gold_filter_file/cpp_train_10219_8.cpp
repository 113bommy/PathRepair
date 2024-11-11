#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, k;
  cin >> n >> k;
  long long int arr[k], mark[n];
  vector<long long int> que[n];
  for (long long int i = 0; i < n; i++) mark[i] = 0;
  for (long long int i = 0; i < k; i++) {
    cin >> arr[i];
    que[arr[i] - 1].push_back(i);
    mark[arr[i] - 1]++;
  }
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    if (!mark[i]) {
      ans += 3;
      if (i == 0 or i == n - 1) ans--;
      continue;
    }
    if (i == 0) {
      if (i + 1 <= n - 1) {
        if (!mark[i + 1]) {
          ans++;
          continue;
        }
        long long int our_p = que[i][0],
                      opp = que[i + 1][que[i + 1].size() - 1];
        if (our_p > opp) ans++;
      }
      continue;
    } else if (i == n - 1) {
      if (i - 1 >= 0) {
        if (!mark[i - 1]) {
          ans++;
          continue;
        }
        long long int our_p = que[i][0],
                      opp = que[i - 1][que[i - 1].size() - 1];
        if (our_p > opp) ans++;
      }
      break;
    }
    if (!mark[i + 1])
      ans++;
    else {
      long long int our_p = que[i][0], opp = que[i + 1][que[i + 1].size() - 1];
      if (our_p > opp) ans++;
    }
    if (!mark[i - 1])
      ans++;
    else {
      long long int our_p = que[i][0], opp = que[i - 1][que[i - 1].size() - 1];
      if (our_p > opp) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
