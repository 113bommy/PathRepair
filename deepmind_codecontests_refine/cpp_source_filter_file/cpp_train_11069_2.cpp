#include <bits/stdc++.h>
using namespace std;
string S, U;
int Res;
int main() {
  cin >> S;
  cin >> U;
  for (int i = 1; i <= U.length(); i++) {
    S = S + '0';
  }
  Res = int(1e9);
  for (int i = 1; i <= S.length(); i++) {
    int Cres = 0;
    for (int j = i - 1; j < i - 1 + U.length(); j++) {
      if (S[j] != U[j - i + 1]) {
        Cres++;
      }
    }
    if (Cres < Res) {
      Res = Cres;
    }
  }
  cout << Res;
  return 0;
}
