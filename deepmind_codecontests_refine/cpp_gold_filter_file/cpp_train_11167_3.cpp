#include <bits/stdc++.h>
using namespace std;
void test_case() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  for (int i = 0; i < k; i++) {
    bool one = false;
    bool zero = false;
    for (int j = i; j < n; j += k) {
      if (s[j] == '1') {
        one = true;
      } else if (s[j] == '0') {
        zero = true;
      }
    }
    if (one && zero) {
      cout << "NO" << endl;
      return;
    }
    for (int j = i; j < n; j += k) {
      if (s[j] == '?') {
        if (one) {
          s[j] = '1';
        } else if (zero) {
          s[j] = '0';
        }
      }
    }
  }
  int one = 0;
  int zero = 0;
  int emp = 0;
  for (int i = 0; i < k; i++) {
    if (s[i] == '1') {
      one++;
    } else if (s[i] == '0') {
      zero++;
    }
  }
  if (max(one, zero) > k / 2) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    test_case();
  }
  return 0;
}
