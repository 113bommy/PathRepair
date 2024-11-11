#include <bits/stdc++.h>
using namespace std;
long long n;
string s, p;
long long bin[34][34];
void read() {
  cin >> n;
  for (int i = 0; i <= 30; i++) {
    bin[i][0] = bin[i][i] = 1;
    for (int j = 1; j < i; j++) {
      bin[i][j] = bin[i - 1][j - 1] + bin[i - 1][j];
    }
  }
}
void solve() {
  string res = "";
  for (int i = 30; i >= 9; i--) {
    while (n >= bin[i][9]) {
      n -= bin[i][9];
      res += "b";
    }
    res += "a";
  }
  cout << "aaaaaaaa";
  for (int i = res.length() - 1; i >= 0; i--) cout << res[i];
  cout << " aaaaaaaaab\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  read();
  solve();
  return 0;
}
