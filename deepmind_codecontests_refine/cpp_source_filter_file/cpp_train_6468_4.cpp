#include <bits/stdc++.h>
using namespace std;
string str;
int n;
int score[105];
long long dp[105][105][105];
long long iter(int s, int e, int p = 1) {
  if (s > e) return 0;
  if (s == e) return score[p];
  if (dp[p][s][e]) return dp[p][s][e];
  long long sc = iter(s + 1, e, 1) + score[1];
  for (int i = s + 1; i <= e; i++) {
    int ind = str.find(str[s], i);
    if (ind >= 0 && ind <= e) {
      sc = max(sc, iter(s + 1, ind - 1, 1) + iter(ind, e, p + 1));
    }
  }
  dp[p][s][e] = sc;
  return sc;
}
int main() {
  cin >> n;
  cin >> str;
  for (int i = 1; i <= n; i++) cin >> score[i];
  cout << iter(0, n - 1) << "\n";
  return 0;
}
