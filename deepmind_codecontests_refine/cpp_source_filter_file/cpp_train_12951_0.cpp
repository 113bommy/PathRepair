#include <bits/stdc++.h>
using namespace std;
const int MIN = -1e4;
int n, m, k, d[101][101][101][2], lps[101];
string s1, s2, virus;
int dp(int i, int j, int KMP, int state) {
  if (KMP > k) return MIN;
  if (i > n || j > m) return 0;
  if (d[i][j][KMP][state] != -1) return d[i][j][KMP][state];
  int f = dp(i + 1, j, KMP, state), s = dp(i, j + 1, KMP, state);
  if (s1[i] == s2[j]) {
    int f1 = MIN;
    if (state == 1) {
      if (s1[i] == virus[KMP])
        f1 = dp(i + 1, j + 1, KMP + 1, 0);
      else if (KMP == 1)
        f1 = dp(i + 1, j + 1, 1, 0) + 1;
      else
        f1 = dp(i, j, lps[KMP - 1] + 1, 1);
      return d[i][j][KMP][state] = f1;
    }
    if (s1[i] == virus[KMP])
      f1 = dp(i + 1, j + 1, KMP + 1, 0) + 1;
    else if (KMP == 1)
      f1 = dp(i + 1, j + 1, 1, 0) + 1;
    else
      f1 = dp(i, j, lps[KMP - 1] + 1, 1);
    return d[i][j][KMP][state] = max(f1, max(s, f));
  }
  return d[i][j][KMP][state] = max(f, s);
}
void trace(int i, int j, int KMP, int state) {
  if (i > n || j > m) return;
  int f = dp(i + 1, j, KMP, state), s = dp(i, j + 1, KMP, state);
  if (s1[i] == s2[j]) {
    int f1 = MIN;
    if (state == 1) {
      if (s1[i] == virus[KMP]) {
        cout << s1[i];
        trace(i + 1, j + 1, KMP + 1, 0);
      } else if (KMP == 1) {
        cout << s1[i];
        trace(i + 1, j + 1, 1, 0);
      } else
        trace(i, j, lps[KMP - 1] + 1, 1);
      return;
    }
    if (s1[i] == virus[KMP])
      f1 = dp(i + 1, j + 1, KMP + 1, 0) + 1;
    else if (KMP == 1)
      f1 = dp(i + 1, j + 1, 1, 0) + 1;
    else
      f1 = dp(i, j, lps[KMP - 1] + 1, 1);
    if (dp(i, j, KMP, state) == f1) {
      if (s1[i] == virus[KMP]) {
        cout << s1[i];
        trace(i + 1, j + 1, KMP + 1, 0);
      } else if (KMP == 1) {
        cout << s1[i];
        trace(i + 1, j + 1, 1, 0);
      } else
        trace(i, j, lps[KMP - 1] + 1, 1);
      return;
    }
    if (dp(i, j, KMP, state) == f)
      trace(i + 1, j, KMP, state);
    else
      trace(i, j + 1, KMP, state);
    return;
  }
  if (dp(i, j, KMP, state) == f)
    trace(i + 1, j, KMP, state);
  else
    trace(i, j + 1, KMP, state);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> s1 >> s2 >> virus;
  memset(d, -1, sizeof d);
  n = s1.size();
  m = s2.size();
  k = virus.size();
  s1 = " " + s1;
  s2 = " " + s2;
  virus = " " + virus;
  lps[0] = 0;
  int len = 1;
  for (int i = 2; i <= k; i++) {
    if (virus[i] == virus[len])
      lps[i] = len++;
    else if (len == 1)
      lps[len] = 0;
    else {
      len = lps[len - 1] + 1;
      i--;
    }
  }
  int ans = dp(1, 1, 1, 0);
  if (ans <= 0) {
    cout << 0;
    return 0;
  }
  trace(1, 1, 1, 0);
  return 0;
}
