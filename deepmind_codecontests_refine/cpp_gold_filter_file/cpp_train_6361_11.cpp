#include <bits/stdc++.h>
using namespace std;
long long n, k, mv;
string query(long long l, long long r) {
  assert(mv < 4400);
  ++mv;
  string res;
  cout << l << ' ' << r << '\n';
  fflush(stdout);
  cin >> res;
  return res;
}
void f(long long l, long long r) {
  if ((r - l + 1) < 100) {
    long long x = (rand() % (r - l + 1)) + l;
    if (query(x, x) == "Yes") exit(0);
    f(max(1ll, l - k), min(n, r + k));
  }
  long long mid = l + r >> 1;
  if (query(l, mid) == "Yes")
    f(max(1ll, l - k), min(n, mid + k));
  else
    f(max(1ll, mid - k), min(n, r + k));
}
signed main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  srand(time(NULL));
  f(1, n);
  return 0;
}
