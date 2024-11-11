#include <bits/stdc++.h>
using namespace std;
string s;
int pref[26][131073];
int F(int l, int r, char ch) {
  if (l == r) {
    if ((char)ch == (char)s[l]) {
      return 0;
    }
    return 1;
  }
  int c = ch - 'a';
  int mid = (l + r) / 2;
  int r1 = pref[c][mid] - pref[c][l - 1];
  int r2 = pref[c][r] - pref[c][mid];
  int N = (r - l + 1) / 2;
  return min(N - r1 + F(mid + 1, r, ch + 1), N - r2 + F(l, mid, ch + 1));
}
int main() {
  int Q;
  cin >> Q;
  while (Q--) {
    int n;
    cin >> n;
    for (int k = 0; k <= 25; k++) {
      for (int i = 0; i < n; i++) pref[k][i] = 0;
    }
    cin >> s;
    for (int k = 0; k < s.size(); k++) {
      int ch = s[k] - 'a';
      pref[ch][k]++;
    }
    for (int k = 0; k <= 25; k++) {
      for (int i = 1; i < n; i++) pref[k][i] += pref[k][i - 1];
    }
    cout << F(0, n - 1, 'a') << endl;
  }
  return 0;
}
