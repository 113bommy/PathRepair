#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int L = S.size();
  string res = "AC";
  if (S[0] != 'A') res = "WA";
  int cnt = 0;
  for (int i = 1; i < L; ++i) {
    if (isupper(S[i])) {
      if (i > 1 || i < L - 1 || S[i] != 'C') res = "WA";
      cnt++;
    }
  }
  if (cnt != 1) res = "WA";
  cout << res << endl;
}
