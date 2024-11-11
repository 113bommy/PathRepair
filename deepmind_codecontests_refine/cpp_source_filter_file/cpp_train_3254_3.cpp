#include <bits/stdc++.h>
using namespace std;
void start() {}
long long int dp[4010][4010];
void beast() {
  long long int a;
  cin >> a;
  long long int arr[4010];
  vector<long long int> v;
  cin >> arr[0];
  long long int x = arr[0];
  long long int count = 1;
  long long int check = 0;
  for (long long int i = 1; i < 2 * a; i++) {
    cin >> arr[i];
    if (arr[i] >= arr[i - 1]) check++;
    if (arr[i] < x)
      count++;
    else {
      v.push_back(count);
      count = 1;
      x = arr[i];
    }
  }
  if (check == 2 * a - 1) {
    cout << "YES" << endl;
    return;
  }
  v.push_back(count);
  for (long long int i = 0; i < a + 1; i++) dp[0][i] = 0;
  dp[0][0] = 1;
  dp[0][v[0]] = 1;
  for (long long int i = 1; i < v.size(); i++) {
    dp[i][0] = 1;
    for (long long int j = i; j < a + 1; j++) {
      dp[i][j] = 0;
      dp[i][j] = dp[i - 1][j];
      if (j >= v[i]) {
        dp[i][j] = dp[i][j] | dp[i - 1][j - v[i]];
      }
    }
  }
  if (dp[v.size() - 1][a] == 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
signed main() {
  start();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int zx = 1;
  cin >> zx;
  while (zx--) {
    beast();
  }
}
