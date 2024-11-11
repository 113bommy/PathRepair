#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  string ans = "AC";

  if (S.front() != 'A') ans = "WA";

  if (count(S.begin() + 2, S.end() - 1, 'C') != 1) ans = "WA";

  int cnt = 0;
  for (int i = 0; i < S.size(); i++) {
    if(isupper(S.at(i))) cnt++;
  }
  if (cnt != 2) ans = "WA";

  cout << ans << "\n";
}