#include <bits/stdc++.h>
using namespace std;
int di[] = {0, 0, 0, -1, 1}, dj[] = {0, 1, -1, 0, 0};
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int main() {
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int j = 0;
  for (char c = 'z'; c >= 'a'; c--) {
    int i = j;
    for (i = j; i < (int)s.size(); i++) {
      if (s[i] == c) {
        j++;
        cout << s[i];
      }
    }
  }
  return 0;
}
