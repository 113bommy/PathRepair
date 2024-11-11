#include <bits/stdc++.h>
using namespace std;
const long long M = 3 * (1e5) + 7, mod = 1e9 + 7;
string f0 =
    "What are you doing at the end of the world? Are you busy? Will you save "
    "us?";
string s0 = "What are you doing while sending \"";
string s1 = "\"? Are you busy? Will you send \"";
string s3 = "\"?";
long long S[M];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  S[0] = f0.size();
  for (long long i = 1; i <= 10 + 1; i++) {
    S[i] = s0.size() + S[i - 1] + s1.size() + S[i - 1] + s3.size();
    S[i] = min(S[i], (long long)1e18);
  }
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n, k;
    cin >> n >> k;
    if (k > S[n]) {
      cout << '.';
      continue;
    } else
      k--;
    while (1) {
      if (n == 0) {
        cout << f0[k];
        break;
      }
      if (k < s0.size()) {
        cout << s0[k];
        break;
      } else
        k -= s0.size();
      if (k < S[n - 1]) {
        n--;
        continue;
      } else
        k -= S[n - 1];
      if (k < s1.size()) {
        cout << s1[k];
        break;
      } else
        k -= s1.size();
      if (k < S[n - 1]) {
        n--;
        continue;
      } else
        k -= S[n - 1];
      cout << s3[k];
      break;
    }
  }
  return 0;
}
