#include <bits/stdc++.h>
using namespace std;
void Solve() {
  int n;
  string s;
  cin >> n >> s;
  for (int i = 1; i < n; ++i) {
    if (s[i - 1] > s[i]) {
      for (int j = 0; j < n; ++j) {
        if (j != i - 1) {
          cout << s[j];
        }
      }
      return;
    }
  }
  for (int i = 0; i < n - 1; ++i) {
    cout << s[i];
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solve();
}
