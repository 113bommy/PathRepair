#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string a = "abcd";
  string b = "";
  for (int i = 0; i < n; i++) {
    b += a[i % 4];
  }
  cout << b << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  long long T;
  T = 1;
  for (int t = 0; t < T; t++) {
    solve();
  }
  return 0;
}
