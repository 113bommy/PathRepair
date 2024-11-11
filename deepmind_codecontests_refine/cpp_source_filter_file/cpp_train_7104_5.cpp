#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if (b & 1) {
    for (int i = 0; i < c; i++) cout << "1";
    for (int i = 0; i < (b + 1) / 2; i++) cout << "10";
    for (int i = 0; i < a; i++) cout << "0";
    cout << '\n';
  } else if (b == 0) {
    if (a)
      for (int i = 0; i < a + 1; i++) cout << "0";
    if (c)
      for (int i = 0; i < c + 1; i++) cout << "1";
    cout << '\n';
  } else {
    if (c) {
      cout << "01";
      for (int i = 0; i < c - 1; i++) cout << "1";
      b--;
      for (int i = 0; i < (b + 1) / 2; i++) cout << "10";
      for (int i = 0; i < a; i++) cout << "0";
      cout << '\n';
    } else if (a) {
      cout << "10";
      for (int i = 0; i < a - 1; i++) cout << "0";
      b--;
      for (int i = 0; i < (b + 1) / 2; i++) cout << "01";
      for (int i = 0; i < c; i++) cout << "1";
      cout << '\n';
    } else {
      for (int i = 0; i < b - 1; i++) cout << "10";
      cout << "1\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
