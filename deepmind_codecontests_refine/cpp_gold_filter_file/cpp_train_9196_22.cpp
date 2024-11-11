#include <bits/stdc++.h>
using namespace std;
int n, k;
string ans = "NO";
string s[2];
int w = -1;
bool f[2][100005] = {false};
int rec(int st, int i) {
  w++;
  if (f[st][i]) return 0;
  f[st][i] = true;
  if (i + k >= n) {
    ans = "YES";
    return 0;
  }
  if (s[(st + 1) % 2][i + k] == '-') {
    rec((st + 1) % 2, i + k);
    w--;
  }
  if (i - 1 > w && s[st][i - 1] == '-') {
    rec(st, i - 1);
    w--;
  }
  if (s[st][i + 1] == '-') {
    rec(st, i + 1);
    w--;
  }
  return 0;
}
int main() {
  cin >> n >> k;
  cin >> s[0] >> s[1];
  rec(0, 0);
  cout << ans;
  return 0;
}
