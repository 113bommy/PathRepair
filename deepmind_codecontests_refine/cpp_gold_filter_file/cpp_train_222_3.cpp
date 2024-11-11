#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  int x = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == '1') x++;
  if (x + x == n) {
    cout << '2' << endl;
    cout << s.substr(0, n - 1) << " " << s[n - 1] << endl;
  } else {
    cout << '1' << endl;
    cout << s << endl;
  }
}
