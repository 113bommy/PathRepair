#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int a[26];
  for (int i = 0; i < 26; i++) {
    a[i] = 0;
  }
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    a[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (k == 0) break;
    if (a[i] < k) {
      k -= a[i];
      a[i] = 0;
    }
    if (a[i] >= k) {
      a[i] = (a[i] - k);
      k = 0;
    }
  }
  string b;
  for (int i = n - 1; i >= 0; i--) {
    if (a[s[i] - 'a'] != 0) {
      b.push_back(s[i]);
      a[s[i] - 'a']--;
    }
  }
  for (int i = b.length() - 1; i >= 0; i--) {
    cout << b[i];
  }
  cout << endl;
}
