#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, acnt = 0, bcnt = 0;
  string s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s[i] == 'A') acnt++;
    if (s[i] == 'D') bcnt++;
  }
  if (acnt > bcnt) cout << "Anton";
  if (bcnt > acnt) cout << "Danik";
  if (acnt = bcnt) cout << "Friendship";
  return 0;
}
