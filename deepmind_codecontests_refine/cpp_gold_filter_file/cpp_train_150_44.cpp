#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, j, k;
  cin >> n >> s;
  for (i = 0; i < n; i++) {
    for (j = 1; j <= (n - i) / 3; j++) {
      for (k = 0; k < 5; k++) {
        if (s[i + k * j] != '*') k = 100;
      }
      if (k == 5) {
        cout << "yes";
        return 0;
      }
    }
  }
  cout << "no";
  return 0;
}
