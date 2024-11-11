#include <bits/stdc++.h>
using namespace std;
const int MAX = 10007;
const int MOD = 1000000007;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  char curr = s[0];
  long long res1 = 0, res2 = 0;
  for (int i = 0; i < n; i++) {
    if ((s[i] - '0' + i) % 2) {
      res1++;
    } else {
      res2++;
    }
  }
  cout << min(res1, res2);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}
