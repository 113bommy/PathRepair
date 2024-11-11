#include <bits/stdc++.h>
using namespace std;
long long N, M;
long long C[100005], dp[100005][2];
long long F(long long x, long long t) {
  if (x == 100000 + 1) return 0;
  long long &ret = dp[x][t];
  if (ret != -1) return ret;
  if (!t) return ret = F(x + 1, 1);
  return ret = max(F(x + 1, 0) + C[x] * x, F(x + 1, 1));
}
void read() {
  long long x;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> x;
    C[x]++;
  }
  memset(dp, -1, sizeof dp);
  cout << F(0, 0) << endl;
}
int main() {
  read();
  return 0;
}
