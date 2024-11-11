#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
string blank = "";
long long A, B;
long long L, T;
long long M;
bool can(long long mid) {
  long long ls = A + (mid - 1) * B;
  long long sum =
      A * (mid - L + 1) + B * (mid * (mid - 1) / 2 - (L - 1) * (L - 2) / 2);
  if (ls > T) return 0;
  return sum <= T * M;
}
void solve() {
  cin >> L >> T >> M;
  long long l = L, r = 2e6, mid;
  bool f = 0;
  while (l < r) {
    mid = l + ((r - l + 1) / 2);
    if (can(mid))
      l = mid, f = 1;
    else
      r = mid - 1;
  }
  if (can(l)) f = 1;
  if (f)
    cout << l;
  else
    cout << -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> A >> B >> n;
  while (n--) {
    solve();
    cout << '\n';
  }
}
