#include <bits/stdc++.h>
using namespace std;
int H, M, K;
int NonZeroDigit(int x) {
  int res;
  while (x) {
    if (x % 10) res++;
    x /= 10;
  }
  return res;
}
int Get(int x, int p) {
  for (int i = 1; i < p; ++i) x /= 10;
  return x;
}
long long Solve(int h, int m) {
  int d = NonZeroDigit(M - 1);
  long long res = Get(h, K - d);
  res += (long long)Get(m, K) + (long long)h * Get(M - 1, K);
  return res;
}
int main() {
  cin >> H >> M >> K;
  int h1, m1, h2, m2;
  cin >> h1 >> m1 >> h2 >> m2;
  if (pair<int, int>(h1, m1) <= pair<int, int>(h2, m2))
    cout << Solve(h2, m2) - Solve(h1, m1) << endl;
  else
    cout << Solve(H - 1, M - 1) - Solve(h1, m1) +
                (NonZeroDigit(H - 1) + NonZeroDigit(M - 1) >= K) + Solve(h2, m2)
         << endl;
  return 0;
}
