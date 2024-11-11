#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2, ans, k;
  cin >> s1 >> s2;
  ans = s1[0] + s2[0];
  for (int i = 0; i < s1.size(); i++) {
    for (int j = 0; j < s2.size(); j++) {
      k = "";
      for (int l = 0; l <= i; l++) k += s1[l];
      for (int l = 0; l <= j; l++) k += s2[l];
      if (k < ans) ans = k;
    }
  }
  cout << ans << endl;
  return 0;
}
