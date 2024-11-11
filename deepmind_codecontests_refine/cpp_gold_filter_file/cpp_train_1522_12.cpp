#include <bits/stdc++.h>
using namespace std;
const int border = 10003;
int a, b, k;
void read() { cin >> a >> b >> k; }
bool is_prime(int x) {
  if (x == 0 || x == 1) return false;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return false;
  return true;
}
long long ans;
vector<int> plk;
int sz;
void rec(int pos, int cnt, long long curr) {
  if (curr > b) return;
  if (pos == sz) {
    int first, last;
    if (a % curr == 0)
      first = a;
    else
      first = a + curr - a % curr;
    last = b - b % curr;
    if (cnt % 2 == 0)
      ans += max(0ll, (last - first) / curr + 1);
    else
      ans -= max(0ll, (last - first) / curr + 1);
    return;
  }
  rec(pos + 1, cnt, curr);
  rec(pos + 1, cnt + 1, curr * plk[pos]);
}
int lcp(int x) {
  if (x == 1) return INT_MAX;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return i;
  return x;
}
void solve() {
  if (!is_prime(k)) {
    cout << 0 << endl;
    return;
  }
  if (k <= border) {
    for (int i = 1; i <= k - 1; i++)
      if (is_prime(i)) plk.push_back(i);
    sz = plk.size();
    rec(0, 0, k);
    cout << ans << endl;
  } else {
    int first, last;
    if (a % k == 0)
      first = a;
    else
      first = a + k - a % k;
    last = b - b % k;
    for (long long i = first; i <= last; i += k)
      if (lcp(i / k) >= k) ans++;
    cout << ans << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  read();
  solve();
}
