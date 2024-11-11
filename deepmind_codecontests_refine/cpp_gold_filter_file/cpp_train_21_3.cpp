#include <bits/stdc++.h>
using namespace std;
long long n, l, r;
long long num;
vector<long long> ans;
bool intersect(long long l1, long long r1, long long l2, long long r2) {
  return min(r1, r2) >= max(l1, l2);
}
void cal(long long left) {
  if (left == n) return;
  if (intersect(l, r, num + 1, num + 2 * (n - left))) {
    for (long long i = left + 1; i <= n; ++i) {
      num++;
      if (num >= l && num <= r) ans.push_back(left);
      num++;
      if (num >= l && num <= r) ans.push_back(i);
    }
  } else
    num += 2 * (n - left);
  cal(left + 1);
}
int main(void) {
  int t;
  cin >> t;
  while (t--) {
    ans.clear();
    num = 0;
    cin >> n >> l >> r;
    cal(1);
    for (auto x : ans) cout << x << " ";
    if (r == n * (n - 1) + 1) cout << 1 << " ";
    cout << endl;
  }
  return 0;
}
