#include <bits/stdc++.h>
using namespace std;
int main() {
  string s[3], f[3] = {"rock", "paper", "scissors"}, w = "FMS";
  int ans[3], anss = 0;
  for (int i = 0; i < 3; i++) {
    cin >> s[i];
    for (int j = 0; j < 3; j++)
      if (s[i] == f[j]) ans[i] = j;
    anss += ans[i];
  }
  if (anss != 1) {
    cout << "?" << endl;
  } else {
    for (int i = 0; i < 3; i++) {
      if (s[i] != s[(i + 1) % 3] && s[i] != s[(i + 2) % 3])
        cout << w[i] << endl;
    }
  }
  return 0;
}
