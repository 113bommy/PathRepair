#include <bits/stdc++.h>
using namespace std;
int main() {
  map<string, bool> pw;
  map<string, bool> ew;
  int nc = 0;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string t;
    cin >> t;
    pw[t] = true;
  }
  for (int i = 0; i < m; i++) {
    string t;
    cin >> t;
    ew[t] = true;
    if (pw.find(t) != pw.end()) nc++;
  }
  if (n > m) {
    cout << "YES\n";
    return 0;
  }
  if (m > n) {
    cout << "NO\n";
    return 0;
  }
  if (nc == 0) {
    cout << "NO\n";
    return 0;
  }
  if (nc % 2) {
    cout << "YES\n";
    return 0;
  }
  if (!nc % 2) {
    cout << "NO\n";
    return 0;
  }
}
