#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, s[3001], c[3001];
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  long long ans = 1000000000000000;
  for (int j = 1; j < n - 1; j++) {
    long long mi = 1e15;
    for (int i = j - 1; i >= 0; i--) {
      if (s[i] < s[j]) {
        if (mi > c[i]) mi = c[i];
      }
    }
    long long mk = 1e15;
    for (int k = j + 1; k < n; k++) {
      if (s[k] > s[j]) {
        if (mk > c[k]) mk = c[k];
      }
    }
    long long cur = mi + mk + c[j];
    ans = min(ans, cur);
  }
  if (ans == 1000000000000000)
    cout << "-1";
  else
    cout << ans;
  return 0;
}
