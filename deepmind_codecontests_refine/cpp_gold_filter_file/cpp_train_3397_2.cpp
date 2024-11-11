#include <bits/stdc++.h>
using namespace std;
bool isvowel(char c) {
  c = tolower(c);
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long fastpow(long long base, long long p) {
  if (p == 0) return 1;
  long long num = fastpow(base, p / 2);
  num *= num;
  if (p % 2) num *= base;
  return num;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, m, x, q, ans = 0;
  cin >> n >> m >> x;
  string KeyBoard[n + 5], t;
  map<char, bool> check;
  vector<pair<int, int>> S;
  for (int i = 1; i <= n; i++) {
    cin >> KeyBoard[i];
    for (int j = 0; j < m; j++) {
      if (KeyBoard[i][j] == 'S') S.push_back(make_pair(i, j + 1));
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      if (KeyBoard[i][j] == 'S') continue;
      check[KeyBoard[i][j]] = true;
      for (int k = 0; k < (int)S.size(); k++) {
        if (sqrt(pow(i - S[k].first, 2) + pow(j - S[k].second + 1, 2)) <= x) {
          check[toupper(KeyBoard[i][j])] = true;
          break;
        }
      }
    }
  }
  cin >> q >> t;
  for (int i = 0; i < (int)t.size(); i++) {
    if (!check[t[i]]) {
      if (islower(t[i]) || !check[tolower(t[i])] || !S.size()) {
        cout << -1;
        return 0;
      }
      ans++;
    }
  }
  cout << ans;
  return 0;
}
