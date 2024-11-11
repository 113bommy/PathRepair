#include <bits/stdc++.h>
using namespace std;
const int nmax = 100007;
int a[nmax];
vector<pair<int, int>> dp;
bool f(int index, int n) {
  if (index + 2 < n) {
    if (a[index + 2] - a[index] >= 2) return true;
  }
  if (index - 1 >= 0 && index + 1 < n) {
    if (a[index + 1] - a[index - 1] >= 2) return true;
  }
  return false;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int amount = 1;
  int maxLength = -1;
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i - 1])
      amount++;
    else {
      dp.push_back(make_pair(i - 1, amount));
      maxLength = max(maxLength, amount);
      amount = 1;
    }
  }
  dp.push_back(make_pair(n - 1, amount));
  maxLength = max(maxLength, amount);
  if (n > 1) maxLength++;
  for (int i = 0; i < dp.size() - 1; i++) {
    int index = dp[i].first;
    if (f(index, n)) {
      maxLength = max(maxLength, dp[i].second + dp[i + 1].second);
    }
  }
  cout << maxLength;
  return 0;
}
