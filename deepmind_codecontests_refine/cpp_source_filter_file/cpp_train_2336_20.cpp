#include <bits/stdc++.h>
using namespace std;
long long int dp[1 << 20];
int Xi[100], Ki[100], Mi[100], Si[100];
int Ii[100];
bool cmp(int x, int y) { return Ki[x] < Ki[y]; }
int main() {
  int N, M, B;
  cin >> N >> M >> B;
  for (int i = 0; i < N; i++) {
    cin >> Xi[i] >> Ki[i] >> Mi[i];
    for (int j = 0; j < Mi[i]; j++) {
      int x;
      cin >> x;
      x--;
      Si[i] |= (1 << x);
    }
    Ii[i] = i;
  }
  sort(Ii, Ii + N);
  for (int i = 1; i < (1 << M); i++) dp[i] = 1LL << 60;
  dp[Si[Ii[0]]] = Xi[Ii[0]];
  int mask = (1 << M) - 1;
  long long int mincost = min(1LL << 60, dp[mask] + Ki[Ii[0]] * (long long)B);
  for (int i = 1; i < N; i++) {
    for (int j = mask; j >= 0; j--)
      if (dp[j] != 1LL << 60)
        dp[j | Si[Ii[i]]] = min(dp[j | Si[Ii[i]]], dp[j] + Xi[Ii[i]]);
    mincost = min(mincost, dp[mask] + Ki[Ii[i]] * (long long)B);
  }
  if (mincost >= 1LL << 60)
    cout << -1 << endl;
  else
    cout << mincost << endl;
  return 0;
}
