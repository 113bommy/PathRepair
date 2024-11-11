#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string a = s.substr(0, n);
  string b = s.substr(n, n);
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  if (a[0] > b[0]) {
    for (int i = 1; i < n; i++) {
      if (a[i] <= b[i]) {
        cout << "NO";
        return;
      }
    }
  } else if (a[0] < b[0]) {
    for (int i = 1; i < n; i++) {
      if (a[i] >= b[i]) {
        cout << "NO";
        return;
      }
    }
  } else if (a[0] == b[0]) {
    cout << "NO";
    return;
  }
  cout << "YES";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
