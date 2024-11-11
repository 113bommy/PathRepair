#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const long long INF = 1e18;
const long double PI = 4 * atan((long double)1);
const int INFTY = 1e7;
int N;
long long B[4001];
set<int> second;
unordered_map<int, int> m;
long long dp[4001][4001];
int main() {
  cin >> N;
  int index = 0;
  for (int i = 0; i < (N); i++) cin >> B[i], second.insert(B[i]);
  for (auto v : second) m[v] = index++;
  for (int i = 0; i < (N); i++) B[i] = m[B[i]];
  for (int i = 0; i < (N); i++)
    for (int j = 0; j < (N); j++) dp[i][j] = 1;
  long long best = 1;
  for (int i = 0; i < (N); i++) {
    for (int j = 0; j < i; j++) {
      dp[i][B[j]] = ((1 + dp[j][B[i]]) > (dp[i][B[j]]) ? (1 + dp[j][B[i]])
                                                       : (dp[i][B[j]]));
      best = ((dp[i][B[j]]) > (best) ? (dp[i][B[j]]) : (best));
    }
  }
  cout << best << "\n";
}
