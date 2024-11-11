#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long t;
    cin >> t;
    string s;
    cin >> s;
    bool f = false;
    long long kol = 0;
    while (f != true) {
      long long lastKol = kol;
      vector<bool> fm(t, false);
      bool f1 = false;
      for (long long j = 0; j < t; j++) {
        if (j + 1 < t) {
          if (s[j] == 'A' && s[j + 1] == 'P' && !fm[j]) {
            s[j + 1] = 'A';
            fm[j + 1] = true;
            f1 = true;
          }
        }
      }
      if (f1) kol++;
      if (lastKol == kol) {
        f = true;
      }
    }
    cout << kol;
  }
  return (0);
}
