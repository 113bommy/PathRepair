#include <bits/stdc++.h>
using namespace std;
long long pow2[70];
vector<long long> ans;
int main() {
  ios_base::sync_with_stdio(false);
  long long p = 1;
  for (int i = 0; i < 63; ++i) {
    pow2[i] = p;
    p *= 2LL;
  }
  long long n = 0;
  cin >> n;
  for (int i = 0; pow2[i] < 63; ++i) {
    long long left = 1;
    long long right = (1LL << 62);
    while (right > left + 20LL) {
      long long x = left + (right - left) / 2;
      if (n / x < pow2[i] - 2 + (x - 1) / 2)
        right = x - 1;
      else {
        long long value = x * (pow2[i] - 1 + (x - 1) / 2);
        if (value > n)
          right = x - 1;
        else
          left = x - 1;
      }
    }
    for (long long c = left; c <= right; ++c) {
      if ((c % 2) && (c * (pow2[i] - 1 + (c - 1) / 2) == n))
        ans.push_back(c * pow2[i]);
    }
  }
  sort(ans.begin(), ans.end());
  int s = unique(ans.begin(), ans.end()) - ans.begin();
  if (s == 0)
    cout << -1 << endl;
  else
    for (int i = 0; i < s; ++i) cout << ans[i] << "\n";
  return 0;
}
