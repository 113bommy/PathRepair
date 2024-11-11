#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
long long google_itr = 1;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
void virus() {
  long long len, k;
  cin >> len >> k;
  string seq;
  cin >> seq;
  long long zero = 0, one = 0;
  for (auto i = 0; i < k; i++) {
    long long enc = -1;
    for (auto j = 0; j < len; j += k) {
      if (seq[j] != '?') {
        if (enc != -1 and seq[j] - '0' != enc) {
          cout << "NO\n";
          return;
        }
        enc = seq[j] - '0';
      }
    }
    if (enc != -1) (enc == 0) ? zero++ : one++;
  }
  if (one > (k / 2) or zero > (k / 2)) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    auto start = high_resolution_clock::now();
    virus();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
  }
  return 0;
}
