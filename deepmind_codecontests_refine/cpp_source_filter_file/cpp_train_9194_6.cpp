#include <bits/stdc++.h>
template <class _, class __>
bool checkmax(_ &a, __ b) {
  return a < b ? a = b, true : false;
}
template <class _, class __>
bool checkmin(_ &a, __ b) {
  return a > b ? a = b, true : false;
}
using namespace std;
const int P = 1e9 + 7;
char str[105];
int A[105];
int dp[105][4050];
int n;
void Add(int &a, int b) {
  a += b;
  if (a >= P) a -= P;
}
void solve() {
  memset(dp, 0, sizeof(dp));
  for (int i = (0), i_end_ = (26); i < i_end_; ++i) dp[1][i] = 1;
  for (int i = (2), i_end_ = (105); i < i_end_; ++i) {
    for (int j = (0), j_end_ = (4050); j < j_end_; ++j) {
      for (int k = (0), k_end_ = (26); k < k_end_; ++k)
        if (j >= k) Add(dp[i][j], dp[i - 1][j - k]);
    }
  }
}
int main() {
  int test;
  solve();
  cin >> test;
  while (test--) {
    int sum = 0;
    scanf("%s", str + 1);
    n = strlen(str + 1);
    for (int i = (1), i_end_ = (n); i <= i_end_; ++i) sum += str[i] - 'a';
    printf("%d\n", dp[n][sum]);
  }
  return EXIT_SUCCESS;
}
