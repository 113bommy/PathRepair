#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int l = S.length();
  for (int i = (1); i < (l - 1); ++i) {
    if (S[i] == S[i + 1] && S[i] == S[i - 1])
      S[i] = (S[i] == 'z') ? S[i] - 1 : S[i] + 1;
  }
  for (int i = (1); i < (l); ++i) {
    if (S[i] == S[i - 1]) {
      char c = 'a';
      while (c == S[i] || c == S[i - 1]) c++;
      S[i] = c;
    }
  }
  cout << S << endl;
  return 0;
}
