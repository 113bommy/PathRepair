#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  int c = count(v.begin(), v.end(), 5);
  int c2 = count(v.begin(), v.end(), 0);
  int i = 0;
  for (i = 0;; i = i + 9) {
    if (c >= i && c < (i + 9)) break;
  }
  string s = "";
  if (c2 >= 1) {
    for (int h = 1; h <= i; h++) s = s + "5";
    if (s != "") {
      for (int h = 1; h <= c2; h++) s = s + "0";
    } else
      s = "0";
    cout << s << endl;
  } else
    cout << -1 << endl;
  return 0;
}
