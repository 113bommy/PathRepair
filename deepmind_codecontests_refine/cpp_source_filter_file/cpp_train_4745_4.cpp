#include <bits/stdc++.h>
using namespace std;
long long N, L, R;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
vector<long long> candi;
int main() {
  cin >> N >> L >> R;
  if (N == 1) {
    cout << R - L + 1;
  } else if (N == 2) {
    cout << (R - L + 1) * (R - L);
  } else if (N > 23) {
    cout << 0;
  } else {
    for (int i = 1;; i++) {
      long long ret = 1;
      for (int j = 1; j <= N - 1; j++) {
        ret *= (long long)i;
      }
      if (ret > R) break;
      candi.push_back(ret);
    }
    long long ans = 0;
    for (int i = 0; i < candi.size(); i++) {
      for (int j = i + 1; j < candi.size(); j++) {
        if (gcd(candi[j], candi[i]) == 1) {
          ans += max(0LL, R / candi[j] - (L - 1) / candi[i]);
        }
      }
    }
    ans *= 2;
    cout << ans;
  }
  return 0;
}
