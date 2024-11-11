#include <bits/stdc++.h>
using namespace std;
int main() {
  string S, T;
  cin >> S >> T;
  bool res = false;
  for (int i = 0; i < S.size(); i++) {
    if (S == T) res = true;
    S = S[S.size() - 1] + S.substr(1, S.size() - 1);
  }
  cout << (res ? "Yes" : "No");
}
