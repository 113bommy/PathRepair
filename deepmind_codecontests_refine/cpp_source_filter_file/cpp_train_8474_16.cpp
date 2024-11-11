#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
long long int cnt[N];
long long int pSum[N];
int main() {
  ios_base::sync_with_stdio(0);
  long long int a;
  cin >> a;
  string s;
  cin >> s;
  int n = s.length();
  for (int i = 0; i < n; ++i) {
    pSum[i + 1] = (s[i] - '0') + pSum[i];
    for (int j = 0; j <= i; ++j) {
      cnt[pSum[i + 1] - pSum[j]]++;
    }
  }
  long long int ans = 0;
  for (int l = 1; l <= n; ++l) {
    for (int r = l; r <= n; ++r) {
      long long int vSum = pSum[r] - pSum[l - 1];
      if (vSum == 0) {
        if (a == 0) {
          ans += (n * (n - 1)) / 2;
        } else
          continue;
      } else if (a % vSum == 0 && (a / vSum) <= pSum[n]) {
        ans += cnt[a / vSum];
      }
    }
  }
  cout << ans;
  return 0;
}
