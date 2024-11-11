#include <bits/stdc++.h>
using namespace std;
const long long INF = 1.1e18;
long long mul(long long a, long long b) {
  if (a == 0 || b == 0) return 0;
  if (INF / a > b) {
    return a * b;
  } else {
    return INF;
  }
}
int main() {
  long long N;
  cin >> N;
  vector<long long> ans;
  for (int d = 0; (1LL << d) <= N + 1; ++d) {
    long long coef = (1LL << d) - 1;
    long long a = 2;
    long long b = (1 + 2 * coef);
    long long c = coef;
    long long left = -1;
    long long right = N + 1;
    while (right - left > 1) {
      long long mid = (right + left) / 2;
      long long fun = mul(mid, mul(a, mid) + b) + c;
      if (fun == N) {
        ans.push_back((2 * mid + 1) * (1LL << d));
        break;
      } else if (fun > N) {
        right = mid;
      } else {
        left = mid;
      }
    }
  }
  int kk = 0;
  sort(ans.begin(), ans.end());
  if (ans.empty()) {
    cout << "-1" << endl;
  } else {
    for (int i = 0; i < ans.size(); ++i) {
      cout << ans[i] << endl;
    }
  }
  return 0;
}
