#include <bits/stdc++.h>
using namespace std;
string t, s = "";
int n;
int main() {
  cin >> n;
  cin >> t;
  int d = 1, k = 0;
  while (t.length() - d <= n) {
    s = s + t[k];
    k += d;
    d++;
  }
  cout << s;
  return 0;
}
