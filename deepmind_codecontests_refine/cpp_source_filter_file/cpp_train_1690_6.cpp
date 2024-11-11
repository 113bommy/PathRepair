#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
long long b[200001];
long long last[2000001];
long long dp[200001];
const long long slide = 2e6 + 1;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < 2e6 + 1; i++) {
    last[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    long long& cur = last[b[i] - i + slide];
    if (cur != -1) {
      dp[i] = dp[cur] + b[i];
    } else
      dp[i] = b[i];
    cur = i;
  }
  long long MAX = -1;
  for (int i = 0; i < n; i++) {
    if (dp[i] > MAX) MAX = dp[i];
  }
  cout << MAX << endl;
}
