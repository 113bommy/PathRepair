#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-15, PI = acos(-1);
const int MOD = int(1e9) + 7, MX = int(1e6) + 1;
void solve() {
  long long msk = 0;
  string s;
  cin >> s;
  int n = int(s.size()), f = 0;
  if (n < 26) {
    puts("-1");
    return;
  }
  for (int i = 0; i + 25 < n; i++) {
    msk = 0;
    int cnt = 0;
    for (int j = i, x = 0; x < 26; ++x, j++) {
      if (s[j] != '?')
        msk |= (1 << (s[j] - 'A'));
      else
        cnt++;
    }
    if (cnt == 26 - __builtin_popcount(msk)) {
      vector<int> V;
      for (int j = 0; j < 26; j++) {
        if (msk & (1 << j)) continue;
        V.push_back(char('A' + j));
      }
      for (int j = i, x = 0, z = 0; x < 26; ++x, j++) {
        if (s[j] != '?')
          continue;
        else
          s[j] = V[z++];
      }
      f = 1;
      break;
    }
  }
  for (int i = 0; i < n; i++)
    if (s[i] == '?') s[i] = 'A';
  if (f)
    cout << s << "\n";
  else
    cout << "-1\n";
}
int main() { solve(); }
