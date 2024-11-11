#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;
  A--;
  B--;
  C--;
  D--;
  string S;
  cin >> S;
  bool flag = true;
  for (int i = A; i < max(C, D) - 1; i++) {
    if (S[i] == '#' && S[i + 1] == '#') {
      flag = false;
      break;
    }
  }
  if (flag && C > D) {
    flag = false;
    for (int i = B; i < D - 1; i++) {
      if (S[i - 1] == '.' && S[i] == '.' && S[i + 1] == '.') {
        flag = true;
        break;
      }
    }
  }
  cout << (flag ? "Yes" : "No") << endl;
  return 0;
}
