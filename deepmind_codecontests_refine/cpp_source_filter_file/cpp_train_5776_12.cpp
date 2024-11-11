#include <bits/stdc++.h>
using namespace std;
int S[500009];
int ans[500009];
bool vowel(char p) {
  if (p == 'I') return true;
  if (p == 'E') return true;
  if (p == 'A') return true;
  if (p == 'O') return true;
  if (p == 'Y') return true;
  if (p == 'U') return true;
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int N = (int)s.length();
  for (int i = 1; i <= N; i++) {
    if (vowel(s[i - 1]))
      S[i] = 1;
    else
      S[i] = 0;
    S[i] += S[i - 1];
  }
  ans[1] = S[N];
  double ret = ans[1];
  for (int len = 2; len <= N; len++) {
    ans[len] = (ans[len - 1] - S[len - 1] + S[N - len + 1]);
    ret += ans[len] / ((double)len);
  }
  cout << fixed << setprecision(7);
  cout << ret << endl;
  return 0;
}
