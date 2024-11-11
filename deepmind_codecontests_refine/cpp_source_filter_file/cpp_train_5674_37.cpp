#include <bits/stdc++.h>
using namespace std;
const long long prime = 1e9 + 7;
const long long maxN = 1e4 + 5;
const long double pi = 3.1415926536;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, vote[101], win[101], a, cnt[101], ans = 1, vmax = 0;
  for (long long i = (long long)(1); i <= (long long)(100); i++) {
    vote[i] = 1;
    win[i] = 1;
    cnt[i] = 1;
  }
  cin >> n >> m;
  for (long long i = (long long)(1); i <= (long long)(m); i++) {
    for (long long j = (long long)(1); j <= (long long)(n); j++) {
      cin >> a;
      if (a > vote[i]) {
        vote[i] = a;
        win[i] = j;
      }
    }
  }
  for (long long i = (long long)(1); i <= (long long)(m); i++) {
    cnt[win[i]]++;
  }
  for (long long i = (long long)(1); i <= (long long)(n); i++) {
    if (cnt[i] > vmax) {
      vmax = cnt[i];
      ans = i;
    }
  }
  cout << ans;
  return 0;
}
