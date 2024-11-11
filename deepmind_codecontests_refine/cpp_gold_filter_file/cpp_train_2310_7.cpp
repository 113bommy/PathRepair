#include <bits/stdc++.h>
using namespace std;
const int LIMIT = 5e5 + 7;
const int INF = 1e9 + 7;
long long n, dp[LIMIT];
string s;
int main() {
  cin >> s;
  n = s.size();
  for (int i = 1; i < n; i++) {
    if (s[i] > s[dp[i - 1]]) {
      dp[i] = dp[i - 1];
    } else {
      dp[i] = i;
    }
  }
  for (int i = 0; i < n; i++) {
    printf(dp[i] == i ? "Mike\n" : "Ann\n");
  }
  return EXIT_SUCCESS;
}
