#include <bits/stdc++.h>
using namespace std;
long long M = 1e9 + 7;
vector<long long> a;
void make_nums(long long n) {
  if (n >= 1000000000) return;
  a.push_back(n);
  make_nums(n * 10 + 4);
  make_nums(n * 10 + 7);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cerr.tie(0);
  make_nums(0);
  sort(a.begin(), a.end());
  long long l, r;
  cin >> l >> r;
  long long ans = 0, prev = l;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] < l) continue;
    ans += (min(r, a[i]) - prev + 1) * a[i];
    prev = min(r, a[i]) + 1;
    if (prev > r) break;
  }
  cout << ans;
  return 0;
}
