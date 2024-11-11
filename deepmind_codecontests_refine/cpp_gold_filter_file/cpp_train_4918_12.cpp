#include <bits/stdc++.h>
using namespace std;
void solve(int n, int a, int b) {
  string res = "";
  char c = 'a';
  for (int i = 0; i < n; i++) {
    res.push_back(c);
    c = (c + 1);
    if ((i + 1) % b == 0) {
      c = 'a';
    }
  }
  cout << res << "\n";
}
int main() {
  int t, n, a, b;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> a >> b;
    solve(n, a, b);
  }
}
