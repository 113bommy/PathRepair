#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e5 + 6;
const int MOD = (int)1e9 + 7;
void solve() {
  string bb1 = "BWBWBWBW";
  string bb2 = "WBWBWBWB";
  int n = 8;
  while (n--) {
    string s;
    cin >> s;
    if (s != bb1 && s != bb2) {
      cout << "NO";
      return;
    }
  }
  cout << "YES";
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
