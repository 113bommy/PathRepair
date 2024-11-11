#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long a[26] = {0};
    long long cnt = 0;
    for (long long i = 0; i < s.size(); i++) {
      a[s[i] - 97]++;
    }
    for (long long i = 0; i < 26; i++) {
      if (a[i] <= 2)
        cnt += a[i];
      else
        cnt += 2;
    }
    cout << cnt / 2 << "\n";
  }
  return 0;
}
