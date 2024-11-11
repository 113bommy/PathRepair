#include <bits/stdc++.h>
using namespace std;
long long H, n;
vector<long long> d;
vector<long long> psum;
long long BS(long long sum, long long total) {
  long long ret = 1LL << 62;
  long long st = 0, en = H / total + 10, mid = 0;
  while (st < en) {
    mid = (st + en) / 2;
    if (sum + mid * total <= -H) {
      ret = min(ret, mid);
      en = mid;
    } else {
      st = mid + 1;
    }
  }
  return ret;
}
void process() {
  cin >> H >> n;
  d.resize(n + 1);
  psum.resize(n + 1);
  for (int i = 1; i < n + 1; i++) cin >> d[i];
  for (int i = 1; i < n + 1; i++) {
    psum[i] = psum[i - 1] + d[i];
    if (psum[i] * -1 >= H) {
      cout << i << '\n';
      return;
    }
  }
  long long ans = 1LL << 62;
  long long total = psum[n];
  if (total >= 0) {
    cout << "-1\n";
    return;
  }
  for (int i = 1; i < n + 1; i++) {
    long long K = BS(psum[i], total);
    if (K * n + i < ans) ans = K * n + i;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  process();
  return 0;
}
