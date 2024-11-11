#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a[100] = {2,  3,  5,  7,  11, 13, 17, 19,
                          23, 29, 31, 37, 41, 43, 47};
  string ans = "prime";
  long long int i, c = 0;
  string s;
  for (i = 0; i < 15; i++) {
    cout << a[i] << endl;
    fflush(stdout);
    cin >> s;
    if (s == "yes") c++;
    if (a[i] <= 7 && s == "yes") {
      cout << (a[i] * a[i]) << endl;
      fflush(stdout);
      cin >> s;
      if (s == "yes") c++;
    }
    if (c == 2) {
      ans = "composite";
      break;
    }
  }
  cout << ans << endl;
  fflush(stdout);
  return 0;
}
