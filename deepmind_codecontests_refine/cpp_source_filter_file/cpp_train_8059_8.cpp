#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize "Ofast"
#pragma GCC optimize "fast-math"
#pragma GCC optimize "no-stack-protector"
long long INF = (long long)1e20;
int iINF = (int)1e20;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k, w;
  cin >> n >> k >> w;
  string s;
  cin >> s;
  if (k == 1) {
    long long pref_s[n];
    pref_s[0] = (s[0] == '1');
    for (int i = 1; i < n; ++i) {
      pref_s[i] = pref_s[i - 1] + (s[i] == 1);
    }
    for (int i = 0; i < w; ++i) {
      long long l, r;
      cin >> l >> r;
      --l;
      --r;
      if (l != 0) {
        cout << (r - l + 1) - pref_s[r] + pref_s[l - 1] << '\n';
      } else {
        cout << (r - l + 1) - pref_s[r] << '\n';
      }
    }
    return 0;
  }
  long long pref[k][n];
  for (int i = 0; i < k; ++i) {
    long long tmp = 0;
    tmp = (s[i] == '0');
    pref[i][i] = tmp;
    for (int j = i + 1; j < n; ++j) {
      if ((j - i + 1) % k == 0) {
        if (s[j] == '0') tmp++;
      } else {
        if (s[j] == '1') tmp++;
      }
      pref[i][j] = tmp;
    }
  }
  for (int i = 0; i < w; ++i) {
    long long l, r;
    cin >> l >> r;
    --l;
    --r;
    long long del = l % k;
    cout << pref[del][r] - pref[del][l] + (s[l] == '1') << '\n';
  }
}
