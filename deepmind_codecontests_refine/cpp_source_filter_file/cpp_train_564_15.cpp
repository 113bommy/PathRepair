#include <bits/stdc++.h>
using namespace std;
int A[1000][1000];
bool lcs(string s1, string s2) {
  int n = s1.length();
  int m = s2.length();
  for (int i = 0; i <= n; i++) A[i][0] = 0;
  for (int i = 0; i <= m; i++) A[0][i] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s1[i - 1] == s2[j - 1])
        A[i][j] = A[i - 1][j - 1] + 1;
      else if (A[i - 1][j] >= A[i][j - 1])
        A[i][j] = A[i - 1][j];
      else
        A[i][j] = A[i][j - 1];
    }
  }
  if (A[n][m] > 0)
    return 1;
  else
    return 0;
}
int main() {
  int S[150] = {0};
  int T[150] = {0};
  string s, t;
  cin >> s >> t;
  int l1 = s.length();
  int l2 = t.length();
  for (int i = 0; i < l1; i++) S[s[i]]++;
  for (int i = 0; i < l2; i++) T[t[i]]++;
  bool tt = true;
  for (int i = 0; i < 140 and tt; i++) {
    if (S[i] < T[i]) tt = false;
  }
  if (!tt) {
    cout << "need tree" << endl;
    return 0;
  }
  if (l1 == l2 and tt) {
    cout << "array" << endl;
    return 0;
  }
  if (lcs(s, t))
    cout << "automaton" << endl;
  else
    cout << "both" << endl;
  return 0;
}
