#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, M, D;
  cin >> N >> M >> D;
  double x, ans;
  if (D == 0)
    x = N;
  else
    x = (N - D) * 2;
  ans = (x / (N * N)) * (M - 1);
  cout << fixed << setprecision(10) << ans << endl;
}