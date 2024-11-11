#include <bits/stdc++.h>
using namespace std;
int n, res;
string s;
map<char, int> cnt;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    cnt[s[0]]++;
  }
  for (char c = 'a'; c <= 'z'; c++) {
    int p1 = cnt[c] / 2, p2 = cnt[c] - p1;
    res = res + p1 * (p1 - 1) / 2 + p2 * (p2 - 1) / 2;
  }
  cout << res;
  return 0;
}
