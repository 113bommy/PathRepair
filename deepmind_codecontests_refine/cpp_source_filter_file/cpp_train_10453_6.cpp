#include <bits/stdc++.h>
using namespace std;
long long int dp[100010];
long long int dp2[100010];
int main() {
  int n, l, r, Ql, Qr;
  cin >> n >> l >> r >> Ql >> Qr;
  vector<long long int> v;
  for (int i = (int)0; i < (int)n; ++i) {
    long long int x;
    cin >> x;
    v.push_back(x);
  }
  dp[0] = v[0];
  dp2[n - 1] = v[n - 1];
  for (int i = (int)1; i < (int)n; ++i) {
    dp[i] = dp[i - 1] + v[i];
  }
  for (int i = n - 2; i >= 0; i--) {
    dp2[i] = dp2[i + 1] + v[i];
  }
  long long int m = 1000000000;
  for (int i = (int)0; i < (int)n - 1; ++i) {
    int left = i + 1;
    int right = n - i - 1;
    long long int s = 0;
    if (left < right) {
      s = dp[i] * l;
      s += dp2[i + 1] * r;
      s += (Qr * (right - left - 1));
      m = min(m, s);
    } else if (left > right) {
      s = dp[i] * l;
      s += dp2[i + 1] * r;
      s += (Ql * (left - right - 1));
      m = min(m, s);
    } else {
      s = dp[i] * l;
      s += dp2[i + 1] * r;
      m = min(m, s);
    }
  }
  long long int s1 = dp2[0] * r;
  s1 += (Qr * (n - 1));
  m = min(m, s1);
  long long int s2 = dp[n - 1] * l;
  s1 += (Ql * (n - 1));
  m = min(m, s2);
  cout << m << endl;
  return 0;
}
