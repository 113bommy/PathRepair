#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  long long int n, k;
  cin >> n >> k >> s;
  string ans = s;
  long long int shift = n;
  for (long long int j = 1; j < n; j++) {
    bool matched = true;
    for (long long int i = j; i < n; i++) {
      if (s[i - j] != s[j]) {
        matched = false;
        break;
      }
    }
    if (matched) {
      shift = j;
      break;
    }
  }
  cout << s;
  for (long long int i = 0; i < k - 1; i++) cout << s.substr(n - shift, shift);
  return 0;
}
