#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    string a;
    string b;
    cin >> a;
    cin >> b;
    long long int ans = 0;
    map<char, int> m;
    for (int i = 0; i < n / 2; i++) {
      m.clear();
      map<char, int>::iterator it;
      m[a[i]] = 1;
      if (m.find(b[i]) == m.end()) {
        m[b[i]] = 1;
      } else {
        m[b[i]]++;
      }
      if (m.find(b[n - i - 1]) == m.end()) {
        m[b[n - i - 1]] = 1;
      } else {
        m[b[n - i - 1]]++;
      }
      if (m.find(a[n - i - 1]) == m.end()) {
        m[a[n - i - 1]] = 1;
      } else {
        m[a[n - i - 1]]++;
      }
      it = m.begin();
      if (m.size() == 4) {
        ans += 2;
      } else if (m.size() == 3) {
        if (a[i] == a[n - i - 1]) {
          ans += 2;
        } else {
          ans++;
        }
      } else if (m.size() == 2) {
        if (it->second == 3 || it->second == 1) {
          ans++;
        }
      }
    }
    if (n % 2 != 0) {
      if (a[n / 2] != b[n / 2]) ans++;
    }
    cout << ans;
  }
  return 0;
}
