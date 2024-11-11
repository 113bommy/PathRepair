#include <bits/stdc++.h>
using namespace std;
const int N = 1400000000;
const int M = 1e7;
int arr[M];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  for (int t = 0; t < m; t++) {
    int l, r;
    char c1, c2;
    cin >> l >> r >> c1 >> c2;
    if (l == r) {
      if (s[l - 1] == c1) s[l - 1] = c2;
    } else {
      for (int i = l - 1; i <= r - 1; i++) {
        if (s[i] == c1) s[i] = c2;
      }
    }
  }
  cout << s;
  return 0;
}
