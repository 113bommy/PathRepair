#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, x;
    cin >> n >> x;
    string a;
    cin >> a;
    long long s[n];
    long long mx = 0, mn = 0;
    for (long long i = 0; i < n; i++) s[i] = 0;
    long long bal = 0;
    for (long long i = 0; i < n; i++) {
      bal = bal + (a[i] == '0') - (a[i] == '1');
      s[i] = bal;
      mx = max(bal, mx);
      mn = min(bal, mn);
    }
    long long ats = x == 0;
    if (bal == 0) {
      if (mn <= bal && bal <= mx) {
        cout << "-1";
      } else
        cout << ats;
      cout << "\n";
      continue;
    }
    for (long long i = 0; i < n; i++) {
      if ((x - s[i]) % bal == 0 && (x - s[i]) / bal >= 0) {
        ats++;
      }
    }
    cout << ats << "\n";
  }
  return 0;
}
