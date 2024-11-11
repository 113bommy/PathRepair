#include <bits/stdc++.h>
const int MAXN = 2e5 + 15;
using namespace std;
bool cool[101][26], cooler[101][26];
void solve() {
  string s1, s2;
  cin >> s1 >> s2;
  int n = s1.length(), m = s2.length();
  if (m > n) {
    cout << "need tree";
    return;
  }
  std::vector<int> fs1(26, 0), fs2(26, 0);
  for (int i = 0; i < n; i++) fs1[(int)(s1[i] - 'a')]++;
  for (int i = 0; i < m; i++) fs2[(int)(s2[i] - 'a')]++;
  for (int i = 0; i < 26; i++) {
    if (fs1[i] < fs2[i]) {
      cout << "need tree";
      return;
    }
  }
  int pos = 0, sw = 0;
  for (int i = 0; i < m; i++) {
    sw = 1;
    for (int j = pos; j < n; j++) {
      if (s2[i] == s1[j]) {
        pos = j + 1;
        sw = 0;
        break;
      }
    }
    if (sw) break;
  }
  if (n == m) {
    if (sw) {
      cout << "array";
    }
  } else {
    if (sw)
      cout << "both";
    else
      cout << "automaton";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
    cout << "\n";
  }
  return 0;
}
