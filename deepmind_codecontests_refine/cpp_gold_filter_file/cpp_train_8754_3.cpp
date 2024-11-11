#include <bits/stdc++.h>
using namespace std;
long long n;
int k, i;
bool query(long long x, long long y) {
  cout << x << ' ' << y << '\n';
  fflush(stdout);
  string ans;
  cin >> ans;
  if (ans == "Yes")
    return 1;
  else if (ans == "No")
    return 0;
  assert(ans != "Bad");
}
int randd() { return rand() ^ rand() ^ rand(); }
void solve(long long l, long long r) {
  l = max(l, (long long)1);
  r = min(r, n);
  long long mid = (l + r) / 2;
  if (mid - l + 2 * k + 3 >= r - l) {
    long long x = l + randd() % (r - l + 1);
    if (!query(x, x)) solve(l - k, r + k);
    return;
  }
  if (query(l, mid))
    solve(l - k, mid + k);
  else
    solve(mid - k, r + k);
}
int main() {
  cin.sync_with_stdio(false);
  cin >> n >> k;
  srand(time(0));
  solve(1, n);
  return 0;
}
