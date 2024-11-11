#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, P;
  string S;
  cin >> N >> P >> S;
  int res = 0;
  if (P == 2 || P == 5) {
    for (int i = 0; i < N; i++) {
      if ((S[i] - '0') % P == 0) res += i + 1;
    }
  } else {
    map<int, int> mp;
    mp[0]++;
    int cur = 0, b = 1;
    reverse(S.begin(), S.end());
    for (int i = 0; i < N; i++) {
      cur += b * (S[i] - '0');
      cur %= P;
      b *= 10;
      b %= P;
      res += mp[cur]++;
    }
  }
  cout << res << '\n';
  return 0;
}
