#include <bits/stdc++.h>
using namespace std;
int testCases, testNum;
int SX, SY;
void solve() {
  int p, q;
  scanf("%d", &p);
  scanf("%d", &q);
  long long N = p, M = q;
  long long ans = 0;
  for (long long b = 2; b <= N; b++) {
    ans += min(b * b - 1, M);
    if (b * b <= M)
      ans -= (b - 1);
    else {
      long long left = ceil(sqrt(b * b - M));
      long long sub = (b - 1) - (left - 1);
      ans -= sub;
    }
  }
  ans *= 2;
  ans += (min(2 * N - 1, M) + 1) / 2;
  ans += min(2 * N - 2, M / 2) / 2;
  cout << ans << endl;
}
bool input() { return true; }
int main() {
  testCases = 1;
  for (testNum = 1; testNum <= testCases; testNum++) {
    if (!input()) break;
    solve();
  }
}
