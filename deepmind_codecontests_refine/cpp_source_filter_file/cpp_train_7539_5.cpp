#include <bits/stdc++.h>
using namespace std;
long a[1000], b[1000];
int main() {
  ios_base::sync_with_stdio(false);
  string s1, s2;
  cin >> s1 >> s2;
  for (char c = 'a'; c <= 'z'; c++) {
    a[c] = 0;
    b[c] = 0;
  }
  for (long i = 0; i < s1.length(); i++) a[s1[i]]++;
  long long ans = 1;
  for (long i = 0; i < s2.length(); i++) b[s2[i]]++;
  for (char c = 'a'; c <= 'z'; c++) {
    if (b[c] > 0 && a[c] == 0) {
      cout << -1;
      return 0;
    }
    if (b[c] > 0 && a[c] > 0) ans *= min(b[c], a[c]);
  }
  cout << ans;
}
