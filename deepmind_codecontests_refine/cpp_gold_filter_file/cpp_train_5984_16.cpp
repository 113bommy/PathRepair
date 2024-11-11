#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 5e6 + 5;
const long long INF = 9e18;
const int M = 3e3 + 5;
long long cnt[M], res = 0;
int main() {
  string s;
  cin >> s;
  for (int i = 0; s[i]; ++i) {
    cnt[s[i]]++;
  }
  for (int i = 0; i < 256; ++i) {
    res += cnt[i] * 1ll * cnt[i];
  }
  cout << res;
  return 0;
}
