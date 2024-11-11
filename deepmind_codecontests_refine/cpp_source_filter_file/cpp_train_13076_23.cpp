#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s[n];
  int i, j, co = 0, miro = 0;
  for (i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (i = 0; i < 7; i++) {
    co = 0;
    for (j = 0; j < n; j++) {
      if (s[j][i] == '1') {
        co++;
      }
    }
    if (co > miro) {
      miro = co;
    }
  }
  cout << co << endl;
}
