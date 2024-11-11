#include <bits/stdc++.h>
using namespace std;
int fact(int n) {
  int res = 1;
  for (int i = 2; i <= n; i++) res = res * i;
  return res;
}
int nCr(int n, int r) { return fact(n) / (fact(r) * fact(n - r)); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s[n];
    int c[26];
    for (int i = 0; i < 26; i++) c[i] = 0;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      for (int j = 0; j < s[i].length(); j++) {
        c[int(s[i][j] - 'a')]++;
      }
    }
    int k = 1;
    for (int i = 0; i < 26; i++) {
      if (c[i] % n != 0) k = 0;
    }
    if (k)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
