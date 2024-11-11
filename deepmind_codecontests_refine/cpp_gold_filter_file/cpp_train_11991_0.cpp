#include <bits/stdc++.h>
using namespace std;
int L[200000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ((void)0);
  ((void)0);
  ((void)0);
  string S, T;
  int c = 0, ans = 0;
  cin >> S >> T;
  for (int i = 0; i < S.size(); i++) {
    if (c == T.size())
      L[i] = c;
    else
      L[i] = c += S[i] == T[c];
    if (L[i] == T.size()) ans = max(ans, (int)S.size() - 1 - i);
  }
  c = T.size();
  for (int i = S.size() - 1; i >= 0; i--) {
    int s = 0, e = S.size() - 1;
    c -= S[i] == T[c - 1];
    if (c == 0) {
      ans = max(ans, i);
      break;
    }
    while (s <= e) {
      int m = (s + e) >> 1;
      if (L[m] >= c)
        e = m - 1;
      else
        s = m + 1;
    }
    if (L[s] >= c) ans = max(ans, i - s - 1);
  }
  cout << ans << '\n';
  return 0;
}
