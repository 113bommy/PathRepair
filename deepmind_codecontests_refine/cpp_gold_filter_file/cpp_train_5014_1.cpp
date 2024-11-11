#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int L = 0, R = S.length() - 1;
  string ans = "";
  while (L <= R) {
    if (S[L] == S[R]) {
      ans += S[L++];
      R--;
      continue;
    }
    if (S[L] == S[R - 1]) {
      ans += S[L++];
      R -= 2;
      continue;
    }
    if (S[L + 1] == S[R]) {
      ans += S[L + 1];
      L += 2;
      R--;
      continue;
    }
    if (S[L + 1] == S[R - 1]) {
      ans += S[L + 1];
      R -= 2;
      L += 2;
      continue;
    }
  }
  string tmp = ans;
  tmp.pop_back();
  reverse(tmp.begin(), tmp.end());
  ans += tmp;
  cout << ans << endl;
  return 0;
}
