#include <bits/stdc++.h>
using namespace std;
int32_t main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long i, j;
  long long n, k;
  cin >> n >> k;
  string s;
  cout << n << "\n";
  cin >> s;
  string x = "";
  for (i = 0; i < s.length(); i++) {
    x += s[i % k];
  }
  if (x >= s)
    cout << x << "\n";
  else {
    for (i = k - 1; i >= 0; i--) {
      if (s[i] != '9') {
        s[i]++;
        for (j = i + 1; j < k; j++) s[j] = 0;
        break;
      }
    }
    for (i = 0; i < s.length(); i++) {
      x[i] = s[i % k];
    }
    cout << x << "\n";
  }
  return 0;
}
