#include <bits/stdc++.h>
using namespace std;
int N, X, Y;
long long M;
long long getval(int A, int B, int x) {
  if (A == 0 || B == 0) return 0;
  if (x >= A + B - 1) return 1LL * A * B;
  if (x <= min(A, B)) return 1LL * x * (x + 1) / 2;
  if (x > min(A, B) && x <= max(A, B))
    return 1LL * (x - min(A, B)) * min(A, B) +
           1LL * min(A, B) * (min(A, B) + 1) / 2;
  return 1LL * A * B - 1LL * (A + B - 1 - x) * (A + B - x) / 2;
}
bool Test(int x) {
  long long resnow = 1;
  resnow += min(x, X - 1);
  resnow += min(x, N - X);
  resnow += min(x, Y - 1);
  resnow += min(x, N - Y);
  resnow += getval(X - 1, Y - 1, x - 1);
  resnow += getval(X - 1, N - Y, x - 1);
  resnow += getval(N - X, Y - 1, x - 1);
  resnow += getval(N - X, N - Y, x - 1);
  return (resnow < M);
}
int main() {
  cin >> N >> X >> Y >> M;
  if (M == 1) {
    cout << 0 << '\n';
    return 0;
  }
  int step = 1 << 30, result;
  for (result = 0; step; step >>= 1)
    if (result + step <= 2 * N && Test(result + step)) result += step;
  ++result;
  cout << result << '\n';
}
