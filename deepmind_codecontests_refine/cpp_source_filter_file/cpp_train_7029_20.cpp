#include <bits/stdc++.h>
using namespace std;
int diff(string a, string s) {
  int d = 0;
  for (int i = 0; i < 6; i++) {
    if (a[i] != s[i]) d++;
  }
  return d;
}
int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = 1000;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ans = min(ans, diff(a[i], a[j]));
    }
  }
  cout << (ans - 1) / 2 << endl;
  return 0;
}
