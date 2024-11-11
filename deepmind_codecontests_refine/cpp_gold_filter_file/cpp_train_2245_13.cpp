#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  long long i = S.find('G');
  long long j = S.find('T');
  string ans = "NO";
  if (i < j) {
    long long idx = i;
    while (idx < N) {
      idx = idx + K;
      if (S[idx] == 'T') {
        ans = "YES";
        break;
      } else if (S[idx] == '#') {
        ans = "NO";
        break;
      } else if (S[idx] == '.') {
        continue;
      }
    }
  } else {
    long long idx = i;
    while (idx >= 0) {
      idx -= K;
      if (S[idx] == 'T') {
        ans = "YES";
        break;
      } else if (S[idx] == '#') {
        ans = "NO";
        break;
      } else if (S[idx] == '.') {
        continue;
      }
    }
  }
  cout << ans << "\n";
}
