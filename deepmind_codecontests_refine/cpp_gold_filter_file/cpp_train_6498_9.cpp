#include <bits/stdc++.h>
using namespace std;
void usaco(string s) { freopen((s + ".out").c_str(), "w", stdout); }
int absolute(int a, int b) { return max(a, b) - min(a, b); }
const long long INF = -10e9 - 3;
const long long MAX = 10e9 + 3;
char matrix[25][25];
long long absolute(long long p) { return max(p, p * (-1)); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  int n = int((s).size());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int j = i + 3;
    while (j < n && (s[j] != 'r' || s[j - 1] != 'a' || s[j - 2] != 'e' ||
                     s[j - 3] != 'b'))
      j++;
    if (n - j <= 0) break;
    ans += (n - j);
  }
  cout << ans << "\n";
  return 0;
}
