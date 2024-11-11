#include <bits/stdc++.h>
using namespace std;
const long long N = 100100;
long long Rec(long long i);
void max_self(long long& x, long long y) { x = max(x, y); }
vector<long long> D;
long long Dp[N];
int main() {
  memset(Dp, -1, sizeof(Dp));
  long long n;
  cin >> n;
  for (long long i = 1; i * i <= n; i++)
    if (n % i == 0) {
      D.push_back(i);
      if (i * i != n) D.push_back(n / i);
    }
  sort(D.begin(), D.end());
  cout << Rec(D.size() - 1);
}
long long Rec(long long i) {
  if (i == 0) return 1;
  if (Dp[i] + 1) return Dp[i];
  long long Res = 0;
  for (long long j = 0; j < i; j++)
    if (D[i] % D[j] == 0) max_self(Res, D[i] + Rec(j));
  return Dp[i] = Res;
}
