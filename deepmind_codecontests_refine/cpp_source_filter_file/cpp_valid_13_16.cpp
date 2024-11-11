#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
using namespace std;
void test_case() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<char>> table(n, vector<char>(m, '0'));
  int horizontal = 0;
  if (n % 2 == 1) horizontal = m / 2;
  int max_h = n * (m / 2);
  if (max_h < k)
    cout << "NO\n";
  else if (k >= horizontal && (k - horizontal) % 2 == 0) {
    cout << "YES\n";
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < n / 2; i++) {
      for (int j = 0; j < m; j++) {
        table[2 * i][j] = alphabet[(j + 2 * i) % 26];
        table[2 * i + 1][j] = alphabet[(j + 2 * i) % 26];
      }
    }
    for (int j = 0; j < horizontal / 2; j++) {
      table[n - 1][j * 2] = alphabet[(n + j * 2) % 26];
      table[n - 1][j * 2 + 1] = alphabet[(n + j * 2) % 26];
    }
    int delta = k - horizontal;
    int s = 0, e = 0;
    while (delta) {
      delta -= 2;
      table[s * 2][e * 2 + 1] = table[s * 2][e * 2];
      table[s * 2 + 1][e * 2] = table[s * 2 + 1][e * 2 + 1];
      e++;
      if (e == m / 2) {
        s++;
        e = 0;
      }
    }
    for (auto v : table) {
      for (auto u : v) cout << u;
      cout << '\n';
    }
  } else
    cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  while (N--) {
    test_case();
  }
}
