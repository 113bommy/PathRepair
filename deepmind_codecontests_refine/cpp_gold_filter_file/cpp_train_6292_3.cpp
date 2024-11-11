#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int t = 1;
  while (t--) {
    string s;
    long long int k;
    cin >> s >> k;
    long long int n = s.size();
    for (long long int i = 0; i < n; i++) {
      long long int idx = i, hi = s[i];
      for (long long int j = i + 1; j <= min(n - 1, i + k); j++) {
        if (hi < s[j]) {
          idx = j;
          hi = s[j];
        }
      }
      long long int temp = s[idx];
      for (long long int j = idx - 1; j >= i; j--) {
        s[j + 1] = s[j];
      }
      s[i] = temp;
      k -= (idx - i);
    }
    cout << s << endl;
  }
}
