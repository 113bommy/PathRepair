#include <bits/stdc++.h>
using namespace std;
int n;
int c[100000 + 7][2];
long long dynTab[100000 + 7][2];
string txt[100000 + 7];
bool check(string &a, int t1, string &b, int t2) {
  if (t1) reverse(a.begin(), a.end());
  if (t2) reverse(b.begin(), b.end());
  bool res = a <= b;
  if (t1) reverse(a.begin(), a.end());
  if (t2) reverse(b.begin(), b.end());
  return res;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i][1];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> txt[i];
  }
  dynTab[1][1] = c[1][1];
  for (int i = 2; i <= n; ++i) {
    dynTab[i][0] = dynTab[i][1] = numeric_limits<long long>::max();
    for (int s1 = 0; s1 < 2; ++s1) {
      for (int s2 = 0; s2 < 2; ++s2) {
        if (dynTab[i - 1][s1] != numeric_limits<long long>::max() &&
            check(txt[i - 1], s1, txt[i], s2) == true) {
          dynTab[i][s2] = min(dynTab[i][s2], dynTab[i - 1][s1] + c[i][s2]);
        }
      }
    }
  }
  long long result = min(dynTab[n][0], dynTab[n][1]);
  if (result == numeric_limits<long long>::max()) {
    cout << "-1" << endl;
  } else {
    cout << result << endl;
  }
  return 0;
}
