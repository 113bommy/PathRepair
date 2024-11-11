#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
char s[N];
void solve() {
  int l = 1;
  bool last = s[0] == '1';
  for (int i = 1; i < n; ++i) {
    bool t = s[i] == '1';
    if (t == !last) {
      last ^= true;
      l++;
    }
  }
  bool find = false;
  last = s[0] == '1';
  for (int i = 1; i < n; ++i) {
    bool t = s[i] == '1';
    if (t == last) {
      int j = i + 1;
      while (j < n - 1 && s[j] != s[j + 1]) {
        j++;
      }
      i = j - 1;
      find = true;
      if (i + 1 >= n) continue;
      if (s[j] == s[j + 1]) {
        cout << l + 2 << '\n';
        return;
      }
    } else
      last ^= true;
  }
  cout << l + find << '\n';
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> s[i];
  solve();
  return 0;
}
